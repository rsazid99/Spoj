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
unordered_map<int, bool> ase;
int n;
int main()
{
        int last = 1;
        ase[last] = 1;
        for(int i = 1; i < 20000; i ++){
                int num = (6 * i) + last;
                ase[num] = 1;
                last = num;
        }

        while(scanf("%d", &n)){
                if(n == -1) break;
                if(ase.find(n) == ase.end()) printf("N\n");
                else printf("Y\n");

        }
        return 0;
}
