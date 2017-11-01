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
char g[305][305];
int r, c, matr[305][305], matc[305][305];
int n;

int level[100010], mate[100010];
vector<int>adj[100010];

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

int matching()
{
        memset(mate, -1, sizeof mate);
        memset(level, 0, sizeof level);

        int match = 0;

        while(bfs()){
                for(int i = 1; i <= n; i ++){
                        if(mate[i] < 0 && dfs(i)) match++;
                }
        }
        for(int i = 1; i <= 100000; i++) adj[i].clear();
        return match;
}

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d\n", &r, &c);

                for(int i = 0; i < r; i ++){
                        for(int j = 0; j < c; j ++){
                                g[i][j] = getchar();
                                getchar();
                        }
                }
                int idx = 0;
                bool b1;
                for(int i = 0; i < r; i ++){
                        bool b1 = false;
                        for(int j = 0; j < c; j ++){
                                if(g[i][j] == 'H' || g[i][j] == 'D'){
                                        if(!b1){
                                                b1 = true;
                                                idx ++;
                                        }
                                        matr[i][j] = idx;
                                }
                                else b1 = false;
                        }
                }
                n = idx;


                for(int j = 0; j < c; j ++){
                        b1 = false;
                        for(int i = 0; i < r; i ++){
                                if(g[i][j] == 'H' || g[i][j] == 'D'){
                                        if(!b1){
                                                b1 = true;
                                                idx ++;
                                        }
                                        matc[i][j] = idx;
                                }
                                else b1 = false;
                        }
                }

                for(int i = 0; i < r; i ++){
                        for(int j = 0; j < c; j ++){
                                if(g[i][j] == 'H'){
                                        adj[matr[i][j]].push_back(matc[i][j]);
                                        adj[matc[i][j]].push_back(matr[i][j]);
                                }
                        }
                }
                printf("%d\n", matching());

        }

        return 0;
}
