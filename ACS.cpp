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

const ll MOD = 998244353;

ii exEuclid(ll a, ll b) {
        if(b == 0) return ii(1, 0);
        else {
                ii r = exEuclid(b, a%b);
                return ii(r.ss, r.ff-r.ss*(a/b));
        }
}

int modInv(ll a, ll m) { ii ret = exEuclid(a, m); return ((ret.ff % m) + m ) % m; }

char ch;
int x, y;
int mat[1235][5679], row[1235], col[5679], rw[1235], cl[5679];

int main()
{
        //freopen("out.txt", "w", stdout);
        int cnt = 0;
        for(int i = 1; i <= 1234; i ++){
                for(int j = 1; j <= 5678; j ++){
                        mat[i][j] = ++cnt;
                        if(i == 1) col[j] = j, cl[j] = j;
                }
                row[i] = i, rw[i] = i;
        }

        while(scanf("%c", &ch) != EOF){
                if(ch == 'R'){
                        scanf("%d %d", &x, &y);
                        //cout << ch << " " << x << " " << y << endl;
                        int tmp = row[y];
                        row[y] = row[x];
                        row[x] = tmp;
                        rw[row[x]] = x, rw[row[y]] = y;
                }
                else if(ch == 'C'){
                        scanf("%d %d", &x, &y);
                        //cout << ch << " " << x << " " << y << endl;
                        int tmp = col[y];
                        col[y] = col[x];
                        col[x] = tmp;
                        cl[col[x]] = x, cl[col[y]] = y;
                }
                else if(ch == 'Q'){
                        scanf("%d %d", &x, &y);
                        //cout << ch << " " << x << " " << y << endl;
                        printf("%d\n", mat[row[x]][col[y]]);
                }
                else if(ch == 'W'){
                        scanf("%d", &x);
                        //cout << ch << " " << x<< endl;
                        int c = x % 5678;
                        if(c == 0) c = 5678;
                        int r = x / 5678;
                        if(x % 5678 != 0) r ++;
                        //cout << r <<" -- " << c << endl;
                        printf("%d %d\n", rw[r], cl[c]);
                }
                else continue;
                getchar();
        }

        return 0;
}




