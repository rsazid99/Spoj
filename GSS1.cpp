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

int n, m, arr[50001];

struct node{
        int suf, prf, tot, mx;
        node()
        {

        }
}tree[4 * 50001];



void build(int id, int l, int r)
{
        if(l == r){
                tree[id].suf = tree[id].prf = tree[id].tot = tree[id].mx = arr[l];
                return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id].suf = max(tree[id * 2 + 1].suf, tree[id * 2 + 1].tot + tree[id * 2].suf);
        tree[id].prf = max(tree[id * 2].prf, tree[id * 2].tot + tree[id * 2 + 1].prf);
        tree[id].mx = max(tree[id * 2].mx, tree[id * 2 + 1].mx);
        tree[id].mx = max(tree[id].mx, tree[id].suf);
        tree[id].mx = max(tree[id].mx, tree[id].prf);
        tree[id].mx = max(tree[id * 2].suf + tree[id * 2 + 1].prf, tree[id].mx);
        tree[id].tot = tree[id * 2].tot + tree[id * 2 + 1].tot;

}


node query(int id, int l, int r, int x, int y)
{
        if(r < x || l > y){
                node ret;
                ret.suf = ret.prf = ret.mx = -inf;
                ret.tot = 0;
                return ret;
        }

        if(l >= x && r <= y) return tree[id];

        int mid = (l + r) / 2;
        node ret1 = query(id * 2, l, mid, x, y);
        node ret2 = query(id * 2 + 1, mid + 1, r, x, y);
        node ret;
        ret.suf = max(ret2.suf, ret2.tot + ret1.suf);
        ret.prf = max(ret1.prf, ret1.tot + ret2.prf);
        ret.mx = max(ret1.mx, ret2.mx);
        ret.mx = max(ret.mx, ret.suf);
        ret.mx = max(ret.mx, ret.prf);
        ret.mx = max(ret.mx, ret1.suf + ret2.prf);
        ret.tot = ret1.tot + ret2.tot;
        return ret;
}


int main()
{
        scanf("%d", &n);

        for(int i = 1; i <= n; i ++){
                scanf("%d", &arr[i]);
        }

        build(1, 1, n);

        scanf("%d", &m);
        int x, y;
        while(m --){
                scanf("%d %d", &x, &y);
                printf("%d\n", query(1, 1, n, x, y).mx);
        }

        return 0;
}
