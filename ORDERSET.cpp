//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
#include <string>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define inf             1061109567
#define ff  first
#define ss  second
#define read()          freopen("in.txt", "r", stdin)
#define write()         freopen("output.txt", "w", stdout)
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;

int q, x;
char ch;

int main()
{
        scanf("%d\n", &q);
        pb_ds treap;
        while(q --){
                scanf("%c %d", &ch, &x);
                getchar();
                if(ch == 'I'){
                        treap.insert(x);
                }
                else if(ch == 'D'){
                        treap.erase(treap.find(x));
                }
                else if(ch == 'K'){
                        if(x > treap.size()) printf("invalid\n");
                        else printf("%d\n", *treap.find_by_order(x - 1));
                }
                else if(ch == 'C'){
                        printf("%d\n", treap.order_of_key(x));
                }
        }

        return 0;
}
