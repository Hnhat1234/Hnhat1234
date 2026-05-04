import os
# Ép chạy hoàn toàn trên CPU và tắt log CUDA
os.environ["CUDA_VISIBLE_DEVICES"] = "-1"
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

import numpy as np
import pandas as pd
import tensorflow as tf
from tensorflow.keras import layers, models, optimizers, callbacks
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import joblib

# 1. Load và chuẩn bị dữ liệu
df = pd.read_csv("wifi_anomaly_synthetic_data.csv")
X = df.drop(columns=['label']).values
y = df['label'].values

X_normal = X[y == 0]

# Chỉ fit Scaler trên dữ liệu bình thường
scaler = StandardScaler()
X_normal_scaled = scaler.fit_transform(X_normal)

# Tách tập Train và Validation
X_train, X_val = train_test_split(X_normal_scaled, test_size=0.2, random_state=42)

# 2. Xây dựng Model Autoencoder (6-16-8-16-6)
def build_autoencoder(input_dim=6):
    model = models.Sequential([
        # Encoder
        layers.Dense(16, activation='relu', input_shape=(input_dim,)),
        layers.Dense(8, activation='relu'), # Bottleneck
        # Decoder
        layers.Dense(16, activation='relu'),
        layers.Dense(input_dim, activation='linear')
    ])
    return model

autoencoder = build_autoencoder()
autoencoder.compile(optimizer=optimizers.Adam(learning_rate=0.001), loss='mse')

# 3. Huấn luyện với EarlyStopping
early_stop = callbacks.EarlyStopping(monitor='val_loss', patience=15, restore_best_weights=True)

print("Đang huấn luyện mô hình trên CPU...")
autoencoder.fit(
    X_train, X_train,
    epochs=100,
    batch_size=32,
    validation_data=(X_val, X_val),
    callbacks=[early_stop],
    verbose=1
)

# 4. Tính toán Threshold
def get_mse(model, data):
    preds = model.predict(data, verbose=0)
    return np.mean(np.square(data - preds), axis=1)

val_errors = get_mse(autoencoder, X_val)

# Ngưỡng thống kê: Mean + 2*Std
optimal_threshold = np.mean(val_errors) + 2 * np.std(val_errors)

print(f"\n" + "="*30)
print(f"Ngưỡng threshold tối ưu (Mean+2Std): {optimal_threshold:.6f}")
print("="*30)

# 5. Lưu Model và Scaler
# Lưu bản .keras để test và .tflite để nạp ESP32
autoencoder.save("wifi_autoencoder.keras")
joblib.dump(scaler, "wifi_scaler.pkl")

# Xuất TFLite Micro
converter = tf.lite.TFLiteConverter.from_keras_model(autoencoder)
tflite_model = converter.convert()
with open("wifi_anomaly_model.tflite", "wb") as f:
    f.write(tflite_model)

# Lưu threshold vào file text để script test có thể đọc
with open("threshold_config.txt", "w") as f:
    f.write(str(optimal_threshold))

print("Đã lưu các file: wifi_autoencoder.keras, wifi_scaler.pkl, wifi_anomaly_model.tflite, threshold_config.txt")
