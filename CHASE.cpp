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

struct point{
        int x, y;
};

point arr[2210];
int n;
double res[2210];

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%d %d", &arr[i].x, &arr[i].y);
                }
                int ans = 0;
                for(int i = 1; i < n; i ++){
                        int ver = 0, hoz = 0, idx = 0;
                        for(int j = i + 1; j <= n; j ++){
                                if(arr[j].x == arr[i].x) ver ++;
                                else if(arr[j].y == arr[i].y) hoz ++;
                                else{
                                        res[idx ++] = (double)(arr[i].y - arr[j].y) / (arr[i].x - arr[j].x);
                                }
                        }
                        sort(res, res + idx);
                        int more = 0;
                        for(int j = 0; j < idx; j ++){
                                if(j == 0 || res[j - 1] < res[j]) more = 1;
                                else more ++;
                                ans = max(ans, more);
                        }
                        ans = max(ans, max(ver, hoz));
                }
                printf("%d\n", ans);
        }
}
