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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

ll po, bet, pn;

int main()
{
        while(scanf("%lld %lld %lld", &po, &bet, &pn) && po){
                int n = 0;
                if(pn == 0){
                        if(bet > po) n = -1;
                        else{
                                n += (po / (3 * bet));
                                po %= (3 * bet);

                                n += (po / (2 * bet));
                                po %= (2 * bet);

                                n += po / bet;
                        }

                }
                else if(pn < po){
                        po = po - pn;
                        n += (po / (3 * bet));
                        po %= (3 * bet);

                        n += (po / (2 * bet));
                        po %= (2 * bet);

                        n += po / bet;
                        po %= bet;

                        if(po > 0) n = -1;
                }
                else if(pn > po){
                        pn = pn - po;
                        n += (pn / (3 * bet));
                        pn %= (3 * bet);

                        n += (pn / (2 * bet));
                        pn %= (2 * bet);

                        n += pn / bet;
                        pn %= bet;

                        if(pn > 0) n = -1;
                }

                if(n == -1) printf("No accounting tablet\n");
                else printf("%d\n", n);
        }

        return 0;
}
