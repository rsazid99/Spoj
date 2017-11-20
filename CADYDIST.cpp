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

int n, x;
vector<ll> stu, prc;

int main()
{
        while(scanf("%d", &n) && n){

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &x);
                        stu.push_back(x);
                }

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &x);
                        prc.push_back(x);
                }

                sort(stu.begin(), stu.end());
                reverse(stu.begin(), stu.end());
                sort(prc.begin(), prc.end());
                ll ans = 0;
                for(int i = 0; i < n; i ++){
                        ans += prc[i] * stu[i];
                }

                printf("%lld\n", ans);
                stu.clear();
                prc.clear();
        }

        return 0;
}
