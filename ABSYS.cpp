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


string fake, s;

bool ok(string r)
{
        for(int i = 0; i < r.size(); i ++){
                if(r[i] >= '0' && r[i] <= '9') continue;
                else return false;
        }
        return true;
}

int to_int(string r)
{
        int ret = 0;
        for(int i = 0; i < r.size(); i ++){
                ret = (ret * 10) + (r[i] - '0');
        }
        return ret;
}

int main()
{
        int t;
        scanf("%d", &t);
        getchar();

        while(t --){
                getline(cin, fake);
                getline(cin, s);
                stringstream ss(s);
                bool b1 = true, b2 = true, b3 = true;
                int a = 0, b = 0, c = 0;
                string tmp;
                ss >> tmp;
                if(!ok(tmp)) b1 = false;
                else a = to_int(tmp);

                ss >> tmp ;
                ss >> tmp;

                if(!ok(tmp)) b2 = false;
                else b = to_int(tmp);

                ss >> tmp;
                ss >> tmp;

                if(!ok(tmp)) b3 = false;
                else c = to_int(tmp);

                if(!b1){
                        printf("%d + %d = %d\n", c - b, b, c);
                }
                else if(!b2){
                        printf("%d + %d = %d\n", a, c - a, c);
                }
                else {
                        printf("%d + %d = %d\n", a, b, a + b);
                }
        }


        return 0;
}


