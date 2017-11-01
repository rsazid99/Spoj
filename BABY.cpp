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

int n, arr[20], brr[20], dp[20][65536];

int dpfun(int i, int mask)
{
        if(i == n + 1) return 0;

        if(dp[i][mask] != -1) return dp[i][mask];

        int ret = inf;

        for(int j = 1;j <= n; j ++){
                if(!(mask & (1 << j))){
                        ret = min(ret, abs(i - j) + abs(arr[i] - brr[j]) + dpfun(i + 1, mask | (1 << j)));
                }
        }

        return dp[i][mask] = ret;
}

int main()
{
        while(scanf("%d", &n) && n){

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &arr[i]);
                }

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &brr[i]);
                }
                memset(dp, -1, sizeof dp);
                int ans = dpfun(1, 0);
                printf("%d\n", ans);
        }


        return 0;
}
