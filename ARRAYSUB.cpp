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

int n, arr[maxn], k;
multiset<int> se;
int main()
{

        scanf("%d", &n);

        for(int i = 1; i <= n; i ++){
                scanf("%d", &arr[i]);
        }
        scanf("%d", &k);
        arr[0] = 1;
        for(int i = 0; i <= n; i ++){
                if(i < k)se.insert(arr[i]);
                else{
                        se.insert(arr[i]);
                        se.erase(se.find(arr[i - k]));
                        printf("%d ", *se.rbegin());
                }
        }
        cout << endl;


}
