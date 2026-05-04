n = 0
while (1):
	try:
		n = int(input("n = "))
	except:
		print("Please Try Again")
		n = 0
	if (n > 0):
		break
S1 = 0
S2 = 0
S3 = 0
S4 = 1/2

count = 1
while (n > 0):
	S1 += 1 / (count * (count + 1) / 2)
	S2 += 1 / (count * (count + 1))
	S3 += count / (count + 1)
	S4 += (2 * count + 1) / (2 * count + 2)
	n -= 1
	count += 1


print("S(n) = 1 + 1 / (1 + 2) + ... + 1 / (1 + ... + n) = ", S1)
print("S(n) = 1 / (1 x 2) + 1 / (2 x 3) + ... + 1 / (n x (n + 1)) = ", S2)
print("S(n) = 1 / 2 + 2 / 3 + ... + n / (n + 1) = ", S3)
print("S(n) = 1 / 2 + 3 / 4 + ... + (2n + 1) / (2n + 2) = ", S4)
