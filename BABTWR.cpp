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

int n, x, y, z;
ll mx;
priority_queue<iii> pq;
vector<iii>v;
ll dp[300];

int main()
{
        while(scanf("%d", &n) && n){
                for(int i = 0; i < n; i ++){
                        scanf("%d %d %d", &x, &y, &z);
                        pq.push(iii(x, ii(y, z)));
                        pq.push(iii(x, ii(z, y)));
                        pq.push(iii(y, ii(x, z)));
                        pq.push(iii(y, ii(z, x)));
                        pq.push(iii(z, ii(x, y)));
                        pq.push(iii(z, ii(y, x)));
                }
                mx = 0;
                while(!pq.empty()){
                        v.push_back(pq.top());
                        pq.pop();
                }

                memset(dp, 0, sizeof dp);

                mx =  0;
                for(int i = 0; i < v.size(); i ++){
                        dp[i] = v[i].ss.ss;
                        for(int j = 0; j < i; j ++){
                                if(v[i].ff < v[j].ff && v[i].ss.ff < v[j].ss.ff){
                                        dp[i] = max(dp[i], dp[j] + v[i].ss.ss);
                                }
                        }
                        mx = max(mx, dp[i]);
                }
                printf("%lld\n", mx);
                v.clear();
        }

        return 0;
}
