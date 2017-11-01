//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define inf             1061109567
#define ff  first
#define ss  second

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef pair<ll, ll> ii;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

vector<int> lucky;
int mark[maxn + 10], n;

int main()
{
        pb_ds treap;
        for(int i = 2; i <= 100010; i ++){
                treap.insert(i);
        }

        for(int i = 2; i <= 100010; i ++){
                if(!mark[i]){
                        lucky.push_back(i);
                        vector<int> v;
                        int pos = treap.order_of_key(i);

                        for(int j = pos + i; j <= 100010 && j < treap.size(); j += i){
                                v.push_back(*treap.find_by_order(j));
                        }
                        for(int i = 0; i < v.size(); i ++) treap.erase(v[i]), mark[v[i]] = 1;
                }
        }

        while(true){
                scanf("%d", &n);
                if(n == 0) break;
                printf("%d\n", lucky[n - 1]);
        }
        return 0;
}
