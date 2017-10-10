//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
#include <string.h>
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

const ll MOD = 998244353;

ii exEuclid(ll a, ll b) {
        if(b == 0) return ii(1, 0);
        else {
                ii r = exEuclid(b, a%b);
                return ii(r.ss, r.ff-r.ss*(a/b));
        }
}

int modInv(ll a, ll m) { ii ret = exEuclid(a, m); return ((ret.ff % m) + m ) % m; }

char ch[1000010], s[1000010];

int main()
{
        //std::ios::sync_with_stdio(false);
        int t;
        scanf("%d\n", &t);


        while(t --){

                scanf("%s", ch);

                int p = 0, sz = strlen(ch);
                memset(s, '\0', sizeof s);
                for(int i = sz - 1; i >= 0; i --){
                        s[p] = ch[i];
                        p ++;
                }

                int it = 0;
                while(1){
                        if(s[it] < '9'){
                                s[it] ++;
                                break;
                        }
                        else{
                                s[it] = '0';
                        }
                        it ++;
                        if(it == sz){
                                s[it] = '1';
                                sz ++;
                                break;
                        }
                }
                if(sz == 1) printf("%s\n", s);
                else{
                        int L = 0, R = 0, mid = sz / 2, go = 0;
                        if(sz % 2 == 1){

                                L = mid - 1;
                                R = mid + 1;
                        }
                        else{
                                L = mid - 1;
                                R = mid;
                        }

                        int l = L, r = R;
                        bool flag = false, fl = false;
                        while(l >= 0 && r < sz){
                                //cout << l <<" " << r << endl;
                                if(s[l] == s[r]){
                                        l --, r ++;
                                        continue;
                                }
                                else if(s[l] > s[r]){
                                        if(!fl) flag = true;
                                        fl = true;
                                        break;
                                }
                                else{
                                        fl = true;
                                        l --, r ++;
                                }
                        }
                        if(!fl){
                                printf("%s\n", s);
                                continue;
                        }
                        if(sz % 2 == 1 && flag){
                                if(s[mid] < '9'){
                                        s[mid] ++;
                                        flag = false;
                                }
                                else{
                                        s[mid] = '0';
                                }
                        }

                        if(!flag){
                                l = L, r = R;

                                while(l >= 0 && r < sz){
                                        if(s[l] == s[r]){
                                                l --, r ++;
                                                continue;
                                        }
                                        else{
                                                s[l] = s[r];
                                                l --, r ++;
                                        }
                                }
                        }
                        else{
                                l = L, r = R;
                                bool bo = false;

                                while(l >= 0 && r < sz){
                                        if(s[l] == s[r] && !bo){
                                                if(s[l] != '9'){
                                                        s[l] ++;
                                                        s[r] ++;
                                                        bo = true;
                                                }
                                                else{
                                                        s[l] = s[r] = '0';
                                                }
                                                l --, r ++;

                                        }
                                        if(s[l] == s[r] && bo){
                                                l --, r ++;
                                        }
                                        else if(s[l] < s[r]){
                                                s[l] = s[r];
                                                bo = true;
                                                l --, r ++;
                                        }
                                        else if(s[l] > s[r] && !bo){
                                                bo = true;
                                                s[r] ++;
                                                s[l] = s[r];
                                                l --, r ++;
                                        }
                                        else if(s[l] > s[r] && bo){
                                                s[l] = s[r];
                                                l --, r ++;
                                        }
                                }
                        }
                        printf("%s\n", s);

                }

        }

        return 0;
}


