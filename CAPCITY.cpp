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

int n, m, x, y;
vector<int> adj[maxn], radj[maxn], ans, cadj[maxn];
int visited[maxn], com[maxn], cc, cnt, outdeg[maxn];
stack<int> stk;

void dfs1(int u)
{
        visited[u] = 1;
        for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i];
                if(!visited[v]) dfs1(v);
        }
        stk.push(u);
}

void dfs2(int u)
{
        visited[u] = 2;
        com[u] = cc;
        for(int i = 0; i < radj[u].size(); i ++){
                int v = radj[u][i];
                if(visited[v] != 2) dfs2(v);
        }

}

void dfs3(int u)
{
        visited[u] = 3;
        for(int i = 0; i < cadj[u].size(); i ++){
                int v = cadj[u][i];
                if(visited[v] != 3) dfs3(v);
        }
}

int main()
{

        scanf("%d %d", &n, &m);

        for(int i = 1; i <= m; i ++){
                scanf("%d %d", &x, &y);
                adj[x].push_back(y);
                radj[y].push_back(x);
        }

        for(int i = 1; i <= n; i ++){
                if(!visited[i]) dfs1(i);
        }

        while(!stk.empty()){
                int v = stk.top();
                stk.pop();

                if(visited[v] != 2){
                        cc ++;
                        dfs2(v);
                }
        }

        for(int i = 1; i <= n; i ++){
                for(int j = 0; j < adj[i].size(); j ++){
                        int v = adj[i][j];
                        if(com[i] != com[v]){
                                cadj[com[i]].push_back(com[v]);
                                cadj[com[v]].push_back(com[i]);
                                outdeg[com[i]] ++;
                        }
                }
        }

        for(int i = 1; i <= cc; i++){
                if(visited[i] != 3){
                        cnt ++;
                        dfs3(i);
                }
        }
        for(int i = 1; i <= n; i ++){
                if(!outdeg[com[i]]) ans.push_back(i);
        }
        if(cnt == 1){
                printf("%d\n", ans.size());
                for(int i = 0; i < ans.size(); i ++)printf("%d ", ans[i]);
                printf("\n");
        }
        else printf("0\n");
        return 0;
}
