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

int mat[maxn][4], n;
ll dp[maxn][4];


int main()
{
        int tt = 1;
        while(scanf("%d", &n) && n){
                for(int i = 1; i <= n; i ++){
                        dp[i][0] = 1e18;
                        for(int j = 1; j <= 3; j ++){
                                scanf("%d", &mat[i][j]);
                                dp[i][j] = 1e18;
                        }
                }
                dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1e18;
                dp[1][2] = mat[1][2];

                for(int i = 1; i <= n; i ++){
                        for(int j = 1; j <= 3; j ++){
                                dp[i][j] = min(dp[i][j], dp[i][j - 1] + mat[i][j]);
                                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + mat[i][j]);
                                dp[i][j] = min(dp[i][j], dp[i - 1][j] + mat[i][j]);
                                dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + mat[i][j]);

                        }
                }


                printf("%d. %lld\n", tt ++, dp[n][2]);
        }
        return 0;
}


