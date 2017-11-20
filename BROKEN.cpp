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
int n, cnt[300], idx[300];
string s;
vector<int> v;

int main()
{
        while(scanf("%d", &n)){
                if(n == 0) break;
                getchar();
                getline(cin, s);
                memset(cnt, 0, sizeof cnt);
                memset(idx, 0, sizeof idx);
                int id = 0;
                for(int i = 0; i < s.size(); i ++){
                        if(!idx[s[i]]){
                                idx[s[i]] = ++ id;
                        }
                        v.push_back(idx[s[i]]);
                }
                int st = 0, ase = 0;
                int ans = 0;
                for(int i = 0; i < v.size(); i ++){

                        if((cnt[v[i]] == 0 && ase < n) || (ase == n && cnt[v[i]] > 0 )){
                                if(cnt[v[i]] == 0) ase ++;
                                cnt[v[i]] ++;
                                ans = max(ans, i - st + 1);

                        }
                        else{
                                while(ase == n){
                                        cnt[v[st]] --;
                                        if(cnt[v[st]] == 0) ase --;
                                        st ++;
                                }
                                if(cnt[v[i]] == 0) ase ++;
                                cnt[v[i]] ++;
                                ans = max(ans, i - st + 1);
                        }

                }
                printf("%d\n", ans);
                v.clear();
        }
        return 0;
}
