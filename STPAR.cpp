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

int n, arr[1010];


int main()
{
        while(true){
                scanf("%d", &n);

                if(!n) break;

                for(int i = 1; i <= n; i ++) scanf("%d", &arr[i]);

                stack<int> stk;
                int idx = 1, ptr = 1;
                while(idx <= n){
                        stk.push(arr[idx]);
                        while(stk.size() && stk.top() == ptr){
                                stk.pop();
                                ptr ++;
                        }
                        idx ++;
                }
                if(stk.size() > 0) printf("no\n");
                else printf("yes\n");
        }
        return 0;
}
