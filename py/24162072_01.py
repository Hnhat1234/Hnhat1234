class PhongHoc:
    def __init__(self, maphong, daynha, dientich, bongden):
        self.maphong = maphong
        self.daynha = daynha
        self.dientich = dientich
        self.bongden = bongden

    def datchuan(self):
        return self.dientich / self.bongden <= 10.0


class PhongLyThuyet(PhongHoc):
    def __init__(self, maphong, daynha, dientich, bongden, maychieu):
        super().__init__(maphong, daynha, dientich, bongden)
        self.maychieu = maychieu

    def datchuan(self):
        return super().datchuan() and self.maychieu == 1


class PhongMayTinh(PhongHoc):
    def __init__(self, maphong, daynha, dientich, bongden, maytinh):
        super().__init__(maphong, daynha, dientich, bongden)
        self.maytinh = maytinh

    def datchuan(self):
        return super().datchuan() and (self.dientich / self.maytinh <= 1.5)


class QLDS:
    def __init__(self, List):
        self.List = List

    def danhsachdatchuan(self):
        res = []
        for i in range(len(self.List)):
            if self.List[i].datchuan():
                res.append(self.List[i].maphong)  
        return res

    def themphong(self, other):
        for i in range(len(self.List)):
            if self.List[i].maphong == other.maphong:
                return "Khong the them trung ma phong"
        self.List.append(other)
        return "Them phong thanh cong"

    def xoaphong(self, ma):
        for i in range(len(self.List)):
            if self.List[i].maphong == ma:
                del self.List[i]
                return "Xoa thanh cong"
        return "Xoa khong thanh cong do khong thay ma phong"

    def tongtungloai(self):
        a, b = 0, 0
        for i in range(len(self.List)):
            if isinstance(self.List[i], PhongLyThuyet):
                a += 1
            if isinstance(self.List[i], PhongMayTinh):
                b += 1
        return (a, b)

    def sophongmaytinhco60(self):
        res = []
        for i in range(len(self.List)):
            if isinstance(self.List[i], PhongMayTinh) and self.List[i].maytinh == 60:
                res.append(self.List[i].maphong)
        return res


def main():
    a = QLDS([])
    while True:
        print("Quan ly danh sach phong hoc")
        print("1. Them phong")
        print("2. Xoa phong")
        print("3. Tong tung loai phong")
        print("4. So phong may tinh co 60 may")
        print("5. Danh sach phong dat chuan")

        try:
            choice = int(input("Chon loai thao tac:"))
        except ValueError:
            print("Vui long nhap so nguyen")
            continue

        if choice == 1:
            while True:
                try:
                    type = int(input("Loai phong = 1. Ly thuyet 2. May tinh:"))
                    if type < 1 or type > 2:
                        print("Loai phong khong hop le")
                        continue
                    break
                except ValueError:
                    print("Vui long nhap 1 hoac 2")
                    continue

            maso = input("Ma so:")
            daynha = input("Day nha:")

     
            while True:
                try:
                    dientich = int(input("Dien tich:"))
                    if dientich <= 0:
                        print("Dien tich phai > 0")
                        continue
                    break
                except ValueError:
                    print("Vui long nhap so nguyen")
                    continue

            while True:
                try:
                    bongden = int(input("Bong den:"))
                    if bongden <= 0:
                        print("Bong den phai > 0")
                        continue
                    break
                except ValueError:
                    print("Vui long nhap so nguyen")
                    continue

            if type == 1:  
                while True:
                    try:
                        maychieu = int(input("Co may chieu hay khong - 0. Khong 1. Co:"))
                        if maychieu < 0 or maychieu > 1:
                            print("Nhap 0 hoac 1")
                            continue
                        break
                    except ValueError:
                        print("Vui long nhap 0 hoac 1")
                        continue

                c = PhongLyThuyet(maso, daynha, dientich, bongden, maychieu)

            if type == 2:  
                while True:
                    try:
                        maytinh = int(input("May tinh:"))
                        if maytinh <= 0:
                            print("So may tinh phai > 0")
                            continue
                        break
                    except ValueError:
                        print("Vui long nhap so nguyen")
                        continue

                c = PhongMayTinh(maso, daynha, dientich, bongden, maytinh)

            print(a.themphong(c))

        elif choice == 2:
            maso = input("ma so phong can xoa:")
            print(a.xoaphong(maso))

        elif choice == 3:
            print("Tong phong ly thuyet va may tinh lan luot la:", a.tongtungloai())

        elif choice == 4:
            print("Danh sach phong may tinh co 60 may:", a.sophongmaytinhco60())

        elif choice == 5:
            print("Danh sach cac phong dat chuan:", a.danhsachdatchuan())

        else:
            print("Lua chon khong hop le")


main()
