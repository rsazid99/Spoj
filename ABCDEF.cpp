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

typedef pair<int, int> ii;

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

int n, arr[110];
unordered_map<ll, int> dp;

int main()
{
        scanf("%d", &n);
        for(int i = 1; i <= n;i ++){
                scanf("%d", &arr[i]);
        }

        for(int i = 1; i <= n; i ++){
                for(int j = 1; j <= n; j ++){
                        for(int k = 1; k <= n; k ++){
                                ll d = arr[i];
                                ll e = arr[j];
                                ll f =arr[k];
                                if(d != 0){
                                        dp[d * (f + e)] ++;
                                }
                        }
                }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
                for(int j = 1; j <= n; j ++){
                        for(int k = 1; k <= n; k ++){
                                ll a = arr[i];
                                ll b = arr[j];
                                ll c = arr[k];
                                if(dp[(a * b) + c] > 0) cnt += dp[(a * b) + c];
                        }
                }
        }

        printf("%d\n", cnt);

        return 0;
}


