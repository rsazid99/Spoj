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

ll sum, x;
int n;

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);
                sum = 0;
                for(int i = 1; i <= n; i ++){
                        scanf("%lld", &x);
                        sum = (sum + x) % n;
                }

                if(sum % n == 0) printf("YES\n");
                else printf("NO\n");
        }

        return 0;
}
