DS = {}

def themsinhvien():
    print("Them sinh vien")
    MS, HT = 0, 0
    MS = input("MSSV: ")
    if (MS in DS.keys()):
        raise "MSSV trung nhau"
    HT = input("Ho va ten: ")
    DS[MS] = HT
def xoasinhvien(MSSV):
    if (MSSV in DS.keys()):
        DS.pop(MSSV)
    else:
        raise "MSSV khong co trong danh sach"
def suasinhvien(MSSV):
    if (MSSV in DS.keys()):
        MS = input("Ma so can sua: ")
        HT = input("Ten can sua: ")
        DS.pop(MSSV)

