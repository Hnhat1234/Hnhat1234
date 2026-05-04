import os
# Ép chạy hoàn toàn trên CPU
os.environ["CUDA_VISIBLE_DEVICES"] = "-1"
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

import pandas as pd
import numpy as np
import tensorflow as tf
from tensorflow import keras
import joblib
from sklearn.metrics import accuracy_score, recall_score, precision_score, f1_score

# 1. Cấu hình đường dẫn
KERAS_MODEL_PATH = "wifi_autoencoder.keras"
TFLITE_MODEL_PATH = "wifi_anomaly_model.tflite"
SCALER_PATH = "wifi_scaler.pkl"
DATA_PATH = "wifi_anomaly_synthetic_data.csv"
THRESHOLD_PATH = "threshold_config.txt"

# 2. Load dữ liệu và các thành phần
scaler = joblib.load(SCALER_PATH)
df = pd.read_csv(DATA_PATH)
with open(THRESHOLD_PATH, "r") as f:
    threshold = float(f.read())

X = df.drop(columns=['label']).values
y_true = df['label'].values
X_scaled = scaler.transform(X).astype(np.float32)

# --- PHẦN 1: DỰ ĐOÁN BẰNG KERAS ---
print("Đang chạy dự đoán bằng Keras...")
keras_model = keras.models.load_model(KERAS_MODEL_PATH)
keras_reconstructions = keras_model.predict(X_scaled, verbose=0)
keras_mse = np.mean(np.square(X_scaled - keras_reconstructions), axis=1)
keras_pred = (keras_mse > threshold).astype(int)

# --- PHẦN 2: DỰ ĐOÁN BẰNG TFLITE ---
print("Đang chạy dự đoán bằng TFLite...")
interpreter = tf.lite.Interpreter(model_path=TFLITE_MODEL_PATH)
interpreter.allocate_tensors()

input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

tflite_mse = []
for i in range(len(X_scaled)):
    # Đưa dữ liệu vào TFLite Interpreter
    input_data = np.expand_dims(X_scaled[i], axis=0)
    interpreter.set_tensor(input_details[0]['index'], input_data)
    interpreter.invoke()
    
    # Lấy kết quả tái tạo
    output_data = interpreter.get_tensor(output_details[0]['index'])
    mse = np.mean(np.square(X_scaled[i] - output_data))
    tflite_mse.append(mse)

tflite_mse = np.array(tflite_mse)
tflite_pred = (tflite_mse > threshold).astype(int)

# --- PHẦN 3: SO SÁNH VÀ IN BÁO CÁO ---
def get_metrics(y_true, y_pred):
    return {
        "Accuracy": accuracy_score(y_true, y_pred),
        "Precision": precision_score(y_true, y_pred),
        "Recall": recall_score(y_true, y_pred),
        "F1-Score": f1_score(y_true, y_pred)
    }

keras_m = get_metrics(y_true, keras_pred)
tflite_m = get_metrics(y_true, tflite_pred)

# Tính độ lệch MSE trung bình giữa 2 mô hình (MSE Drift)
# Con số này càng nhỏ chứng tỏ việc chuyển đổi sang TFLite càng hoàn hảo
mse_drift = np.mean(np.abs(keras_mse - tflite_mse))

print("\n" + "="*50)
print(f"{'CHỈ SỐ':<15} | {'KERAS MODEL':<15} | {'TFLITE MODEL':<15}")
print("-" * 50)
for metric in keras_m.keys():
    print(f"{metric:<15} | {keras_m[metric]:<15.4f} | {tflite_m[metric]:<15.4f}")
print("="*50)

print(f"\nĐộ lệch sai số trung bình (MSE Drift): {mse_drift:.8f}")
if mse_drift < 1e-5:
    print("=> Đánh giá: Chuyển đổi TFLite cực kỳ ổn định.")
else:
    print("=> Đánh giá: Có sự sai lệch nhỏ do quá trình nén mô hình.")

# Lưu kết quả so sánh vào CSV để làm báo cáo
comparison_df = pd.DataFrame({
    'True_Label': y_true,
    'Keras_MSE': keras_mse,
    'TFLite_MSE': tflite_mse,
    'Keras_Pred': keras_pred,
    'TFLite_Pred': tflite_pred
})
comparison_df.to_csv("model_comparison_report.csv", index=False)
print("\nĐã lưu báo cáo đối chiếu vào file 'model_comparison_report.csv'")