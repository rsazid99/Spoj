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

char str[1000];
string s, r;
int n;

int str_int(string t)
{
        if(t == "063") return 0;
        if(t == "010") return 1;
        if(t == "093") return 2;
        if(t == "079") return 3;
        if(t == "106") return 4;
        if(t == "103") return 5;
        if(t == "119") return 6;
        if(t == "011") return 7;
        if(t == "127") return 8;
        if(t == "107") return 9;
}

string int_str(int val)
{
        if(val == 0) return "063";
        if(val == 1) return "010";
        if(val == 2) return "093";
        if(val == 3) return "079";
        if(val == 4) return "106";
        if(val == 5) return "103";
        if(val == 6) return "119";
        if(val == 7) return "011";
        if(val == 8) return "127";
        if(val == 9) return "107";
}

string to_String(ll v)
{
        string ret;
        while(v){
              ret += ((v % 10) + '0');
              v /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
}

int main()
{
        while(true){
                scanf("%s", str);
                if(str[0] == 'B') break;

                bool bo = false;
                n = strlen(str);
                s = "", r = "";
                for(int i = 0; i < n - 1; i ++){
                        if(str[i] == '+'){
                                bo = true;
                                continue;
                        }
                        if(!bo) s += str[i];
                        else r += str[i];
                }
                ll a = 0, b = 0;
                for(int i = 0; i < s.size(); i += 3){
                        string tmp;
                        tmp += s[i];
                        tmp += s[i + 1];
                        tmp += s[i + 2];
                        a = a * 10 + str_int(tmp);
                }

                for(int i = 0; i < r.size(); i += 3){
                        string tmp;
                        tmp += r[i];
                        tmp += r[i + 1];
                        tmp += r[i + 2];
                        b = b * 10 + str_int(tmp);
                }

                a = a + b;

                string ans;
                s = to_String(a);
                for(int i = 0; i < s.size(); i ++){
                        ans += int_str(s[i] - '0');
                }
                cout << str << ans << endl;
        }

        return 0;
}
