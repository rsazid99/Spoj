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

int x, n, nise[1010], dise[1010];

int main()
{
        int tt = 1;
        while(true){
                scanf("%d", &n);
                if(n == 0) break;
                int a = 0, b = 0;
                memset(nise, 0, sizeof nise);
                memset(dise, 0, sizeof dise);
                for(int i = 1; i <= n; i ++){
                        for(int j = 1; j <= n; j ++){
                                scanf("%d", &x);
                                dise[i] += x;
                                nise[j] += x;
                                a += x;
                        }
                }

                for(int i = 1; i <= n; i ++){
                        if(nise[i] > dise[i]){
                                nise[i] -= dise[i];
                                dise[i] = 0;
                        }
                        else{
                                dise[i] -= nise[i];
                                nise[i] = 0;
                        }
                }
                for(int i = 1; i <= n; i ++){
                        b += nise[i];
                }
                printf("%d. %d %d\n", tt ++, a, b);

        }

        return 0;
}
