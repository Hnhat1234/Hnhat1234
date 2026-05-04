import os
# Ép chạy hoàn toàn trên CPU
os.environ['CUDA_VISIBLE_DEVICES'] = '-1'
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

import numpy as np
import pandas as pd
import tensorflow as tf
from tensorflow.keras import layers, models, optimizers, callbacks
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import RobustScaler # Thay đổi ở đây
from sklearn.metrics import roc_curve, auc
import joblib

# --- BƯỚC 1: KHÓA SEED (CHỐNG LỆCH KẾT QUẢ) ---
SEED = 42
np.random.seed(SEED)
tf.random.set_seed(SEED)

# --- BƯỚC 2: LOAD & TIỀN XỬ LÝ ---
df = pd.read_csv("wifi_anomaly_synthetic_data.csv")
X = df.drop(columns=['label']).values
y = df['label'].values

X_normal = X[y == 0]
X_anomaly = X[y == 1]

# Sử dụng RobustScaler để chống nhiễu
scaler = RobustScaler()
X_normal_scaled = scaler.fit_transform(X_normal)
X_anomaly_scaled = scaler.transform(X_anomaly)

# Chia tập Train/Val
X_train, X_val = train_test_split(X_normal_scaled, test_size=0.2, random_state=SEED)

# --- BƯỚC 3: KIẾN TRÚC MÔ HÌNH ---
# Thêm lớp Dropout nhỏ để chống Overfitting (tăng tính ổn định)
autoencoder = models.Sequential([
    layers.Input(shape=(6,)),
    layers.Dense(16, activation='relu'),
    layers.Dropout(0.1), 
    layers.Dense(8, activation='relu'), # Bottleneck
    layers.Dense(16, activation='relu'),
    layers.Dense(6, activation='linear')
])

autoencoder.compile(optimizer=optimizers.Adam(learning_rate=0.001), loss='mse')

# --- BƯỚC 4: HUẤN LUYỆN ---
early_stop = callbacks.EarlyStopping(monitor='val_loss', patience=15, restore_best_weights=True)

print("Đang train mô hình với chiến thuật ổn định hóa...")
autoencoder.fit(
    X_train, X_train,
    epochs=150, # Tăng epoch để model hội tụ sâu hơn
    batch_size=32,
    validation_data=(X_val, X_val),
    callbacks=[early_stop],
    verbose=0
)

# --- BƯỚC 5: TÍNH NGƯỠNG THEO LOGIC NOTEBOOK (YOUDEN) ---
def get_mse(data):
    preds = autoencoder.predict(data, verbose=0)
    return np.mean(np.square(data - preds), axis=1)

val_errors = get_mse(X_val)
anomaly_errors = get_mse(X_anomaly_scaled)

y_true_roc = np.concatenate([np.zeros(len(val_errors)), np.ones(len(anomaly_errors))])
y_scores_roc = np.concatenate([val_errors, anomaly_errors])

fpr, tpr, thresholds = roc_curve(y_true_roc, y_scores_roc)
optimal_idx = np.argmax(tpr - fpr)
optimal_threshold = thresholds[optimal_idx]

print(f"\n[KẾT QUẢ]")
print(f"Ngưỡng tối ưu ổn định: {optimal_threshold:.6f}")
print(f"Chỉ số AUC: {auc(fpr, tpr):.4f}")

# Lưu lại các tham số chuẩn
joblib.dump(scaler, "wifi_scaler.pkl")
autoencoder.save("wifi_autoencoder.keras")
