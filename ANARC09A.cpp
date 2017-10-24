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

char s[2010];
int n;

int main()
{
        int tt = 1;
        while(scanf("%s", s)){
                if(s[0] == '-') break;
                n = strlen(s);
                stack<char> stk;
                for(int i = 0; i < n; i ++){
                        if(stk.empty()){
                                stk.push(s[i]);
                        }
                        else if(stk.top() != s[i] && stk.top() == '{') stk.pop();
                        else stk.push(s[i]);
                }

                string r;
                while(!stk.empty()){
                        r += stk.top();
                        stk.pop();
                }
                reverse(r.begin(), r.end());
                int ans = 0;
                for(int i = 0; i < r.size(); i += 2){
                        if(r[i] == '}' && r[i + 1] == '{') ans += 2;
                        else if((r[i] == '{' || r[i] == '}') && r[i] == r[i + 1]) ans ++;
                }
                printf("%d. %d\n", tt ++, ans);

        }
        return 0;
}
