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

ll arr[10];

int main()
{
        while(true){
                for(int i = 1; i <= 8; i ++){
                        scanf("%lld", &arr[i]);
                }
                if(arr[1] == -1) break;
                ll mx = 0;
                for(int i = 1; i <= 4; i ++){
                        if(arr[i] == 0) mx = max(mx, 0LL);
                        else mx = max(mx, (arr[i] / arr[i + 4]) + (arr[i] % arr[i + 4] > 0));
                }

                for(int i = 1; i <= 4; i ++){
                        if(i > 1) printf(" ");
                        printf("%lld", arr[i + 4] * mx - arr[i]);
                }
                printf("\n");
        }

        return 0;
}
