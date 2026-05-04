n = int(input())
arr = []
for i in range(n):
    x = input()
    arr.append(x)
pos_max = arr.index(max(arr))
pos_min = arr.index(min(arr))
arr[pos_max], arr[pos_min] = arr[pos_min], arr[pos_max]
print(arr)
