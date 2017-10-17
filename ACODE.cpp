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

char s[5005];
ll dp[5005], sz;

ll dpfun(int i)
{
        if(i == sz) return 1;

        if(dp[i] != -1) return dp[i];

        ll ret = 0;
        if(i + 1 < sz && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26 && s[i] != '0') ret += dpfun(i + 2);
        if(s[i] != '0') ret += dpfun(i + 1);

        return dp[i] = ret;
}

int main()
{
        while(true){
                scanf("%s", s);

                if(s[0] == '0') break;

                memset(dp, -1, sizeof dp);
                sz = strlen(s);

                ll ans = dpfun(0);

                printf("%lld\n", ans);
        }
        return 0;
}

