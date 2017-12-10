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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n, q, arr[maxn];
struct node{
        int pf, pfcnt, sf, sfcnt, mxcnt;
        node(){

        }
        node(int _pf, int _sf, int _pfcnt, int _sfcnt, int _mxcnt){
                pf = _pf;
                sf = _sf;
                pfcnt = _pfcnt;
                sfcnt = _sfcnt;
                mxcnt = _mxcnt;
        }

};
node tree[4 * maxn];

void build(int id, int l, int r)
{
        if(l == r){
                tree[id].pf = tree[id].sf = arr[l];
                tree[id].mxcnt = tree[id].pfcnt = tree[id].sfcnt = 1;
                return;
        }

        int mid = (l + r) / 2;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id].mxcnt = 0;
        if(tree[id * 2].sf == tree[id * 2 + 1].pf){
                tree[id].mxcnt = tree[id * 2].sfcnt + tree[id * 2 + 1].pfcnt;
        }
        else tree[id].mxcnt = max(tree[id * 2].sfcnt, tree[id * 2 + 1].pfcnt);
        if(tree[id * 2].pfcnt == mid - l + 1 && tree[id * 2].pf == tree[id * 2 + 1].pf){
                tree[id].mxcnt = max(tree[id].mxcnt, tree[id * 2].pfcnt + tree[id * 2 + 1].pfcnt);
                tree[id].pf = tree[id * 2].pf;
                tree[id].pfcnt = tree[id * 2].pfcnt + tree[id * 2 + 1].pfcnt;
        }
        else{
                tree[id].mxcnt = max(tree[id].mxcnt, tree[id * 2].pfcnt);
                tree[id].pf = tree[id * 2].pf;
                tree[id].pfcnt = tree[id * 2].pfcnt;
        }

        if(tree[id * 2 + 1].sfcnt == r - mid && tree[id * 2 + 1].sf == tree[id * 2].sf){
                tree[id].mxcnt = max(tree[id].mxcnt, tree[id * 2 + 1].sfcnt + tree[id * 2].sfcnt);
                tree[id].sf = tree[id * 2 + 1].sf;
                tree[id].sfcnt = tree[id * 2 + 1].sfcnt + tree[id * 2].sfcnt;
        }
        else{
                tree[id].mxcnt = max(tree[id].mxcnt, tree[id * 2 + 1].sfcnt);
                tree[id].sf = tree[id * 2 + 1].sf;
                tree[id].sfcnt = tree[id * 2 + 1].sfcnt;
        }
        tree[id].mxcnt = max(tree[id].mxcnt, max(tree[id * 2].mxcnt, tree[id * 2 + 1].mxcnt));
}

node query(int id, int l, int r, int x, int y)
{
        if(r < x || l > y){
                node ret = node(-inf, 0, -inf, 0, 0);
                return ret;
        }

        if(l >= x && r <= y) return tree[id];

        int mid = (l + r) / 2;
        node ret1 = query(id * 2, l, mid, x, y);
        node ret2 = query(id * 2 + 1, mid + 1, r, x, y);
        node ret = node(-inf, 0, -inf, 0, 0);

        if(ret1.sf == ret2.pf){
                ret.mxcnt = ret1.sfcnt + ret2.pfcnt;
        }
        else ret.mxcnt = max(ret1.sfcnt, ret2.pfcnt);
        if(ret1.pfcnt == mid - l + 1 && ret1.pf == ret2.pf){
                ret.mxcnt = max(ret.mxcnt, ret1.pfcnt + ret2.pfcnt);
                ret.pf = ret1.pf;
                ret.pfcnt = ret1.pfcnt + ret2.pfcnt;
        }
        else{
                ret.mxcnt = max(ret.mxcnt, ret1.pfcnt);
                ret.pf = ret1.pf;
                ret.pfcnt = ret1.pfcnt;
        }

        if(tree[id * 2 + 1].sfcnt == r - mid && ret2.sf == ret1.sf){
                ret.mxcnt = max(ret.mxcnt, ret2.sfcnt + ret1.sfcnt);
                ret.sf = ret2.sf;
                ret.sfcnt = ret2.sfcnt + ret1.sfcnt;
        }
        else{
                ret.mxcnt = max(ret.mxcnt, ret2.sfcnt);
                ret.sf = ret2.sf;
                ret.sfcnt = ret2.sfcnt;
        }
        ret.mxcnt = max(ret.mxcnt, max(ret1.mxcnt, ret2.mxcnt));
        //cout << l <<" " << r <<" " << ret1.pf << " " << ret1.pfcnt  <<" " << ret2.sf <<" " << ret2.sfcnt<< endl;
        return ret;
}


int main()
{
        while(scanf("%d", &n)){
                if(!n) break;

                scanf("%d", &q);

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &arr[i]);
                }

                build(1, 1, n);

                int x, y;
                while(q --){
                        scanf("%d %d", &x, &y);
                        printf("%d\n", query(1, 1, n, x, y).mxcnt);
                }
        }

        return 0;
}
