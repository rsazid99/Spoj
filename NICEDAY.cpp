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
#define read()          freopen("in.txt", "r", stdin)
#define write()         freopen("output.txt", "w", stdout)
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n;
struct node{
        int a, b, c;
        bool operator < (const node oth) const{
                return a < oth.a;
        }
};

node arr[maxn];
int tree[4 * maxn];

void build(int id, int l, int r)
{
        if(l == r){
                tree[id] = inf;
                return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = min(tree[id * 2], tree[id * 2 + 1]);

}


void update(int id, int l, int r, int pos, int val)
{
        if(l == r){
                tree[id] = val;
                return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid) update(id * 2, l, mid, pos, val);
        else update(id * 2 + 1, mid + 1, r, pos, val);
        tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}

int query(int id, int l, int r, int x, int y)
{
        if(r < x || l > y) return inf;

        if(l >= x && r <= y) return tree[id];

        int mid = (l + r) / 2;
        return min(query(id * 2, l, mid, x, y), query(id * 2 + 1, mid + 1, r, x, y));

}
int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
                }
                sort(arr + 1, arr + 1 + n);
                build(1, 1, n);
                int cnt = 0;
                for(int i = 1; i <= n; i ++){
                        update(1, 1, n, arr[i].b, arr[i].c);
                        int ret = query(1, 1, n, 1, arr[i].b);
                        if(ret == arr[i].c) cnt ++;
                }
                printf("%d\n", cnt);
        }

       return 0;
}
