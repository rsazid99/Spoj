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

int a, b, c, q, tree[3][4 * maxn], lazy[3][4 * maxn];

void build(int id, int l, int r, int ax)
{
        if(l == r){
                tree[ax][id] = 0;
                lazy[ax][id] = 0;
                return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid, ax);
        build(id * 2 + 1, mid + 1, r, ax);
        tree[ax][id] = tree[ax][id * 2] + tree[ax][id * 2 + 1];
        lazy[ax][id] = 0;
}


void propagate(int id, int l, int r, int ax)
{
        lazy[ax][id] = 0;
        lazy[ax][id * 2] ^= 1;
        lazy[ax][id * 2 + 1] ^= 1;

        int mid = (l + r) / 2;
        tree[ax][id * 2] = (mid - l + 1) - tree[ax][id * 2];
        tree[ax][id * 2 + 1] = (r - (mid + 1) + 1) - tree[ax][id * 2 + 1];
}

void update(int id, int l, int r, int x, int y, int ax)
{
        if(l > y || r < x) return;
        if(l >= x && r <= y){
                lazy[ax][id] ^= 1;
                tree[ax][id] = (r - l + 1) - tree[ax][id];
                return;
        }
        if(lazy[ax][id]) propagate(id, l, r, ax);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, x, y, ax);
        update(id * 2 + 1, mid + 1, r, x, y, ax);
        tree[ax][id] = tree[ax][id * 2] + tree[ax][id * 2 + 1];
}


int query(int id, int l, int r, int x, int y, int ax)
{

        if(l > y || r < x) return 0;

        if(l >= x && r <= y) return tree[ax][id];

        if(lazy[ax][id]) propagate(id, l, r, ax);
        int mid = (l + r) / 2;
        return query(id * 2, l, mid, x, y, ax) + query(id * 2 + 1, mid + 1, r, x, y, ax);
}





int main()
{
        int t, ty, x, y, z, x1, y1, z1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d %d %d", &a, &b, &c, &q);
                build(1, 0, a - 1, 0);
                build(1, 0, b - 1, 1);
                build(1, 0, c - 1, 2);
                while(q --){
                        scanf("%d", &ty);
                        if(ty == 0){
                                scanf("%d %d", &x, &y);
                                update(1, 0, a - 1, x, y, 0);
                        }
                        else if(ty == 1){
                                scanf("%d %d", &x, &y);
                                update(1, 0, b - 1, x, y, 1);
                        }
                        else if(ty == 2){
                                scanf("%d %d", &x, &y);
                                update(1, 0, c - 1, x, y, 2);
                        }
                        else{
                                scanf("%d %d %d %d %d %d", &x, &y, &z, &x1, &y1, &z1);
                                ll rx = query(1, 0, a - 1, x, x1, 0);
                                ll gx = (x1 - x + 1) - rx;
                                ll ry = query(1, 0, b - 1, y, y1, 1);
                                ll gy = (y1 - y + 1) - ry;
                                ll rz = query(1, 0, c - 1, z, z1, 2);
                                ll gz = (z1 - z + 1) - rz;
                                ll ans = (rx * gy * gz) + (gx * ry * gz) + (gx * gy * rz) + (rx * ry * rz);
                                printf("%lld\n", ans);
                        }
                }
        }
}
