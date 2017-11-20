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
int n, m, x, y, visited[5005], cc, com[5005], outdeg[5005];
vector<int> adj[5005], radj[5005];
stack<int> stk;
vector<int> v;


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


int main()
{
        while(scanf("%d", &n) && n){
                scanf("%d", &m);

                for(int i = 0; i < m; i ++){
                        scanf("%d %d", &x, &y);
                        adj[x].push_back(y);
                        radj[y].push_back(x);
                }

                memset(visited, 0, sizeof visited);
                memset(com, 0, sizeof com);
                memset(outdeg, 0, sizeof outdeg);


                for(int i = 1; i <= n;i ++){
                        if(!visited[i]) dfs1(i);
                }
                cc = 0;
                while(!stk.empty() ){
                        int u =stk.top();
                        stk.pop();

                        if(visited[u] != 2){
                                cc ++;
                                dfs2(u);
                        }
                }
                for(int i = 1; i <= n; i ++){
                        for(int j = 0; j < adj[i].size(); j ++){
                                int v = adj[i][j];
                                if(com[i] != com[v]){
                                        outdeg[com[i]] ++;
                                }
                        }
                }
                for(int i = 1; i <= n; i ++){
                        if(!outdeg[com[i]]) v.push_back(i);
                }
                sort(v.begin(), v.end());

                for(int i = 0; i < v.size(); i ++){
                        if(i > 0) printf(" ");
                        printf("%d", v[i]);
                }
                printf("\n");
                v.clear();
                for(int i = 1; i <= n; i ++) adj[i].clear(), radj[i].clear();


        }

        return 0;
}
