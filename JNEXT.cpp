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

int n, arr[1000010], cnt[11];
vector<int> v;

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%d", &arr[i]);
                }

                memset(cnt, 0, sizeof cnt);

                int mx = arr[n];
                cnt[arr[n]] ++;
                bool flag = false;
                for(int i = n - 1; i > 0 ; i --){
                        cnt[arr[i]] ++;
                        if(arr[i] < mx){
                                for(int j = arr[i] + 1; j <= 9; j ++){
                                        if(cnt[j]){
                                                arr[i] = j;
                                                cnt[j] --;
                                                flag = true;
                                                break;

                                        }
                                }
                                if(flag){
                                        int idx = i;
                                        for(int j = 0; j < 10; j ++){
                                                for(int k = 1; k <= cnt[j]; k ++){
                                                        arr[++ idx] = j;
                                                }
                                        }
                                }
                        }
                        else mx = max(arr[i], mx);
                        if(flag) break;
                }
                if(!flag) printf("-1\n");
                else{
                        for(int i = 1; i <= n; i ++) printf("%d", arr[i]);
                        printf("\n");
                }

        }
}

