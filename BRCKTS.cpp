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

string s, r;
int n, m, k;

struct node{
        int p, q, cnt;
};

node tree[4 * 30005];

void build(int id, int l, int r)
{
        if(l == r){
                if(s[l] == '(') tree[id].p = 1, tree[id].q = 0;
                else tree[id].q = 1, tree[id].p = 0;
                tree[id].cnt = 0;
                return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        int mn = min(tree[id * 2].p, tree[id * 2 + 1].q);
        tree[id].cnt = tree[id * 2].cnt + tree[id * 2 + 1].cnt + mn;
        tree[id].p = tree[id * 2].p + tree[id * 2 + 1].p - mn;
        tree[id].q = tree[id * 2].q + tree[id * 2 + 1].q - mn;
}

void update(int id, int l, int r, int pos)
{
        if(l == r && pos == l){
                if(s[l] == '(') tree[id].p = 1, tree[id].q = 0;
                else tree[id].q = 1, tree[id].p = 0;
                tree[id].cnt = 0;
                return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid) update(id * 2, l, mid, pos);
        else update(id * 2 + 1, mid + 1, r, pos);
        int mn = min(tree[id * 2].p, tree[id * 2 + 1].q);
        tree[id].cnt = tree[id * 2].cnt + tree[id * 2 + 1].cnt + mn;
        tree[id].p = tree[id * 2].p + tree[id * 2 + 1].p - mn;
        tree[id].q = tree[id * 2].q + tree[id * 2 + 1].q - mn;
}


int main()
{
        int tt = 1;
        while(scanf("%d", &n) != EOF){
                s = " ";
                cin >> r;
                s += r;
                scanf("%d", &m);
                build(1, 1, n);
                printf("Test %d:\n", tt ++);
                while(m --){
                        scanf("%d", &k);

                        if(k > 0){

                                if(s[k] == '(') s[k] = ')';
                                else s[k] = '(';
                                update(1, 1, n, k);
                        }
                        else{
                                if(tree[1].cnt == n / 2) printf("YES\n");
                                else printf("NO\n");
                        }
                }

        }

        return 0;
}
