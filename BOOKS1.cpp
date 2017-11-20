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

ll arr[505];
vector<string> v;
int n, k;

string to_str(ll val)
{
        string r;
        while(val){
                r += (val % 10) + '0';
                val /= 10;
        }
        reverse(r.begin(), r.end());

        return r;
}

bool ok(ll val)
{
        int cnt = 0;
        ll sum = 0;
        v.clear();
        for(int i = n; i > 0; i --){
                if(i > k - cnt){
                        if(sum + arr[i] <= val){
                                sum += arr[i];
                                v.push_back(to_str(arr[i]));
                        }
                        else{
                                cnt ++;
                                v.push_back("/");
                                v.push_back(to_str(arr[i]));
                                sum = arr[i];
                        }
                }
                else{
                        if(sum + arr[i] <= val){
                                v.push_back(to_str(arr[i]));
                                cnt ++;
                                sum = 0;
                        }
                        else if(sum > 0 && sum <= val && arr[i] + sum > val && arr[i] <= val){
                                v.push_back("/");
                                v.push_back(to_str(arr[i]));
                                sum = arr[i];
                                cnt ++;
                                continue;
                        }
                        if(i > 1) v.push_back("/");

                }
        }
        if(sum > 0 && sum <= val){
                cnt ++;
        }
        reverse(v.begin(),v.end());
        if(cnt == k) return true;
        else return false;
}

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &k);
                ll sum = 0, mx = 0;
                for(int i = 1; i <= n; i ++){
                        scanf("%d", &arr[i]);
                        mx = max(mx, arr[i]);
                        sum += arr[i];
                }

                ll lo = mx, hi = sum, mid = 0;
                vector<string> ans;

                while(lo <= hi){
                        mid = (lo + hi) / 2;
                        if(ok(mid)){
                                ans = v;
                                hi = mid - 1;
                        }
                        else lo = mid + 1;
                }
                sum = 0;

                for(int i = 0; i < ans.size(); i ++){
                        if(i > 0) cout <<" ";
                        cout << ans[i];
                }
                cout << endl;

        }

        return 0;
}
