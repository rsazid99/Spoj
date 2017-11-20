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
int n, x, y, m, color[2010];
vector<int> adj[2010];
bool flag;

void dfs(int u, int from, int clr)
{
        color[u] = clr;

        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(color[v] == -1){
                        dfs(v, u, 1 - clr);
                }
                else{
                        if(color[v] == clr) flag = false;
                }
        }
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                }
                memset(color, -1, sizeof color);
                flag = true;
                for(int i = 1; i <= n; i ++)
                        if(color[i] == -1) dfs(i, -1, 1);
                printf("Scenario #%d:\n", tt ++);
                if(flag) printf("No suspicious bugs found!\n");
                else printf("Suspicious bugs found!\n");

                for(int i = 1; i <= n; i ++) adj[i].clear();
        }

        return 0;
}



