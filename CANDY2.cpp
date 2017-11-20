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

int n;
int arr[5005], brr[5005], crr[5005];
vector<ii> va, vb, vc;
ll asum, bsum, csum;

int main()
{
        scanf("%d", &n);

        for(int i = 1; i <= n; i ++){
                scanf("%d %d %d", &arr[i], &brr[i], &crr[i]);
                va.push_back(ii(arr[i], i));
                vb.push_back(ii(brr[i], i));
                vc.push_back(ii(crr[i], i));
                asum += arr[i];
                bsum += brr[i];
                csum += crr[i];
        }

        sort(va.begin(), va.end());
        reverse(va.begin(), va.end());

        sort(vb.begin(), vb.end());
        reverse(vb.begin(), vb.end());

        sort(vc.begin(), vc.end());
        reverse(vc.begin(), vc.end());
        ll mn = LLONG_MAX;
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < min(5, n); i ++){
                for(int j = 0; j < min(5, n); j ++){
                        for(int k = 0; k < min(5, n); k ++){
                                if(va[i].ss == vb[j].ss || va[i].ss == vc[k].ss || vb[j].ss == vc[k].ss) continue;
                                ll cost = (asum - va[i].first) + (bsum - vb[j].first) + (csum - vc[k].first);
                                if(cost < mn){
                                        mn = cost;
                                        a = va[i].ss;
                                        b = vb[j].ss;
                                        c = vc[k].ss;
                                }

                        }
                }
        }

        printf("Bag for chocolate candies: %d\nBag for strawberry candies: %d\nBag for banana candies: %d\n", a - 1, b - 1, c - 1);

        return 0;
}
