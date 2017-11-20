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

char conso[30][100], vowel[30][200], arr[200], brr[200];
char vow[5] = {'a', 'e', 'i', 'o', 'u'};
char con[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
int MOD[30], cnt[30], n;
char s[50010];
bool is_vow(char ch)
{
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        else return false;
}

int main()
{
        for(int i = 0; i < 105;i ++){
                arr[i] = vow[i % 5];
                brr[i] = con[i % 21];
                vowel[arr[i] - 'a'][MOD[arr[i] - 'a']] = brr[i];
                conso[brr[i] - 'a'][MOD[brr[i] - 'a']] = arr[i];
                MOD[arr[i] - 'a'] ++;
                MOD[brr[i] - 'a'] ++;
        }


        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%s", s);
                memset(cnt, 0, sizeof cnt);
                string ans;
                n = strlen(s);
                for(int i = 0; i < n; i ++){
                        if(is_vow(s[i])) ans += vowel[s[i] - 'a'][cnt[s[i] - 'a'] % MOD[s[i] - 'a']];
                        else ans += conso[s[i] - 'a'][cnt[s[i] - 'a'] % MOD[s[i] - 'a']];
                        cnt[s[i] - 'a'] ++;
                }
                cout << ans << endl;
        }

        return 0;
}
