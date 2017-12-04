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

typedef pair<ll, int> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n;
ll a[maxn], b[maxn], d[maxn];


int main()
{

        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);
                priority_queue<ii, vector<ii>, greater<ii> > pq;
                for(int i = 1; i <= n; i ++){
                        scanf("%lld %lld %lld", &a[i], &b[i], &d[i]);
                        pq.push(ii(b[i] - d[i], i));
                }

                long double ans = 0.00;

                while(!pq.empty()){
                        ii u = pq.top();
                        pq.pop();

                        if(u.first <= 0) continue;
                        else{
                                ans += (long double) u.first / a[u.second];
                        }
                }

                printf("%.2Lf\n", ans);



        }

        return 0;
}
