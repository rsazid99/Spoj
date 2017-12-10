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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n, arr[30005], frst[1000005], scnd[1000005], ans[200005], q;
int tree[30005];

struct node{
        int l, r, idx;
        node(int _l, int _r, int _idx){
                l = _l;
                r = _r;
                idx = _idx;
        }
        bool operator < (const node oth) const{
                return r < oth.r;
        }

};


vector<node> qe;

struct fenwick{

        void update(int idx, int val){
                while(idx <= n){
                        tree[idx] += val;
                        idx += idx & (-idx);
                }
        }
        int query(int idx)
        {
                int sum = 0;
                while(idx > 0){
                        sum += tree[idx];
                        idx -= idx & (-idx);
                }
                return sum;
        }
};



int main()
{
        int x, y;

        scanf("%d", &n);

        for(int i = 1; i <= n; i ++){
                scanf("%d", &arr[i]);
        }

        scanf("%d", &q);

        for(int i = 1; i <= q; i ++){
                scanf("%d %d", &x, &y);
                qe.push_back(node(x, y, i));
        }
        sort(qe.begin(), qe.end());

        fenwick BIT;

        int qi = 0;

        for(int i = 1; i <= n; i ++){
                if(scnd[arr[i]]){
                        BIT.update(scnd[arr[i]], 0);
                }
                if(frst[arr[i]]){
                        BIT.update(frst[arr[i]], -1);
                        scnd[arr[i]] = frst[arr[i]];
                }
                BIT.update(i, 1);
                frst[arr[i]] = i;
                while(qi < q && qe[qi].r == i){
                        ans[qe[qi].idx] = BIT.query(i) - BIT.query(qe[qi].l - 1);
                        qi ++;
                }
        }

        for(int i = 1; i <= q; i ++){
                printf("%d\n", ans[i]);
        }

        return 0;
}
