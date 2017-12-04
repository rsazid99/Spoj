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

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                int l = 0, r = 0;
                priority_queue<int> left;
                priority_queue<int, vector<int>, greater<int> > right;
                while(scanf("%d", &n)){
                        if(!n) break;

                        if(n != -1){
                                left.push(n);
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

                        }
                        else{
                                printf("%d\n", left.top());
                                left.pop();
                                l --;

                                while(r > l){
                                        int val = right.top();
                                        right.pop();
                                        left.push(val);
                                        r --;
                                        l ++;
                                }

                        }
                }
        }
}
