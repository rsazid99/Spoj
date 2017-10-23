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

int n, k, arr[20010];

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &k);
                for(int i = 1; i <= n; i ++){
                        scanf("%d", &arr[i]);
                }

                sort(arr + 1, arr + 1 + n);
                int ans = inf;
                for(int i = k; i <= n; i ++){
                        int last = i - k + 1;
                        ans = min(ans, arr[i] - arr[last]);
                }
                printf("%d\n", ans);
        }
        return 0;
}




