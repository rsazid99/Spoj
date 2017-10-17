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

const ll MOD = 998244353;

ii exEuclid(ll a, ll b) {
        if(b == 0) return ii(1, 0);
        else {
                ii r = exEuclid(b, a%b);
                return ii(r.ss, r.ff-r.ss*(a/b));
        }
}

int modInv(ll a, ll m) { ii ret = exEuclid(a, m); return ((ret.ff % m) + m ) % m; }

ll G, T, A, D;
vector<ll> v;

int main()
{
        ll last = 1;
        for(int i = 0; i <= 34; i ++){
                v.push_back(last);
                last *= 2;
        }
        while(true){
                scanf("%lld %lld %lld %lld", &G, &T, &A, &D);
                if(G == -1) break;

                ll team = (G * A) + D;

                ll lo =  lower_bound(v.begin(), v.end(), team) - v.begin();

                ll ans = v[lo] - team;

                ll tot = (((T - 1) * T) / 2)* G;

                ll tmp = v[lo];
                while(tmp){
                        tmp /= 2;
                        tot += tmp;
                }

                printf("%lld*%lld/%lld+%lld=%lld+%lld\n", G, A, T, D, tot, ans);
        }
        return 0;
}


