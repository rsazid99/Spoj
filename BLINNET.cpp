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
int n, m, x, w, pa[10010];
char ch[20000];
vector<iii> edge;

int find(int a)
{
        if(pa[a] == a) return a;
        else return pa[a] = find(pa[a]);
}

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%s", ch);
                        scanf("%d", &m);
                        pa[i] = i;
                        for(int j = 1; j <= m; j ++){
                                scanf("%d %d", &x, &w);
                                edge.push_back(iii(w, ii(x, i)));
                        }
                }
                sort(edge.begin(), edge.end());
                int ans = 0, cnt = 0;
                for(int i = 0; i < edge.size(); i ++){
                        w = edge[i].ff;
                        int u = find(edge[i].ss.ff);
                        int v = find(edge[i].ss.ss);
                        if(u != v){
                                ans += w;
                                pa[u] = v;
                                cnt ++;
                        }
                        if(cnt == n - 1) break;
                }
                printf("%d\n", ans);
                edge.clear();
        }

        return 0;
}
