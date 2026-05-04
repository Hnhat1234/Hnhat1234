import pandas as pd
import matplotlib.pyplot as plt

# Đọc dữ liệu từ file CSV
df = pd.read_csv("IMDB_data.csv")

# ===================== a. Hiển thị 5 dòng đầu tiên =====================
print("=== 5 dòng đầu tiên ===")
print(df.head(5))

# ===================== b. Hiển thị thông tin các cột =====================
print("\n=== Các cột Title, Genre, Actors, Directors, Rating ===")
print(df[['Title', 'Genre', 'Actors', 'Directors', 'Rating']])

# ===================== c. Kiểm tra số lượng giá trị null =====================
print("\n=== Số lượng giá trị null trong từng cột ===")
print(df.isnull().sum())

# ===================== d. Thay thế giá trị null trong Revenue bằng trung bình =====================
mean_revenue = df['Revenue'].mean()
df['Revenue'].fillna(mean_revenue, inplace=True)
print("\n=== Sau khi thay thế giá trị null trong Revenue ===")
print(df['Revenue'].isnull().sum())  # Kiểm tra lại

# ===================== e. Lấy phim 2010-2015, rating < 6.0, doanh thu cao nhất =====================
subset = df[(df['Year'] >= 2010) & (df['Year'] <= 2015) & (df['Rating'] < 6.0)]
if not subset.empty:
    top_revenue_movie = subset.loc[subset['Revenue'].idxmax()]
    print("\n=== Phim từ 2010-2015, rating <6.0 nhưng có doanh thu đứng đầu ===")
    print(top_revenue_movie)
else:
    print("\nKhông có phim thỏa mãn điều kiện 2010-2015 và rating < 6.0")

# ===================== f. Tạo cột phân loại Rating_Labels =====================
def rating_label(r):
    if r >= 7.5:
        return 'Good'
    elif r >= 6:
        return 'Average'
    else:
        return 'Bad'

df['Rating_Labels'] = df['Rating'].apply(rating_label)
print("\n=== Thêm cột Rating_Labels ===")
print(df[['Title', 'Rating', 'Rating_Labels']].head(10))

# ===================== g. Vẽ biểu đồ tròn tổng doanh thu theo năm 2010-2015 =====================
revenue_by_year = df[(df['Year'] >= 2010) & (df['Year'] <= 2015)].groupby('Year')['Revenue'].sum()

plt.figure(figsize=(8,8))
plt.pie(revenue_by_year, labels=revenue_by_year.index, autopct='%1.1f%%', startangle=140)
plt.title("Tổng doanh thu theo năm (2010-2015)")
plt.show()
