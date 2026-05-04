import math

def check(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

print("Program for solving ax^2 + bx + c = 0")

a, b, c = 0, 0, 0

while (1):
    a = input("a = ")
    if (check(a)):
        a = float(a)
        break
    print("The value must be a real number") 

while (1):
    b = input("b = ")
    if (check(b)):
        b = float(b)
        break
    print("The value must be a real number") 

while (1):
    c = input("c = ")
    if (check(c)):
        c = float(c)
        break
    print("The value must be a real number") 
delta = (b * b - 4 * a * c)
if (a == 0):
	if (b == 0 and c != 0):
		print(f"The equation {a}x^2 + {b}x + {c} = 0 have no root")
	if (b == 0 and c == 0):
		print(f"The equation {a}x^2 + {b}x + {c} = 0 have inf root")
	if (b != 0):
		print(f"The equation {a}x^2 + {b}x + {c} = 0 have 1 root: x = {-c/b}")
else:
	if (delta < 0):
		print(f"The equation {a}x^2 + {b}x + {c} = 0 have no root")
	elif (delta == 0):
		print(f"The equation {a}x^2 + {b}x + {c} = 0 have 1 root: x = {-b / (2 * a)}")
	else:
		x1 = (-b + math.sqrt(delta)) / (2 * a)
		x2 = (-b - math.sqrt(delta)) / (2 * a)
		print(f"The equation {a}x^2 + {b}x + {c} = 0 have 2 root: x = {x1} and x = {x2}")
