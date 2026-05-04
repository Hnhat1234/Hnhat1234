import pywifi
import time
import numpy as np
import math
import csv
import os

# ===== CONFIG =====
OUTPUT_PATH = "data/01_raw/wifi_features_simple.csv"
SCAN_TIME = 5        # thời gian mỗi lần scan
NUM_SAMPLES = 50     # số sample cần thu
DELAY_BETWEEN = 2    # nghỉ giữa các lần scan
LABEL = 0            # 0 = normal

# ===== INIT WIFI =====
wifi = pywifi.PyWiFi()
iface = wifi.interfaces()[1]

# ===== HELPER =====
def shannon_entropy(ssid):
    if not ssid:
        return 0
    prob = [float(ssid.count(c)) / len(ssid) for c in set(ssid)]
    return -sum([p * math.log2(p) for p in prob])

# ===== CSV SETUP =====
os.makedirs(os.path.dirname(OUTPUT_PATH), exist_ok=True)
file_exists = os.path.isfile(OUTPUT_PATH)

with open(OUTPUT_PATH, "a", newline="") as f:
    writer = csv.writer(f)

    # header
    if not file_exists:
        writer.writerow([
            "traffic_mean",
            "traffic_std",
            "packet_rate",
            "packet_variance",
            "active_hosts",
            "traffic_entropy",
            "label"
        ])

    # ===== LOOP =====
    for i in range(NUM_SAMPLES):
        print(f"\n[+] Scan {i+1}/{NUM_SAMPLES}...")

        iface.scan()
        time.sleep(SCAN_TIME)
        results = iface.scan_results()

        rssi_list = []
        entropy_list = []

        for net in results:
            rssi_list.append(net.signal)
            entropy_list.append(shannon_entropy(net.ssid))

        # skip nếu không có data
        if len(rssi_list) == 0:
            print("[-] No networks found, skip")
            continue

        # ===== FEATURES =====
        traffic_mean = np.mean(rssi_list)
        traffic_std = np.std(rssi_list)
        packet_variance = np.var(rssi_list)
        active_hosts = len(rssi_list)
        packet_rate = active_hosts / SCAN_TIME
        traffic_entropy = np.mean(entropy_list)

        row = [
            traffic_mean,
            traffic_std,
            packet_rate,
            packet_variance,
            active_hosts,
            traffic_entropy,
            LABEL
        ]

        writer.writerow(row)
        print("[+] Saved:", row)

        time.sleep(DELAY_BETWEEN)

print("\n✅ Done collecting dataset!")