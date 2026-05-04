Cup_Size = ['500ml', '250ml']
Coffe_type = ['Espresso', ' Latte', 'Cappuccino']
Milk = ['Sữa tươi (Fresh Milk)', 'Sữa hạnh nhân (Almond milk)', 'Sữa yến mạch (Oat milk)']
Topping = ['Kem tươi (Whipped cream)', 'Caramel', 'Socola (Chocolate)', 'Bột quế (Cinnamon)', 'Đá xay (Ice blended)']

def order():
	print("Chọn kích thước cốc :")
	for i in range(0, len(Cup_Size)):
		print("{i + 1}. {Cup_Size[i]}")
	print("Nhập lựa chọn của bạn :")
	Size = int(input()) 
	while (Size > len(Cup_Size) || Size <= 0):
		print("Nhập lại lựa chọn của bạn :")
		Size = int(input())
	print("Chọn loại cà phê :")
	for i in range(0, len(Coffe_type)):
		print("{i + 1}. {Coffe_type[i]}")
	print("Nhập lựa chọn của bạn :")
	TYPE = int(input())
	while (TYPE > len(Coffe_type) || TYPE <= 0):
		print("Nhập lại lựa chọn của bạn :")
		TYPE = int(input())
	print("Chọn loại sữa cho cà phê :")
	for i in range(0, len(Milk)):
		print("{i + 1}. {Milk[i]}")
	MILK = int(input())
	while (MILK > len(Milk) || MILK <= 0):
		print("Nhập lại lựa chọn của bạn :")
		MILK = int(input())
	print("")


