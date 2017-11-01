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
string s, a;
int from , to;

int get_v(char ch)
{
        if(ch >= '0' && ch <= '9') return ch - '0';
        else return ch - 'A' + 10;
}

char get_char(int val)
{
        if(val >= 0 && val <= 9) return '0' + val;
        else return 'A' + (val - 10);
}

int main()
{
        while(true){
                getline(cin, s);
                if(cin.eof()) break;
                stringstream ss(s);

                ss >> a >> from >> to;
                int num = 0;
                for(int i = 0; i < a.size(); i ++){
                        num = num * from + (get_v(a[i]));
                }

                string tmp;
                while(num){
                        tmp += get_char(num % to);
                        num /= to;
                }
                reverse(tmp.begin(), tmp.end());
                if(tmp.size() > 7) printf("  ERROR\n");
                else{
                        int it = 0;
                        char ans[10];
                        memset(ans, '\0', sizeof ans);
                        for(int i = 0; i < 7; i ++){
                                if(7 - tmp.size() <= i){
                                        ans[i] = tmp[it];
                                        it ++;
                                }
                                else ans[i] = ' ';
                        }
                        printf("%s\n", ans);
                }
        }

        return 0;
}
