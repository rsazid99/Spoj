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

char s1[2 * maxn], s2[2 * maxn];
string s, r;

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%s %s", s1, s2);
                int sz1 = strlen(s1), sz2 = strlen(s2);
                s = "", r = "";
                if(sz1 >= sz2){
                        for(int i = 0; i < sz1; i ++){
                                s += s1[i];
                        }
                        for(int i = 0; i < sz2; i ++){
                                r += s2[i];
                        }
                }
                else{
                        for(int i = 0; i < sz2; i ++){
                                s += s2[i];
                        }
                        for(int i = 0; i < sz1; i ++){
                                r += s1[i];
                        }
                }

                string ans;

                int cary = 0;
                int i = 0;
                for(; i < r.size();i ++){
                        int a = s[i] - '0';
                        int b = r[i] - '0';
                        int num = a + b + cary;
                        a = num % 10;
                        b = num / 10;
                        if(b > 0){
                                if((ans.size() > 0 && !a) || a > 0 ) ans += (a + '0');
                                cary = b;
                        }
                        else{
                                if((ans.size() > 0 && !a) || a > 0 ) ans += (a + '0');
                                cary = 0;
                        }
                }
                for( ; i < s.size(); i ++){
                        int num = (s[i] - '0') + cary;
                        int a = num % 10;
                        int b = num / 10;
                        if(b > 0){
                                if((ans.size() > 0 && !a) || a > 0 ) ans += (a + '0');
                                cary = b;
                        }
                        else{
                                if((ans.size() > 0 && !a) || a > 0 ) ans += (a + '0');
                                cary = 0;
                        }
                }
                if(cary > 0) ans += (cary + '0');
                cout << ans <<"\n";
        }
        return 0;
}




