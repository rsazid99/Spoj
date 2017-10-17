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

const ll MOD = 998244353;

ii exEuclid(ll a, ll b) {
        if(b == 0) return ii(1, 0);
        else {
                ii r = exEuclid(b, a%b);
                return ii(r.ss, r.ff-r.ss*(a/b));
        }
}

int modInv(ll a, ll m) { ii ret = exEuclid(a, m); return ((ret.ff % m) + m ) % m; }

int n, x, brr[1010], m;
vector<int> v;

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);
                int ans = inf;
                for(int i = 1; i <= n; i ++){
                        scanf("%d", &x);
                        v.push_back(x);
                }
                scanf("%d", &m);
                sort(v.begin(), v.end());
                for(int i = 1; i <= m; i ++){
                        scanf("%d", &brr[i]);
                        int lo = lower_bound(v.begin(), v.end(), brr[i]) - v.begin();
                        if(lo == v.size()) lo --;
                        if(lo - 1 >= 0) ans = min(ans, abs(v[lo - 1] - brr[i]));
                        ans = min(ans, abs(v[lo] - brr[i]));
                }


                printf("%d\n", ans);
                v.clear();
        }
        return 0;
}



