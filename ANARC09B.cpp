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


int main()
{
        int w, h;
        while(scanf("%d %d", &w, &h)){
                if(w == 0 && h == 0) break;
                int gc = __gcd(w, h);
                w /= gc;
                h /= gc;
                printf("%lld\n", (1LL * w) * h);
        }
        return 0;
}
