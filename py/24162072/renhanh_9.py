def check(s):
    try:
        float(s)
        return True
    except ValueError:
        return False
x = 0

while (1):
    x = input("x = ")
    if (check(x)):
        x = float(x)
        break
    print("The value must be a real number") 
if (x > 0):
	print(f"f(x) = {x * x + 3 * x + 5}")
else:
	print(f"f(x) = {-x * x - 3 * x - 5}")


