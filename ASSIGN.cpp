//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
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

int mat[20][20], n, memo[1 << 20];
ll dp[1 << 20];
int tt;

ll dpfun(int i, int mask)
{
        if(i == n) return 1;

        if(memo[mask] == tt) return dp[mask];

        ll ret = 0;
        for(int j = 0; j < n; j ++){
                if(!check(mask, j) && mat[i][j]){
                        ret += dpfun(i + 1, mask | (1 << j));
                }
        }
        memo[mask] = tt;
        return dp[mask] = ret;
}


int main()
{
        int t;
        scanf("%d", &t);
        while(t --){
                scanf("%d", &n);
                tt ++;
                for(int i = 0; i < n; i ++){
                        for(int j = 0; j < n; j ++){
                                scanf("%d", &mat[i][j]);
                        }
                }
                ll ans = dpfun(0, 0);

                printf("%lld\n", ans);
        }

        return 0;
}
