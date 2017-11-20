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

int dp[1010], arr[1010], n;

int main()
{
        arr[1] = 4, dp[1] = 5;
        for(int i = 2; i <= 1000; i ++){
                dp[i] = dp[i - 1] + arr[i - 1] + 3;
                arr[i] = arr[i - 1] + 3;
        }

        while(scanf("%d", &n)){
                if(n == 0) break;

                printf("%d\n", dp[n]);
        }
        return 0;
}
