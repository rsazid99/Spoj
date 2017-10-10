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

int n, c, x;
vector<int> v;

bool ok(int d)
{
        int cnt = c - 1;
        int last = v[0] + d;
        while(cnt){
                int lo = lower_bound(v.begin(), v.end(), last) - v.begin();
                if(lo == v.size()) break;
                last = v[lo] + d;
                cnt --;
        }
        if(cnt > 0) return false;
        else return true;
}

int main()
{

        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &c);

                for(int i = 1; i <= n;i ++){
                        scanf("%d", &x);
                        v.push_back(x);
                }

                sort(v.begin(), v.end());

                int lo = 1, hi = 1e9, mid = 0, ans = 0;

                while(lo <= hi){
                        mid = (lo + hi) / 2;
                        if(ok(mid)){
                                ans = mid;
                                lo = mid + 1;
                        }
                        else hi = mid - 1;
                }
                printf("%d\n", ans);
                v.clear();
        }




        return 0;
}


