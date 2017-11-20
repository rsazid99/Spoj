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

vector<int> vec;
int n;

int main()
{
        int t;
        scanf("%d", &t);
        vec.push_back(0);
        int last = 0;
        for(int i = 1; i <= 10000; i ++){
                last = last + i;
                vec.push_back(last);
        }

        while(t --){
                scanf("%d", &n);

                int lo = lower_bound(vec.begin(), vec.end(), n) - vec.begin();
                int po = n - vec[lo - 1];

                if(lo % 2 == 1){
                        printf("TERM %d IS %d/%d\n", n, lo - (po - 1), po);
                }
                else{
                        printf("TERM %d IS %d/%d\n", n, po, lo - (po - 1));
                }

        }

        return 0;
}
