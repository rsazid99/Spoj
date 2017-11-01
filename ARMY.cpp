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

int n, m, x;


int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);
                priority_queue<int, vector<int> , greater<int> > a, b, tot;
                for(int i = 0; i < n; i ++){
                        scanf("%d", &x);
                        a.push(x);
                        tot.push(x);
                }

                for(int i = 0; i < m; i ++){
                        scanf("%d", &x);
                        b.push(x);
                        tot.push(x);
                }

                while(!a.empty() && !b.empty()){
                        int u = tot.top();
                        tot.pop();

                        if(a.top() == u && b.top() == u){
                                b.pop();
                        }
                        else if(a.top() == u && b.top() != u) a.pop();
                        else if(b.top() == u && a.top() != u) b.pop();
                }

                if(a.empty() && b.empty()) printf("uncertain\n");
                else if(b.empty()) printf("Godzilla\n");
                else printf("MechaGodzilla\n");
        }

        return 0;
}
