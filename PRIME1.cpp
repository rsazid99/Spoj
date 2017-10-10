//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
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

const ll MOD = 998244353;

ii exEuclid(ll a, ll b) {
        if(b == 0) return ii(1, 0);
        else {
                ii r = exEuclid(b, a%b);
                return ii(r.ss, r.ff-r.ss*(a/b));
        }
}

int modInv(ll a, ll m) { ii ret = exEuclid(a, m); return ((ret.ff % m) + m ) % m; }

int mark[1000010], arr[1000010];
vector<int> prime;
void sieve(int n)
{
        mark[1] = mark[0] = 1;

        for(int i = 4; i <= n; i += 2) mark[i] = 1;

        int limit = sqrt(n + 2);
        prime.push_back(2);
        for(int i = 3; i <= n; i ++){
                if(!mark[i]){
                        prime.push_back(i);
                        if(i <= limit){
                                for(int j = i * i; j <= n; j += 2 * i) mark[j] = 1;
                        }
                }
        }
}

void segmented_sieve(ll a, ll b)
{
        if(a == 1) a ++;
        memset(arr, 0, sizeof arr);
        ll sq = sqrt(b);

        for(int i = 0; i < prime.size() && prime[i] <= sq; i ++){
                ll p = prime[i];
                ll j = p * p;
                if(j < a) j = ((a + p - 1) / p) * p;
                for( ; j <= b; j += p){
                        arr[j - a] = 1;
                }
        }
        for(ll i = a; i <= b; i ++){
                if(!arr[i - a]) printf("%lld\n", i);
        }
}


int main()
{
        sieve(1000000);

        int t;
        scanf("%d", &t);

        while(t --){
                ll a, b;
                scanf("%lld %lld", &a, &b);
                segmented_sieve(a, b);
                printf("\n");
        }

        return 0;
}


