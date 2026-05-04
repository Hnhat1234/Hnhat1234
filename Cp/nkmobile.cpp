#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll bit[2000][2000];

int n;

void update(int x,int y,int val){
    for (;x <=n;x+=(x&(-x))){
        for (int v=y;v<=n;v+=(v&(-v))){
            bit[x][v]+=val;
        }
    }
}
ll get(int x,int y){
    ll s=0;
    for (;x>0;x-=(x&(-x))){
        for (int v=y;v>0;v-=(v&(-v))){
            s+=bit[x][v];
        }
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    while (1){
        int q;cin >> q;
        if (q==0){cin >> n;}
        else if (q==3){break;}
        else if (q==1){
            int x,y,v;
            cin >> x >> y >> v;
            x++;y++;
            update(x,y,v);
        }else{
            int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
            x1++;y1++;x2++;y2++;
            cout << get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1) << '\n';
        }
    }
}


