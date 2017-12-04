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
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n;
ll a, b, c, F[2 * maxn];


int find_mid(int d)
{
        if(d == 1) return 1;
        else return (d / 2) + (d % 2 > 0);
}


int main(){

        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%lld %lld %lld %d", &a, &b, &c, &n);
                priority_queue<int> left;
                priority_queue<int, vector<int>, greater<int> > right;
                F[1] = 1;
                left.push(1);
                int l = 1, r = 0;
                ll sum = 1;
                for(int i = 2; i <= n; i ++){
                        F[i] = ((a * 1LL) * left.top() + b * i + c) % mod;
                        sum += F[i];
                        left.push(F[i]);
                        l ++;

                        while(l > r){
                                int val = left.top();
                                left.pop();
                                right.push(val);
                                l --;
                                r ++;
                        }

                        while(r > l){
                                int val = right.top();
                                right.pop();
                                left.push(val);
                                r --;
                                l ++;
                        }
                        /*while(!left.empty() && !right.empty() && left.top() > right.top()){
                                int val1 = left.top();
                                int val2 = right.top();
                                left.pop();
                                right.pop();
                                left.push(val2);
                                right.push(val1);
                        }
                        */

                }
                printf("%lld\n", sum);
        }

        return 0;
}

