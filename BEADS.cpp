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
char ch[maxn];
string s;
int n, st;
int SA[maxn], tmpSA[maxn], RA[maxn], tmpRA[maxn], mp[maxn], cnt[maxn];


void counting_sort(int k)
{
        memset(cnt, 0, sizeof cnt);
        int mx = max(n, 300);

        for(int i = 0; i < n; i ++){
                cnt[RA[(i + k) % n]] ++;
        }

        int sum = 0;
        for(int i = 0; i < mx; i ++){
                int tmp = cnt[i];
                cnt[i] = sum;
                sum += tmp;
        }


        for(int i = 0; i < n; i ++){
                tmpSA[cnt[RA[(SA[i] + k) % n]] ++] = SA[i];
        }

        for(int i = 0; i < n; i ++) SA[i] = tmpSA[i];

}

void suffix_array()
{
        for(int i = 0; i < n; i ++) RA[i] = s[i], SA[i] = i;

        for(int k = 1; k < n; k <<= 1){
                counting_sort(k);
                counting_sort(0);

                tmpRA[SA[0]] = 0;
                int r = 0;

                for(int i = 1; i < n;i ++){
                        tmpRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[(SA[i] + k) % n] == RA[(SA[i - 1] + k) % n]) ? r : ++ r;
                }

                for(int i = 0; i < n; i ++) RA[i] = tmpRA[i];
                if(RA[SA[n - 1]] == n - 1) break;
        }
}

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%s", ch);
                s = "";
                s = ch;
                n = s.size();

                suffix_array();

                printf("%d\n", SA[0] + 1);

        }

        return 0;
}
