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

int n, arr[1000010];
vector<int> v;

int main()
{
        scanf("%d", &n);

        for(int i = 1; i <= n; i ++){
                scanf("%d", &arr[i]);
        }
        v.push_back(arr[1]);
        int st = 2;
        ll cost = 0;
        while(st <= n){
                if(v.back() <= arr[st]){
                        while(v.size() && v.back() <= arr[st]){
                                v.pop_back();
                                if(v.empty() || v.back() > arr[st]) cost += arr[st];
                                else cost += v.back();
                        }

                }
                v.push_back(arr[st]);
                st ++;
        }
        for(int i = 0; i + 1 < v.size(); i ++) cost += v[i];
        cout << cost << endl;

}
