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

char s[101];
int n, val;

int get_val(char ch)
{
        if(ch == 'H') return 1;
        if(ch == 'C') return 12;
        if(ch == 'O') return 16;
}



int main()
{

        scanf("%s", s);
        n = strlen(s);
        stack<int> stk;
        for(int i = 0; i < n; i ++){
                if(isdigit(s[i])){
                        val = stk.top();
                        stk.pop();
                        stk.push(val * (s[i] - '0'));
                }
                else if(s[i] == '(') stk.push(-1);
                else if(s[i] == ')'){
                        val = 0;
                        while(!stk.empty() && stk.top() != -1){
                                val += stk.top();
                                stk.pop();
                        }
                        stk.pop();
                        stk.push(val);
                }
                else stk.push(get_val(s[i]));

        }
        val = 0;
        while(!stk.empty()){
                val += stk.top();
                stk.pop();
        }
        printf("%d\n", val);

        return 0;
}
