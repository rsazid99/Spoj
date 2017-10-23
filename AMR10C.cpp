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

int m;

int mark[1000010];
vector<int> prime, res;
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

void find_pf(int n)
{
        int idx = 0, pf = prime[idx];
        res.clear();
        while(pf * pf <= n){
                int cnt = 0;
                while(n % pf == 0){
                        cnt ++;
                        n /= pf;
                }
                if(cnt > 0) res.push_back(cnt);
                pf = prime[++ idx];
        }
        if(n > 1) res.push_back(1);
}


int main()
{
        int t;
        scanf("%d", &t);
        sieve(1000000);
        while(t --){
                scanf("%d", &m);
                find_pf(m);
                int ff = 0, ss = 0;
                sort(res.begin(), res.end());
                if(res.size() > 0) ff = res.back();
                res.pop_back();
                if(res.size() > 0) ss = res.back();
                int ans = (ff - ss) + ss;
                printf("%d\n", ans);
        }
        return 0;
}



