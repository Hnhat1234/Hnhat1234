import random
import math

def khoitao():
    n = 0
    while 1:
        try:
            n = int(input("n = "))
        except:
            n = 0
        if (n > 0):
            break
        print("Please Try Again, input must be an positive integer")
    a = []
    for i in range(n):
        x = 0.5
        while 1:
            try:
                x = int(input(f"a{i} = "))
            except:
                x = 0.5
            if (x != 0.5):
                a.append(x)
                break
            else:
                print("Please Try Again")
    return a
def tongsohoanhao(a: list[int]):
    res = 0
    for i in range(len(a)):
        s = 0
        for j in range(1, int(math.sqrt(math.fabs(a[i])) + 1) + 1):
            if (a[i] % j == 0):
                s += j
        if (a[i] == s):
            res += a[i]
    return res
def tong1va5(a: list[int]):
    res = sum([a[i] for i in range(len(a)) if ((a[i] / 10) % 10 == 1 or (a[i] / 10) % 10 == 5)])
    return res
def main():
    a = khoitao()
    print("Tong cac so hoan hao = ",tongsohoanhao(a))
    print("Tong cac so hang chuc la 1 va 5 = ",tong1va5(a))
    am = [a[i] for i in range(len(a)) if a[i] < 0]
    duong = [a[i] for i in range(len(a)) if a[i] > 0]
    am.sort(reverse = True)
    duong.sort()
    for i in range(len(a)):
        if (a[i] < 0):
            a[i] = am.pop()
        elif (a[i] > 0):
            a[i] = duong.pop()
    print(a)
main()



