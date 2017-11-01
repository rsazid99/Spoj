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

int n, x, y, z, visited[maxn];
vector<ii> adj[maxn];
ll dist[maxn];

pair<ll, int>  dijkstra(int st)
{
        memset(dist, -1, sizeof dist);
        memset(visited, 0, sizeof visited);

        priority_queue<pair<ll, ll> > pq;
        pq.push(make_pair(0, st));
        dist[st] = 0;
        ll mx = -1;
        int node = 0;

        while(!pq.empty()){
                pair<ll, ll> u = pq.top();
                pq.pop();

                if(dist[u.second] != u.first) continue;
                if(dist[u.second] > mx){
                        mx = dist[u.second];
                        node = u.second;
                }
                visited[u.second] = 1;

                for(int i = 0; i < adj[u.second].size(); i ++){
                        int v = adj[u.second][i].first;
                        ll di = adj[u.second][i].second;
                        if(dist[v] < dist[u.second] + di && !visited[v]){
                                dist[v] = dist[u.second] + di;
                                pq.push(make_pair(dist[v], v));
                        }
                }
        }
        return make_pair(mx, node);

}

int main()
{

        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i < n;i ++){
                        scanf("%d %d %d", &x, &y, &z);
                        adj[x].push_back(ii(y, z));
                        adj[y].push_back(ii(x, z));
                }

                pair<ll, int> res = dijkstra(1);
                pair<ll, int> ans = dijkstra(res.second);

                printf("%lld\n", ans.first);

                for(int i = 0;i <= n; i ++) adj[i].clear();

        }


        return 0;;
}
