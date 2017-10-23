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
int add = 10000;
int ase[2][20000], n, m, x, dp[10000][2];
vector<int> v[2];

int dpfun(int i, int ty)
{
        if((ty == 0 && i == n) || (ty == 1 && i == m)) return 0;

        if(dp[i][ty] != -1) return dp[i][ty];

        int ret = -inf ;

        if(ase[1 - ty][v[ty][i] + add] >= 0){
                ret = max(ret, v[ty][i] + dpfun(ase[1 - ty][v[ty][i] + add] + 1, 1 - ty));
        }
        ret = max(ret, v[ty][i] + dpfun(i + 1, ty));

        return dp[i][ty] = ret;
}

int main()
{


        while(true){
                memset(ase, -1, sizeof ase);
                memset(dp, -1, sizeof dp);

                scanf("%d", &n);

                if(!n) break;

                for(int i = 0; i < n; i ++){
                        scanf("%d", &x);
                        v[0].push_back(x);
                        ase[0][x + add] = i;
                }

                scanf("%d", &m);

                for(int i = 0; i < m; i ++){
                        scanf("%d", &x);
                        v[1].push_back(x);
                        ase[1][x + add] = i;
                }

                int ans = max(dpfun(0, 0), dpfun(0, 1));
                printf("%d\n", ans);
                v[0].clear();
                v[1].clear();
        }

        return 0;
}


