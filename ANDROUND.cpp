//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
#include <string>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define inf             1061109567
#define ff  first
#define ss  second

typedef pair<ll, ll> ii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int arr[3 * maxn], tree[3 * 4 * maxn], n, k;

void build(int id, int l, int r)
{
        if(l == r){
                tree[id] = arr[l];
                return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = tree[id * 2] & tree[id * 2 + 1];
}

int query(int id, int l, int r, int x, int y)
{
        if(l > y || r < x) return (1 << 30) - 1;

        if(l >= x && r <= y) return tree[id];
        int mid = (l + r) / 2;
        return (query(id * 2, l, mid, x, y) & query(id * 2 + 1, mid + 1, r, x, y));
}


int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &k);

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &arr[i]);
                }
                build(1, 1, n);

                if(2 * k + 1 < n){
                        for(int i = 1; i <= n; i++){
                                int l = i + k;
                                int r = i - k;

                                int ans;
                                if(l <= n){
                                        ans = query(1, 1, n, i, l);
                                }
                                else{
                                        ans = query(1, 1, n, i , n) & query(1, 1, n, 1, l - n);
                                }

                                if(r >= 1){
                                        ans &= query(1, 1, n, r, i);
                                }
                                else{
                                        ans &= (query(1, 1, n, 1, i) & query(1, 1, n, n + r, n));
                                }
                                if(i > 1) printf(" ");
                                printf("%d", ans);
                        }
                }
                else{
                        int ans = query(1, 1, n, 1, n);
                        for(int i = 1; i <= n; i++){
                                if(i > 1) printf(" ");
                                printf("%d", ans);
                        }

                }
                printf("\n");
        }

        return 0;
}
