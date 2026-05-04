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
const int LG = 20;

int a[200005], st[20][200005];

int gcd(int a,int b){
    if (b == 0) return a;
    return gcd(b,a % b);
}
void preprocess(int n) {
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = gcd(st[j - 1][i],st[j - 1][i + (1 << (j - 1))]);
}
int querygcd(int l, int r){
    int k = __lg(r - l + 1);
    return gcd(st[k][l], st[k][r - (1 << k) + 1]);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("Hnhatn.inp","r",stdin);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int x = 0;
        for (int i = 0;i < n;++i){
            cin >> a[i];
            if (i == 0){x = a[i];}
            else{
                x = gcd(x,a[i]);
            }
        }
        int l = 0; int r = 0;
        int ans = 0;
        int cur = 0;
        while (l <= n && cur != -1){
            if (cur == x){
                while (gcd(l,r) == x){
                    ans = max(ans,r - l);
                    if (l == r){
                        l = (l + 1) % n; r = (r + 1) % n;
                        if (l == 0){cur = -1; break;}
                    }
                    else{
                        l = (l + 1) % n;
                    }
                }
            }else{
                while (1){
                    if (l <= r){
                        if (gcd(l,r) != x){l = (l + 1) % n; r = (r + 1) % n;}
                    }else{

                    }
                }
            }
        }
        en:
        cout << ans << '\n';
    }
}
/* Cre : Hồng lâu mộng (Mình add để code bớt trống <("))
Hook x2
Dạy miễn phí không cần tiền bạc, dù biết súc vật càng lúc càng lười
Dạy lại lũ súc sinh cách rap chuẩn, và dạy thêm chúng nó cách làm người
Ghi chép rồi cút về nhà mà đọc, lũ mọi rợ học thức không sâu rộng
Ngói nát đừng cố làm GIẢ BẢO NGỌC, lũ chúng mày đừng có mơ Hồng Lâu Mộng

Tao phải cân nhắc liệu có nên rep Pjpo, vì dạy súc sinh chắc gì sẽ có ích
Một phần vì tao cũng xem xét nghĩ lo, fan nó cắm cờ mất con mẹ nó nick
Cái cuộc sống này nó cứ rình giông gió, bất công là thứ duy nhất nó luôn thừa
Thằng Choi đã đấu với tứ linh trong đó, còn tao đang đấu với một con đuông dừa
Viết status gáy như Chi Pu, nhạc ra được một nhúm văn còm
Quẩy sớm ăn gì hả các bạn? Địt con mẹ mày quẩy sớm ăn lồn
Mất bao lâu mới rặn ra cái bài nhạc như buồi người ta nghe qua loa rồi tắt
Phải chăng mày bận casting diễn viên Star Wars cho vai Jabba the Hut?
Mày đòi địt mẹ ai, khi con cặc mày thụt trong mỡ và đéo biết tìm đâu
Con ghệ mày bật đèn pin mò mẫm dưới từng lá mỡ, gọi đó là VẠCH LÁ TÌM SÂU
Bọn tao chẳng dám đe dọa hay bạo lực, vì dân bây giờ rất là khôn
Họ thừa biết con súc sinh như mày khi chết thì đéo có đất mà chôn
Nhưng nếu nó chết thì cũng đừng hoảng hốt, chẳng có việc gì phải sợ lo
Chúng mày có thể tìm xác Pjpo trong gói hạt nêm từ thịt Knorr
Chúng mày có thể chắc chắn rằng, Pjpo ra đi với một tấm lòng son
Xưa nay các cụ đã dạy: “Con lợn có béo thì lòng mới ngon”

Hook x2

Fat joke mày trước, rebuttal mày sau, tao dạy lại chúng mày vài chiêu rap chiến
Bây giờ đéo còn giữ lễ nữa, chỉ còn sự xúc phạm, cho tất cả những điều khác biến
Tổ sư bố cái truyền thống làm đĩ, tự hào lồn gì cái mảnh đất nhiễu nhương
Nghe miền Tây tao đéo thấy dễ thương, tao thấy con đĩ Ngọc Trinh là biểu tượng
 
Dám mở mõm nói đến Cờ và rap, chẳng lẽ mày tình nguyện bị bắt sao
Hưng Cao là Đế Thích của rap Việt, CAO KỲ mày đéo thể CAO KỲ bằng tao
Khuôn mặt mày chỉ có cái TƯỚNG SĨ, mày là TƯỢNG gỗ mục tao ngả ra đốt
Vì sinh ra đám mọt chỉ giỏi khoe XE PHÁO hoặc câu fame nhờ cái MÃ TỐT
Đồ vô học câm mõm lại, tao đã im lặng, mày được thể lấn lướt làm càn
Nếu tao có công ty chỉ đạo, thì công ty đó nó yêu nước đàng hoàng
Phải bịa chuyện tao có công ty chỉ đạo, nói điêu có bao giờ mày mang hối lỗi?
Nói tao bị ĐỨNG SAU GIẬT DÂY, rõ ràng con chó Kỳ đang nói DỐI/RỐI
Mang văn cùn lý bịa bị vả vỡ mõm thì tao hỏi mày định ăn bằng gì?
Hãy nhớ Quốc Ca được viết bởi VĂN CAO chứ nó đéo được viết bởi VĂN KỲ
Mày là nỗi sỉ nhục của gia tộc, chẳng ai dám mang nỗi nhục này giãi bày
Đến mức mẹ mày sẽ mát lồn rười rượi nếu ngày hôm đấy bà ấy sảy thai mày

Hook x2

Bao năm tao mong đất Việt này hòa hợp, nhưng chúng mày khiến tao ngậm chặt hờn căm
Nếu bảo vệ quê hương bị coi là hai mặt, thì tao xin tình nguyện làm hai mặt ngàn năm
Tao tình nguyện làm kẻ phản diện, hiên ngang ngạo nghễ nhếch miệng cười đời
Thằng HAI MẶT đưa mày lên tòa nhà cao nhất đất Việt, và biến mày thành NGƯỜI RƠI
Chúng mày giỏi cả văn lẫn võ, lại cái bài dọa đánh coi mạng người rẻ như đinh vít
Lỡ mà tao bị làm sao mà mày phải vào tù, hãy nói lời vĩnh biệt với trinh đít
Chúng mày tài năng quá biến ảo thật tình nhận ra điều đó đã khiến tao giật mình
Nào là photoshop với cắm cờ đối thủ, chúng mày mới xứng đáng là rapper lập trình
Tao thương con mẹ mày thâm lồn, đã khổ sở lúc lâm bồn
Đẻ ra đời thằng âm hồn, sớm bị tao bắt câm mồm
Có thằng fan không thể giấu mối tình đồng tính với Pjpo
Tên nó nói lên mong muốn cả đời được dính với “bi to”
VD chết mới được khen bởi những đứa chửi lại thầy
Địt con mẹ đồ súc vật là lời tao muốn gửi chúng mày
VD bị đệ tử chửi, là truyền thống đó hả mày?
Giờ VD thành lá chắn cho cái nòi giống chó phản thầy
Dạy chúng mày và tất cả bọn phản thầy ở ba miền
Môn Đạo Đức và nhân phẩm, chẳng cần dạy có ra tiền
Nhục mạ đám vô liêm sỉ mà bọn mọi rợ tung hô
Đánh như năm xưa Lý Mục giết 10 vạn rợ Hung Nô
Đó là chút hy vọng của chúng mày sao?
Vậy chúng mày óc cứt hay bẩm sinh chúng mày Down?
Mấy thằng khả năng yếu mau mang cả chăn chiếu
Bỏ nhà ra Punch Miếu dập đầu cúng thầy Cao*/
