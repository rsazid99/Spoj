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

int mark[10010], cnt[10010];
vector<int> v;
void sieve(int n)
{
        mark[1] = mark[0] = 1;
        for(int i = 2; i <= n; i ++){
                if(!mark[i]){
                        for(int j = i + i; j <= n; j += i) mark[j] = 1, cnt[j] ++;
                }
        }
        for(int i = 1; i <= n; i ++){
                if(cnt[i] >= 3) v.push_back(i);
        }
}

int m;

int main()
{
        int t;
        scanf("%d", &t);
        sieve(5000);
        while(t --){
                scanf("%d", &m);
                printf("%d\n", v[m - 1]);
        }
        return 0;
}



