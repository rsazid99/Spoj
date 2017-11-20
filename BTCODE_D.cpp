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

int n, m, w[110][110], c[110][110];
ll prc[110][110];

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);

                for(int i = 1;i <= n; i ++){
                        for(int j = 1; j <= m; j ++){
                                scanf("%d", &w[i][j]);
                        }
                }

                for(int i = 1;i <= n; i ++){
                        for(int j = 1; j <= m; j ++){
                                scanf("%d", &c[i][j]);
                        }
                }

                for(int i = 1;i <= n; i ++){
                        for(int j = 1; j <= m; j ++){
                                scanf("%lld", &prc[i][j]);
                                prc[i][j] *= min(w[i][j], c[i][j]);
                        }
                }

                ll sum = 0;
                for(int i = 1; i <= n; i ++){
                        ll mx = -1;
                        for(int j = 1; j <= m; j ++) mx = max(mx, prc[i][j]);
                        sum += mx;
                }

                printf("%lld\n", sum);
        }

        return 0;
}
