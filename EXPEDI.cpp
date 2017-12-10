//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################
//############Created by Sazid Rahman Simanto on 3/20/17.#############
//#####Copyright 2017 Sazid Rahman Simanto. All rights reserved.######
//####################################################################

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <ctime>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <bitset>
#include <list>
#include <algorithm>
#include <complex>
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
int n, L, P, x, y;
vector<ii> v;


int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%d %d", &x, &y);
                        v.push_back(ii(x, y));
                }
                scanf("%d %d", &L, &P);

                sort(v.begin(), v.end());

                int i = n - 1;
                priority_queue<int> pq;
                int now = P, cnt = 0;
                while(i >= 0 && L - v[i].first <= P) pq.push(v[i --].second);

                while(!pq.empty()){
                        if(now >= L) break;
                        now += pq.top();
                        pq.pop();
                        cnt ++;
                        while(i >= 0 && L - v[i].first <= now) pq.push(v[i --].second);
                }
                if(now >= L) printf("%d\n", cnt);
                else printf("-1\n");
                v.clear();
        }

        return 0;
}


