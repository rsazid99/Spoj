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

int a, b, n, m, s;

int main()
{
        while(true){
                scanf("%d %d %d %d %d", &a, &b, &s, &m, &n);
                if(a == 0 && b == 0 && s == 0 && m == 0 && n == 0) break;
                double dsin = (double) b * n;
                double dcos = (double) a * m;
                double theta = atan2(dsin, dcos);
                double d = dsin * sin(theta) + dcos * cos(theta);
                printf("%.2f %.2f\n", (theta * 180) / (acos(-1)), d / s);

        }

        return 0;
}
