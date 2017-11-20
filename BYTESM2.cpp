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

int r, c, mat[101][101], dp[101][101];


int dpfun(int i, int j)
{
        if(i == r + 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ret = 0;

        ret = max(ret, mat[i][j] + dpfun(i + 1, j));
        if(j - 1 >= 1) ret = max(ret, mat[i][j] + dpfun(i + 1, j - 1));
        if(j + 1 <= c) ret = max(ret, mat[i][j] + dpfun(i + 1, j + 1));

        return dp[i][j] = ret;

}

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &r, &c);

                for(int i = 1; i <= r; i ++){
                        for(int j = 1; j <= c; j ++){
                                scanf("%d", &mat[i][j]);
                        }
                }

                int ans = 0;
                memset(dp, -1, sizeof dp);
                for(int i = 1; i <= c; i ++){
                        ans = max(ans, dpfun(1, i));
                }

                printf("%d\n", ans);
        }

        return 0;
}
