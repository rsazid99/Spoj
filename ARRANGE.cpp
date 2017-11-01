//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
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
int n, x, cnt;
vector<int> v;

int main()
{
        int t;
        scanf("%d", &t);
        while(t --){
                scanf("%d", &n);
                cnt = 0;
                for(int i = 1; i <= n; i++){
                        scanf("%d", &x);
                        if(x == 1) cnt ++;
                        else v.push_back(x);
                }
                sort(v.begin(), v.end());
                reverse(v.begin(), v.end());

                while(cnt --){
                        printf("1 ");
                }
                if(v.size() == 2 && v[0] == 3 && v[1] == 2){
                        swap(v[0], v[1]);
                }
                for(int i = 0; i < v.size(); i++){
                        printf("%d ", v[i]);
                }
                printf("\n");
                v.clear();

        }

        return 0;
}
