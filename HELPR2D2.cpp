//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
#include <string>
using namespace std;

#define maxn            1000010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define inf             1061109567
#define ff  first
#define ss  second
#define read()          freopen("in.txt", "r", stdin)
#define write()         freopen("output.txt", "w", stdout)
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}
int k, n, x, y;
ii tree[4 * maxn];
string s;
vector<int> v;
set<int> se;

ii merge(ii a, ii b)
{
        if(a.first > b.first || (a.first == b.first && a.second < b.second)) return a;
        return b;
}

void build(int id, int l, int r)
{
        if(l == r){
                tree[id] = ii(k, l);
                return;
        }

        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = ii(k, l);
}

int get_idx(int id, int l, int r, int val)
{
        if(l == r) return l;

        int mid = (l + r) / 2;
        if(tree[id * 2].first >= val) return get_idx(id * 2, l, mid, val);
        else return get_idx(id * 2 + 1, mid + 1, r, val);
}

void update(int id, int l, int r, int pos, int val)
{
        if(l == r){
                tree[id].first += val;
                return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid) update(id * 2, l, mid, pos, val);
        else update(id * 2 + 1, mid + 1, r, pos, val);
        tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
}

ii query(int id, int l, int r, int pos)
{
        if(l == r) return tree[id];

        int mid = (l + r) / 2;
        if(pos <= mid) return query(id * 2, l, mid, pos);
        else return query(id * 2 + 1, mid + 1, r, pos);
}


int to_int(string r)
{
        int ret = 0;
        for(int i = 0; i < r.size(); i ++) ret = (ret * 10) + (r[i] - '0');
        return ret;
}

int main()
{
        ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
        int t;
        cin >> t;

        while(t --){
                cin >> k;

                cin >> n;
                int cnt = 0, tot = 0;
                while(cnt < n){
                        cin >> s;
                        if(s[0] == 'b'){
                                cin >> x >> y;
                                cnt += x;
                                tot += x * y;
                                while(x --) v.push_back(y);

                        }
                        else v.push_back(to_int(s)), cnt ++, tot += to_int(s);
                }
                build(1, 1, 1000000);
                for(int i = 0; i < v.size(); i ++){
                        int idx = get_idx(1, 1, 1000000, v[i]);
                        update(1, 1, 1000000, idx, -v[i]);
                        se.insert(idx);
                }
                int sz = se.size();
                ll sum = 0;
                for(auto it : se){
                      sum += query(1, 1, 1000000, it).first;
                }
                cout << sz <<" " << sum << endl;
                se.clear();
                v.clear();
        }

        return 0;
}
