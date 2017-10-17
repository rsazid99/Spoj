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

typedef pair<int, int> ii;

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

int r, c, visited[55][55], dp[55][55];
int row[] = {1, -1, 0, 0, 1, 1, -1, -1};
int col[] = {0, 0, 1, -1, 1, -1, 1, -1};
char g[55][55];

int dfs(int x, int y, int depth)
{
        visited[x][y] = 1;
        dp[x][y] = 1;
        for(int i = 0; i < 8;i ++){
                int nr = row[i] + x;
                int nc = col[i] + y;
                if(nr >= 0 && nr < r && nc >= 0 && nc < c && g[nr][nc] - g[x][y] == 1){
                        if(!visited[nr][nc]) dp[x][y] = max(dp[x][y] , 1 + dfs(nr, nc, depth + 1));
                        else dp[x][y] = max(dp[x][y] , dp[nr][nc] + 1);
                }

        }
        return dp[x][y];
}



int main()
{
        int tt = 1;
        while(scanf("%d %d", &r, &c)){
                if(!r && !c) break;

                for(int i = 0; i < r; i ++){
                        scanf("%s", g[i]);
                }

                memset(visited, 0, sizeof visited);
                memset(dp, 0, sizeof dp);
                int ans = 0;
                for(int i = 0; i < r; i ++){
                        for(int j = 0; j < c; j ++){
                                if(!visited[i][j] && g[i][j] == 'A'){
                                        ans = max(ans, dfs(i, j, 0));
                                }
                        }
                }

                printf("Case %d: %d\n", tt ++, ans);
        }


        return 0;
}


