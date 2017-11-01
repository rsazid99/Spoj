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

typedef pair<ll, ll> ii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}
string s, r, fake;

int main()
{
        int t;
        scanf("%d", &t);
        getchar();
        while(t --){
                getline(cin, fake);
                getline(cin, s);

                stringstream ss(s);
                ll val = 0;
                ss >> val;
                while(true){
                        ss >> r;
                        if(r == "=") break;
                        ll op  = 0;
                        ss >> op;
                        if(r == "+") val += op;
                        if(r == "-") val -= op;
                        if(r == "/") val /= op;
                        if(r == "*") val *= op;
                }
                printf("%lld\n", val);

        }

        return 0;
}
