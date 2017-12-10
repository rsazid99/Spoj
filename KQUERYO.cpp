//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
#include <string>
using namespace std;

#define maxn            30005
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

int n, sz, q, arr[maxn], tree[20 * maxn], mx[20 * maxn], mn[20 * maxn], L[20 * maxn], R[20 * maxn], root[maxn], NEW = 0;
set<int> se;
unordered_map<int, int> idx, ridx;


void build(int id, int l, int r)
{
        if(l == r){
                tree[id] = 0;
                mx[id] = 0;
                mn[id] = inf;
                return;
        }

        int mid = (l + r) / 2;
        L[id] = ++ NEW;
        R[id] = ++ NEW;
        build(L[id], l, mid);
        build(R[id], mid + 1, r);
        tree[id] = tree[L[id]] + tree[R[id]];
        mx[id] = max(mx[L[id]], mx[R[id]]);
        mn[id] = min(mn[L[id]], mn[R[id]]);
}

int update(int id, int l, int r, int pos)
{
        int ID = ++ NEW;
        if(l == r){
                tree[ID] = tree[id] + 1;
                mx[ID] = ridx[l];
                mn[ID] = ridx[l];
                return ID;
        }

        int mid = (l + r) / 2;
        L[ID] = L[id], R[ID] = R[id];
        if(pos <= mid) L[ID] = update(L[id], l, mid, pos);
        else R[ID] = update(R[id], mid + 1, r, pos);
        tree[ID] = tree[L[ID]] + tree[R[ID]];
        mx[ID] = max(mx[L[ID]], mx[R[ID]]);
        mn[ID] = min(mn[L[ID]], mn[R[ID]]);
        return ID;
}

int query(int ID, int id, int l, int r, int val)
{

        if(mn[ID] > val){
                return tree[ID] - tree[id];
        }

        int mid = (l + r) / 2;

        int ret = 0;
        if(mx[L[ID]] > val) ret += query(L[ID], L[id], l, mid, val);
        if(mx[R[ID]] > val) ret += query(R[ID], R[id], mid + 1, r, val);
        return  ret;
}


int main()
{
        //read();
        //write();
        scanf("%d", &n);

        for(int i = 1; i <= n; i ++){
                scanf("%d", &arr[i]);
                se.insert(arr[i]);
        }
        int indx = 0;

        for(auto it : se){
                idx[it] = ++indx;
                ridx[indx] = it;
        }
        build(0, 1, n);
        for(int i = 1; i <= n; i ++){
                root[i] = update(root[i - 1], 1, n, idx[arr[i]]);
        }
        scanf("%d", &q);
        int x, y, z;
        int ans = 0;
        while(q --){
                scanf("%d %d %d", &x, &y, &z);
                x ^= ans;
                y ^= ans;
                z ^= ans;
                if(x < 1) x = 1;
                if(y > n) y = n;
                if(x > y) ans = 0;
                else ans = query(root[y], root[x - 1], 1, n, z);
                printf("%d\n", ans);
        }

        return 0;
}

