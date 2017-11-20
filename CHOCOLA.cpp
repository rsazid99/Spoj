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
int colcut[1010], rowcut[1010], rsum[1010], csum[1010], n, m;
int dp[1010][1010];

int dpfun(int i, int j)
{
        if(i > n || j > m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ret = INT_MAX;
        int ret1 = rowcut[i] + (csum[m] - csum[j - 1]) + dpfun(i + 1, j);
        int ret2 = colcut[j] + (rsum[n] - rsum[i - 1]) + dpfun(i, j + 1);
        ret = min(ret, min(ret1, ret2));
        cout << rowcut[i] <<" " <<  (csum[m] - csum[j - 1]) << dpfun(i + 1, j)<< endl;
        cout << i <<" " << j << " " << ret << " " << ret1 << " " << ret2<< endl;

        return dp[i][j] = ret;
}

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &m, &n);

                for(int i = 1; i < m; i ++){
                        scanf("%d", &colcut[i]);
                        csum[i] = colcut[i] + csum[i - 1];
                }
                colcut[m] = 0;
                csum[m] = csum[m - 1];

                for(int i = 1; i < n; i ++){
                        scanf("%d", &rowcut[i]);
                        rsum[i] = rowcut[i] + rsum[i - 1];
                }
                rowcut[n] = 0;
                rsum[n] = rsum[n - 1];
                memset(dp, -1, sizeof dp);

                int ans = dpfun(1, 1);

                printf("%d\n", ans);

        }

        return 0;
}
