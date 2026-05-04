# baguette_basic.py
# ------------------------------------
# Version: "no OOP" (only lists, dicts, functions, loops, conditionals)
# A single Order contains many "loaves" (each loaf has: size, bread, filling, salads<=3).
# Daily sales stats are counted per loaf by size, bread, filling.
#
# How to run:
#   python baguette_basic.py
#
# Files:
#   - sales_data.txt : JSON counters (auto-created/updated)

from __future__ import annotations
import json, os

# ===== Options =====
SIZE_OPTIONS    = ["30cm", "15cm"]
BREAD_OPTIONS   = ["white", "brown", "seeded"]
FILLING_OPTIONS = ["beef", "chicken", "cheese", "egg", "tuna", "turkey"]
SALAD_OPTIONS   = ["lettuce", "tomato", "sweetcorn", "cucumber", "peppers"]

# ===== Sales persistence =====
SALES_DATA_FILE = "sales_data.txt"
DEFAULT_SALES = {
    "size":    {k: 0 for k in SIZE_OPTIONS},
    "bread":   {k: 0 for k in BREAD_OPTIONS},
    "filling": {k: 0 for k in FILLING_OPTIONS},
}

def load_sales():
    if os.path.exists(SALES_DATA_FILE):
        try:
            with open(SALES_DATA_FILE, "r", encoding="utf-8") as f:
                data = json.load(f)
            # ensure keys exist
            for g, d in DEFAULT_SALES.items():
                if g not in data or not isinstance(data[g], dict):
                    data[g] = {}
                for k in d:
                    if k not in data[g] or not isinstance(data[g][k], int):
                        data[g][k] = 0
            return data
        except Exception:
            pass
    # deep copy safe
    return json.loads(json.dumps(DEFAULT_SALES))

def save_sales(sales):
    with open(SALES_DATA_FILE, "w", encoding="utf-8") as f:
        json.dump(sales, f, ensure_ascii=False, indent=2)

# ===== UI helpers =====
def choose_from_list(prompt, options):
    while True:
        print(f"\n{prompt}")
        for i, opt in enumerate(options, start=1):
            print(f"{i}. {opt}")
        raw = input(f"Chọn (1-{len(options)}): ").strip()
        if raw.isdigit():
            idx = int(raw) - 1
            if 0 <= idx < len(options):
                return options[idx]
        print("⛔ Lựa chọn không hợp lệ, thử lại.")

def choose_salads():
    print("\nChọn tối đa 3 loại salad (nhập số, cách nhau bởi dấu phẩy).")
    for i, s in enumerate(SALAD_OPTIONS, start=1):
        print(f"{i}. {s}")
    print("Bỏ trống hoặc nhập 0 nếu không chọn.")
    while True:
        raw = input("Ví dụ: 1,3 hoặc 2,4,5: ").strip()
        if raw == "" or raw == "0":
            return []
        try:
            parts = [p.strip() for p in raw.split(",") if p.strip()]
            idxs = []
            for p in parts:
                if not p.isdigit():
                    raise ValueError
                v = int(p)
                if not (1 <= v <= len(SALAD_OPTIONS)):
                    raise ValueError
                if v not in idxs:
                    idxs.append(v)
            if len(idxs) > 3:
                print("⛔ Tối đa 3 loại salad. Hãy chọn lại.")
                continue
            return [SALAD_OPTIONS[i-1] for i in idxs]
        except ValueError:
            print("⛔ Danh sách không hợp lệ. Hãy nhập lại theo mẫu 1,3 hoặc 2,4,5.")

# ===== Build one loaf (dict) =====
def input_one_loaf():
    size = choose_from_list("Chọn kích thước bánh mì:", SIZE_OPTIONS)
    bread = choose_from_list("Chọn loại bánh mì:", BREAD_OPTIONS)
    filling = choose_from_list("Chọn nhân bánh mì:", FILLING_OPTIONS)
    salads = choose_salads()
    loaf = {
        "size": size,
        "bread": bread,
        "filling": filling,
        "salads": salads,   # list length 0..3
    }
    print("\n✅ Ổ bánh đã chọn:")
    print(f"   - size:    {size}")
    print(f"   - bread:   {bread}")
    print(f"   - filling: {filling}")
    print(f"   - salads:  {', '.join(salads) if salads else '(none)'}")
    return loaf

# ===== Sales counting =====
def record_loaf_to_sales(loaf, sales):
    sales["size"][loaf["size"]] += 1
    sales["bread"][loaf["bread"]] += 1
    sales["filling"][loaf["filling"]] += 1

def analyze_fillings(sales):
    total = sum(sales["filling"].values())
    print("\n===== PHÂN TÍCH NHÂN =====")
    print(f"Tổng số baguette đã bán: {total}")
    if total == 0:
        print("Chưa có dữ liệu.")
        return
    # compute percentages
    perc = {}
    for k, v in sales["filling"].items():
        perc[k] = (v / total) * 100 if total else 0.0
    # find most/least
    most = max(perc, key=perc.get)
    least = min(perc, key=perc.get)
    for k in FILLING_OPTIONS:
        print(f"- {k:<8}: {sales['filling'][k]:>3} chiếc  ({perc[k]:6.2f}%)")
    print(f"\n🥇 Phổ biến nhất: {most} ({perc[most]:.2f}%)")
    print(f"🥉 Ít phổ biến nhất: {least} ({perc[least]:.2f}%)")

# ===== Print order =====
def print_order(order_id, loaves):
    print("\n===== CHI TIẾT ĐƠN HÀNG =====")
    print(f"Mã đơn hàng: {order_id}")
    for i, loaf in enumerate(loaves, start=1):
        salads_str = ", ".join(loaf["salads"]) if loaf["salads"] else "(none)"
        print(f"  Ổ #{i}: size={loaf['size']}, bread={loaf['bread']}, filling={loaf['filling']}, salads=[{salads_str}]")

# ===== Main loop =====
def main():
    sales = load_sales()
    next_order_id = 1  # simple counter in memory

    print("=== DỊCH VỤ ĐẶT BAGUETTE (NO-OOP) ===")
    while True:
        print("\nBắt đầu tạo đơn hàng mới...")
        loaves = []  # list of loaf dicts in this order

        # build order with 1..n loaves
        while True:
            loaf = input_one_loaf()
            loaves.append(loaf)


            # prompt action
            while True:
                action = input("\nChọn hành động: [a] thêm ổ  |  [c] xác nhận đơn  |  [x] huỷ đơn  > ").strip().lower()
                if action in ("a", "c", "x"):
                    break
                print("⛔ Vui lòng chọn a / c / x.")
            if action == "a":
                continue
            elif action == "x":
                print("❌ Đơn hàng đã huỷ.")
                loaves.clear()
                break
            else:  # confirm
                if not loaves:
                    print("⛔ Đơn rỗng, không thể xác nhận.")
                    continue
                # record stats per loaf
                for lf in loaves:
                    record_loaf_to_sales(lf, sales)
                save_sales(sales)
                print_order(next_order_id, loaves)
                print("✅ Đơn hàng đã được xác nhận.")
                next_order_id += 1
                break

        cont = input("\nTiếp tục tạo đơn hàng mới? (y/n): ").strip().lower()
        if cont != "y":
            break

    print("\n===== SỐ LIỆU CUỐI NGÀY =====")
    print(json.dumps(sales, ensure_ascii=False, indent=2))
    analyze_fillings(sales)

if __name__ == "__main__":
    main()
