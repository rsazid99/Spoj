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
int arr[maxn], n, x, qe[maxn];
char ch[20];
vector<int> v;
int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d\n", &n);

                memset(qe, 0, sizeof qe);

                for(int i = 1; i <= n; i ++){
                        arr[i] = 1;
                        scanf("%s", ch);
                        if(ch[0] == 'd') qe[i] = 0;
                        else{
                                scanf("%d", &x);
                                qe[i] = x;
                        }
                }

                for(int i = n; i > 0 ; i --){
                        if(arr[i] && qe[i]){
                                arr[qe[i]] = 0;
                        }
                }

                for(int i = 1; i <= n; i ++){
                        if(arr[i]) v.push_back(i);
                }

                printf("%d\n", v.size());

                for(int i = 0; i < v.size(); i ++){
                        if(i > 0) printf(" ");
                        printf("%d", v[i]);
                }
                printf("\n");
                v.clear();
        }

        return 0;
}
