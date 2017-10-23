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

int n, m, k, c;
int mat[101][101];

int level[210], mate[220];
vector<int>adj[210];

bool bfs()
{
        queue<int> q;
        for(int i = 1; i <= n; i ++){
                level[i] = -1;
                if(mate[i] < 0){
                        level[i] = 0;
                        q.push(i);
                }
        }
        while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int i = 0; i < adj[u].size(); i ++){
                        int w = adj[u][i];
                        int v = mate[w];
                        if(v < 0) return true;
                        if(level[v] < 0){
                                level[v] = level[u] + 1;
                                q.push(v);
                        }
                }
        }
        return false;
}
bool dfs(int u)
{
        for(int i = 0; i < adj[u].size(); i ++){
                int w = adj[u][i];
                int v = mate[w];
                if(v < 0 || (level[v] > level[u] && dfs(v))){
                        mate[u] = w;
                        mate[w] = u;
                        return true;
                }
        }
        return false;
}


bool ok(int val)
{
        memset(mate, -1, sizeof mate);
        memset(level, 0, sizeof level);
        for(int i = 1; i <= n; i ++){
                for(int j = 1; j <= m; j ++){
                        if(mat[i][j] <= val){
                                adj[i].push_back(j + n);
                        }
                        if(mat[i][j] + c <= val){
                                adj[i].push_back(j + n + m);
                        }
                }
        }

        int match = 0;

        while(bfs()){
                for(int i = 1; i <= n; i ++){
                        if(mate[i] < 0 && dfs(i)) match++;
                }
        }
        for(int i = 1; i <= 200; i++) adj[i].clear();
        if(match >= k) return true;
        else return false;
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d %d %d", &n, &m, &k, &c);

                for(int i = 1; i <= n; i ++){
                        for(int j = 1; j <= m; j ++){
                                scanf("%d", &mat[i][j]);
                        }
                }

                int lo = 0, hi = 2e9, mid, ans = 0;
                while(lo <= hi){
                        mid = (lo + hi) / 2;

                        if(ok(mid)){
                                ans = mid;
                                hi = mid - 1;
                        }
                        else lo = mid + 1;
                }
                printf("%d\n", ans);
        }

        return 0;
}

