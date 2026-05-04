import math

year = 0

while (1):
    try:
        year = int(input("Year = "))
    except:
        print("Please Try Again (A valid Year)")
        year = 0
    if (year > 0):
        break

day_of_the_week = (year + math.floor((year - 1) / 4)
                   - math.floor((year - 1) / 100)
                   + math.floor((year - 1) / 400)) % 7

days = ["Chủ nhật", "Thứ Hai", "Thứ Ba", "Thứ Tư", "Thứ Năm", "Thứ Sáu", "Thứ Bảy"]

print(f"Ngày 1 tháng 1 năm {year} là {days[day_of_the_week]}.")
