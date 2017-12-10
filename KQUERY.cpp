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

int n, sz, q, arr[maxn], ans[200001];
set<int> se;
unordered_map<int, int> idx, ridx;
int tree[230005];
struct node{
        int x, y, ind, val;
        node(int _x, int _y, int _ind, int _val){
                x = _x;
                y = _y;
                ind = _ind;
                val = _val;
        }
        bool operator < (const node oth) const{
                if(y != oth.y) return y < oth.y;
                else return x < oth.x;
        }
};

vector<node> qe;


struct fenwick{

        void update(int idx, int val){
                while(idx <= 230000){
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

        scanf("%d", &n);

        for(int i = 1; i <= n; i ++){
                scanf("%d", &arr[i]);
                se.insert(arr[i]);
        }

        scanf("%d", &q);
        int x, y, z;
        for(int i = 1; i <= q; i ++){
                scanf("%d %d %d", &x, &y, &z);
                qe.push_back(node(x, y, i, z));
                se.insert(z);
        }
        sort(qe.begin(), qe.end());

        int indx = 0;
        for(auto it : se){
                idx[it] = ++indx;
                ridx[indx] = it;
        }

        int qi = 0;
        fenwick BIT;
        for(int i = 1; i <= n; i ++){
                BIT.update(idx[arr[i]], 1);
                while(qi < q && qe[qi].y == i){
                        ans[qe[qi].ind] = BIT.query(230000) - BIT.query(idx[qe[qi].val]);
                        qi ++;
                }
        }

        for(int i = 1; i <= q; i ++){
                printf("%d\n", ans[i]);
        }
        return 0;
}
