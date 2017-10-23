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

char s[30], n;
int dp[25][226][226];

int dpfun(int i, int last, int sum)
{
        if(i == n){
                if(sum >= last) return 1;
                else return 0;
        }

        if(dp[i][last][sum] != -1) return dp[i][last][sum];

        int ret = 0;

        if(last <= sum && i > 0) ret += dpfun(i + 1, sum, s[i] - '0');
        ret += dpfun(i + 1, last, sum + (s[i] - '0'));

        return dp[i][last][sum] = ret;
}

int main()
{

        int tt = 1;
        while(true){
               scanf("%s", s);
               if(s[0] == 'b') break;
               memset(dp, -1, sizeof dp);
               n = strlen(s);
               int ans = dpfun(0, 0, 0);
               printf("%d. %d\n", tt ++, ans);
        }

        return 0;
}



