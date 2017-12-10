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

int n, a, b, d;
vector<iii> v;


int main()
{

        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%d %d %d", &a, &b, &d);
                        v.push_back(iii(d, ii(b, a)));
                }
                sort(v.begin(), v.end());

                double ans = 0.00;
                int Time = 0;
                priority_queue<ii> pq;
                for(int i = 0; i < n; i ++){
                        Time += v[i].second.first;
                        pq.push(ii(v[i].second.second, v[i].second.first));
                        while(Time > v[i].first){
                                int t = Time - v[i].first;
                                ii u = pq.top();
                                pq.pop();

                                if(u.second >= t){
                                        u.second -= t;
                                        ans += (double) t / u.first;
                                        Time = v[i].first;
                                        pq.push(u);
                                }
                                else{
                                        Time -= u.second;
                                        ans += (double) u.second / u.first;
                                        u.second = 0;
                                }
                        }
                }
                printf("%.2f\n", ans);
                v.clear();

        }

        return 0;
}
