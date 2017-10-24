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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n, d;
pb_ds treap;


int main()
{
        while(scanf("%d %d", &n, &d)){
                if(n == 0 && d == 0) break;

                for(int i = 1; i <= n; i ++){
                        treap.insert(i);
                }
                int st = 0, val = 1;
                while(treap.size() > 1){
                        int pos = (st + d - 1) % treap.size();
                        int nxt = (pos + 1) % treap.size();
                        val = *treap.find_by_order(nxt);
                        treap.erase(treap.find_by_order(pos));
                        st = treap.order_of_key(val);
                }

                printf("%d %d %d\n", n, d, val);
                treap.clear();
        }

        return 0;
}
