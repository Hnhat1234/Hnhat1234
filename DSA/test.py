# baguette_basic.py
# ------------------------------------
# Version: "no OOP" (only lists, dicts, functions, loops, conditionals)
# Mỗi Order gồm nhiều loaf (size, bread, filling, salads<=3).
#
# Cách chạy:
#   python baguette_basic.py
#
# File:
#   - sales_data.txt : Lưu danh sách loaf đã chọn

from __future__ import annotations
import json, os

# ===== Options =====
SIZE_OPTIONS    = ["30cm", "15cm"]
BREAD_OPTIONS   = ["white", "brown", "seeded"]
FILLING_OPTIONS = ["beef", "chicken", "cheese", "egg", "tuna", "turkey"]
SALAD_OPTIONS   = ["lettuce", "tomato", "sweetcorn", "cucumber", "peppers"]

# ===== File =====
SALES_DATA_FILE = "sales_data.json"

def save_list_chosen(list_chosen):
    with open(SALES_DATA_FILE, "w", encoding="utf-8") as f:
        json.dump(list_chosen, f, ensure_ascii=False, indent=2)

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
        "salads": salads,
    }
    print("\n✅ Ổ bánh đã chọn:")
    print(f"   - size:    {size}")
    print(f"   - bread:   {bread}")
    print(f"   - filling: {filling}")
    print(f"   - salads:  {', '.join(salads) if salads else '(none)'}")
    return loaf

# ===== In ra đơn hàng =====
def print_order(order_id, list_chosen):
    print("\n===== CHI TIẾT ĐƠN HÀNG =====")
    print(f"Mã đơn hàng: {order_id}")
    for i, loaf in enumerate(list_chosen, start=1):
        salads_str = ", ".join(loaf["salads"]) if loaf["salads"] else "(none)"
        print(f"  Ổ #{i}: size={loaf['size']}, bread={loaf['bread']}, "
              f"filling={loaf['filling']}, salads=[{salads_str}]")

# ===== Main loop =====
def main():
    next_order_id = 1

    print("=== DỊCH VỤ ĐẶT BAGUETTE (NO-OOP) ===")
    while True:
        print("\nBắt đầu tạo đơn hàng mới...")
        list_chosen = []  # list chứa các loaf dict

        while True:
            loaf = input_one_loaf()
            list_chosen.append(loaf)

            # hỏi hành động
            while True:
                action = input("\nChọn hành động: [a] thêm ổ  |  [c] xác nhận đơn  |  [x] huỷ đơn  > ").strip().lower()
                if action in ("a", "c", "x"):
                    break
                print("⛔ Vui lòng chọn a / c / x.")

            if action == "a":
                continue
            elif action == "x":
                print("❌ Đơn hàng đã huỷ.")
                list_chosen.clear()
                break
            else:  # confirm
                if not list_chosen:
                    print("⛔ Đơn rỗng, không thể xác nhận.")
                    continue

                # in đơn hàng
                print_order(next_order_id, list_chosen)
                # lưu toàn bộ list_chosen vào sales_data.txt
                save_list_chosen(list_chosen)

                print("✅ Đơn hàng đã được xác nhận và lưu vào sales_data.txt")
                next_order_id += 1
                break

        cont = input("\nTiếp tục tạo đơn hàng mới? (y/n): ").strip().lower()
        if cont != "y":
            break

if __name__ == "__main__":
    main()
