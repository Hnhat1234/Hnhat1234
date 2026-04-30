#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define maxi(a, b) a = max(a, b)
#define mize(a, b) a = min(a, b)
#define getbit(a, i) ((a) >> (i) & 1)

#define FOR(i, a, b) for(int i=a, _n=b; i<=_n; ++i)
#define FORD(i, a, b) for(int i=a, _n=b; i>=_n; --i)
#define REP(i, _n) for(int i=0; i<_n; ++i)

#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair

#define ii pair<int, int>

using namespace std;

const ll basehash = 31;
const ll modhash = 1000000003;

ll a[200005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int n; cin >> n;
    ll sum = 0;
    for (int i = 1;i <= n;++i){
        cin >> a[i];
        sum += a[i];
    }
    sum/=n;
    ll ans = 0;
    for (int i = 1;i <= n;++i){
        if (a[i] < sum){ans += sum - a[i];}
    }
    cout << ans;

}
/* Cre : Hong lau mong (Minh add de code bot trong <("))
Hook x2
Day mien phi khong can tien bac, du biet suc vat cang luc cang luoi
Day lai lu suc sinh cach rap chuan, va day them chung no cach lam nguoi
Ghi chep roi cut ve nha ma doc, lu moi ro hoc thuc khong sau rong
Ngoi nat dung co lam GIA BAO NGOC, lu chung may dung co mo Hong Lau Mong

Tao phai can nhac lieu co nen rep Pjpo, vi day suc sinh chac gi se co ich
Mot phan vi tao cung xem xet nghi lo, fan no cam co mat con me no nick
Cai cuoc song nay no cu rinh giong gio, bat cong la thu duy nhat no luon thua
Thang Choi da dau voi tu linh trong do, con tao dang dau voi mot con duong dua
Viet status gay nhu Chi Pu, nhac ra duoc mot nhum van com
Quay som an gi ha cac ban? Dit con me may quay som an lon
Mat bao lau moi ran ra cai bai nhac nhu buoi nguoi ta nghe qua loa roi tat
Phai chang may ban casting dien vien Star Wars cho vai Jabba the Hut?
May doi dit me ai, khi con cac may thut trong mo va deo biet tim dau
Con ghe may bat den pin mo mam duoi tung la mo, goi do la VACH LA TIM SAU
Bon tao chang dam de doa hay bao luc, vi dan bay gio rat la khon
Ho thua biet con suc sinh nhu may khi chet thi deo co dat ma chon
Nhung neu no chet thi cung dung hoang hot, chang co viec gi phai so lo
Chung may co the tim xac Pjpo trong goi hat nem tu thit Knorr
Chung may co the chac chan rang, Pjpo ra di voi mot tam long son
Xua nay cac cu da day: “Con lon co beo thi long moi ngon”

Hook x2

Fat joke may truoc, rebuttal may sau, tao day lai chung may vai chieu rap chien
Bay gio deo con giu le nua, chi con su xuc pham, cho tat ca nhung dieu khac bien
To su bo cai truyen thong lam di, tu hao lon gi cai manh dat nhieu nhuong
Nghe mien Tay tao deo thay de thuong, tao thay con di Ngoc Trinh la bieu tuong
 
Dam mo mom noi den Co va rap, chang le may tinh nguyen bi bat sao
Hung Cao la De Thich cua rap Viet, CAO KY may deo the CAO KY bang tao
Khuon mat may chi co cai TUONG SI, may la TUONG go muc tao nga ra dot
Vi sinh ra dam mot chi gioi khoe XE PHAO hoac cau fame nho cai MA TOT
Do vo hoc cam mom lai, tao da im lang, may duoc the lan luot lam can
Neu tao co cong ty chi dao, thi cong ty do no yeu nuoc dang hoang
Phai bia chuyen tao co cong ty chi dao, noi dieu co bao gio may mang hoi loi?
Noi tao bi DUNG SAU GIAT DAY, ro rang con cho Ky dang noi DOI/ROI
Mang van cun ly bia bi va vo mom thi tao hoi may dinh an bang gi?
Hay nho Quoc Ca duoc viet boi VAN CAO chu no deo duoc viet boi VAN KY
May la noi si nhuc cua gia toc, chang ai dam mang noi nhuc nay giai bay
Den muc me may se mat lon ruoi ruoi neu ngay hom day ba ay say thai may

Hook x2

Bao nam tao mong dat Viet nay hoa hop, nhung chung may khien tao ngam chat hon cam
Neu bao ve que huong bi coi la hai mat, thi tao xin tinh nguyen lam hai mat ngan nam
Tao tinh nguyen lam ke phan dien, hien ngang ngao nghe nhech mieng cuoi doi
Thang HAI MAT dua may len toa nha cao nhat dat Viet, va bien may thanh NGUOI ROI
Chung may gioi ca van lan vo, lai cai bai doa danh coi mang nguoi re nhu dinh vit
Lo ma tao bi lam sao ma may phai vao tu, hay noi loi vinh biet voi trinh dit
Chung may tai nang qua bien ao that tinh nhan ra dieu do da khien tao giat minh
Nao la photoshop voi cam co doi thu, chung may moi xung dang la rapper lap trinh
Tao thuong con me may tham lon, da kho so luc lam bon
De ra doi thang am hon, som bi tao bat cam mom
Co thang fan khong the giau moi tinh dong tinh voi Pjpo
Ten no noi len mong muon ca doi duoc dinh voi “bi to”
VD chet moi duoc khen boi nhung dua chui lai thay
Dit con me do suc vat la loi tao muon gui chung may
VD bi de tu chui, la truyen thong do ha may?
Gio VD thanh la chan cho cai noi giong cho phan thay
Day chung may va tat ca bon phan thay o ba mien
Mon Dao Duc va nhan pham, chang can day co ra tien
Nhuc ma dam vo liem si ma bon moi ro tung ho
Danh nhu nam xua Ly Muc giet 10 van ro Hung No
Do la chut hy vong cua chung may sao?
Vay chung may oc cut hay bam sinh chung may Down?
May thang kha nang yeu mau mang ca chan chieu
Bo nha ra Punch Mieu dap dau cung thay Cao*/
