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

char s[1010], n;
int visited[2010][2010];

int main()
{
        int t = 1;
        while(true){
                scanf("%s", s);
                if(s[0] == 'Q') break;
                n = strlen(s);
                memset(visited, 0, sizeof visited);
                int x = 1001, y = 1001;
                visited[x][y] = 1;
                int cnt = 0;
                for(int i = 0; s[i] != 'Q'; i ++){
                        if(s[i] == 'U') y ++;
                        if(s[i] == 'D') y --;
                        if(s[i] == 'L') x --;
                        if(s[i] == 'R') x ++;
                        if(visited[x][y] == 1) cnt ++;
                        visited[x][y] = 1;

                }
                printf("%d\n", cnt);

        }
        return 0;
}
