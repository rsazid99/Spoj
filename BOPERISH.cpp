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

int n, x, mx;
vector<int> v;

int main()
{

        while(scanf("%d", &n) && n){
                mx = 0;
                for(int i = 0; i < n; i ++){
                        scanf("%d", &x);
                        v.push_back(x);
                        mx = max(mx, x);
                }
                sort(v.begin(), v.end());

                int ans = 0;

                for(int i = 0; i <= n; i ++){
                        int eq = 0, ls = 0, gt = 0;
                        for(int j = 0; j < n; j ++){
                                if(v[j] == i) eq ++;
                                if(v[j] > i) gt ++;
                                if(v[j] < i) ls ++;
                        }
                        bool b = false;
                        if(gt == i){
                                ans = i;
                                break;
                        }
                        if(gt < i){
                                if(eq >= ( i - gt)){
                                        ans = i;
                                        b = true;
                                }
                        }
                        if(b) break;
                }
                printf("%d\n", ans);
                v.clear();
        }

}
