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
char name[200];
int arr[2 * maxn], n;
string fake;
int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                getline(cin, fake);
                scanf("%d", &n);
                for(int i = 0; i < n; i ++){
                        scanf("%s %d", name, &arr[i]);;
                }
                sort(arr, arr + n);

                ll ans = 0;
                for(int i = 0; i < n; i ++) ans += abs(arr[i] - (i + 1));

                printf("%lld\n", ans);
        }

        return 0;
}
