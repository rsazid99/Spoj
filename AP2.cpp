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

typedef pair<ll, ll> ii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

ll a, b, sum, n, d;

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%lld %lld %lld", &a, &b, &sum);

                n = (sum * 2) / (a + b);

                d = abs(b - a) / (n - 5);
                a = a - (2 * d);
                printf("%lld\n", n);
                for(int i = 1; i <= n; i ++){
                        if(i > 1) printf(" ");
                        printf("%lld", a + (i - 1) * d);
                }
                printf("\n");
        }

        return 0;
}
