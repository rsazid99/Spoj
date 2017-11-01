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
char s1[2 * maxn], s2[2 * maxn];
int n;
int main()
{
        while(scanf("%s %s", s1, s2)){
                if(s1[0] == '*') break;

                int ans = 0;
                n = strlen(s1);
                bool st = false;
                for(int i = 0;i < n; i ++){
                        if(!st){
                                if(s1[i] == s2[i]) continue;
                                else{
                                        ans ++;
                                        st = true;
                                }
                        }
                        else{
                                if(s1[i] == s2[i]){
                                        st = false;
                                }
                                else continue;
                        }
                }
                printf("%d\n", ans);
        }

        return 0;
}
