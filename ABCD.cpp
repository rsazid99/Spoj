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

char s[maxn], r[maxn];

int n, cnt[4];


int main()
{
        scanf("%d\n", &n);
        scanf("%s", s);

        int sz = strlen(s);
        for(int i = 0; i < sz; i ++){
                cnt[s[i] - 'A'] ++;
        }

        for(int i = 0; i < 4;i ++){
                cnt[i] = n - cnt[i];
        }
        for(int i = 0; i < sz; i += 2){
                char ch1 = '\0', ch2 = '\0';
                for(int j = 0;j < 4;j ++){
                        if(s[i] == 'A' + j || s[i + 1] == 'A' + j) continue;
                        if(ch1 == '\0') ch1 = 'A'+ j;
                        else if(ch2 == '\0') ch2 = 'A'+ j;
                }
                if(i - 1 >= 0 && r[i - 1] == ch1) swap(ch1, ch2);
                r[i] = ch1, r[i + 1] = ch2;

        }
        printf("%s\n", r);


        return 0;
}

