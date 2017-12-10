//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
#include <string.h>
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
char s[30];
int tree[30001];
map<string, int> mp;

struct fenwick{

        void clr(){
                memset(tree, 0, sizeof tree);
        }
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

        //ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);
                getchar();
                int idx = 0;
                for(int i = 0; i < n; i ++){
                        scanf("%s", s);
                        mp[s] = ++idx;
                }

                fenwick BIT;
                BIT.clr();

                int ans = 0;
                for(int i = 0; i < n; i ++){
                        scanf("%s", s);
                        ans += BIT.query(n) - BIT.query(mp[s]);
                        BIT.update(mp[s], 1);
                }
                printf("%d\n", ans);

                mp.clear();
        }

        return 0;
}
