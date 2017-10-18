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

char s[6110];
int dp[6100][6100];

int dpfun(int i, int j)
{
        if(j < i) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ret = inf;

        if(s[i] == s[j]){
                ret = min(ret, dpfun(i + 1, j - 1));
        }
        else{
                ret = min(ret, 1 + dpfun(i, j - 1));
                ret = min(ret, 1 + dpfun(i + 1, j));
        }

        return dp[i][j] = ret;

}

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%s", s);
                memset(dp, -1, sizeof dp);
                int ans = dpfun(0, strlen(s) - 1);
                printf("%d\n", ans);
        }
        return 0;
}


