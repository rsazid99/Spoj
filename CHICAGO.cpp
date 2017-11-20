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

int n, m, x, y, p;
vector<ii> adj[110];
double prob[110];


double bfs()
{
        priority_queue<pair<double, int> > pq;
        pq.push(make_pair(1.00, 1));
        prob[1] = 1;

        while(!pq.empty()){
                pair<double, int> u = pq.top();
                pq.pop();

                if(prob[u.second] > u.first || prob[u.second] < u.first) continue;

                for(int i = 0; i < adj[u.second].size(); i ++){
                        int v = adj[u.second][i].first;
                        int pro = adj[u.second][i].second;
                        if(prob[v] < (prob[u.second] * pro) / 100){
                                prob[v] = (prob[u.second] * pro) / 100;
                                pq.push(make_pair(prob[v], v));
                        }
                }
        }
        return prob[n] * 100;
}

int main()
{
        while(scanf("%d", &n) && n){

                scanf("%d", &m);

                for(int i = 1; i <= m; i ++){
                        scanf("%d %d %d", &x, &y, &p);
                        adj[x].push_back(ii(y, p));
                        adj[y].push_back(ii(x, p));
                }

                memset(prob, 0, sizeof prob);

                printf("%.7f percent\n", bfs());

                for(int i = 1; i <= n; i ++){
                        adj[i].clear();
                }
        }

        return 0;
}
