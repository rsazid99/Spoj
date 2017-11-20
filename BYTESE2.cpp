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

int idx[1000000], x, y, n, arr[210];
set<int> se;
vector<ii> qe;


int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 0; i < n; i ++){
                        scanf("%d %d", &x, &y);
                        qe.push_back(ii(x, y));
                        se.insert(x);
                        se.insert(y);
                }
                memset(arr, 0, sizeof arr);

                int id = 0;
                set<int> :: iterator it = se.begin();
                for( ; it != se.end(); it ++){
                        idx[*it] = ++id;
                }
                int mx = 0;
                for(int i = 0; i < n; i ++){
                        x = qe[i].ff, y = qe[i].ss;
                        arr[idx[x]] ++;
                        arr[idx[y] + 1] --;
                        mx = max(mx, max(idx[x], idx[y] + 1));

                }

                int ans = 0, go = 0;
                for(int i = 1; i <= mx; i ++){
                        go += arr[i];
                        ans = max(go, ans);
                }
                printf("%d\n", ans);
                se.clear();
                qe.clear();

        }

        return 0;
}
