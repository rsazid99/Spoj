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

int r, c, mat[101][101], x, y, ti, level[101][101];
int row[] = {1, -1, 0, 0};
int col[] = {0, 0, -1, 1};

struct node{
        int ro, co, t;
        node(int _ro, int _co, int _t){
                ro = _ro;
                co = _co;
                t = _t;
        }
};

int bfs()
{
        memset(level, 63, sizeof level);
        level[1][1] = mat[1][1];
        queue<node> q;
        q.push(node(1, 1, mat[1][1]));

        while(!q.empty()){
                node u = q.front();
                q.pop();

                if(u.t != level[u.ro][u.co]) continue;

                for(int i = 0; i < 4; i ++){
                        int nr = row[i] + u.ro;
                        int nc = col[i] + u.co;
                        if(nr >= 1 && nr <= r && nc >= 1 && nc <= c && level[nr][nc] > level[u.ro][u.co] + mat[nr][nc]){
                                level[nr][nc] = level[u.ro][u.co] + mat[nr][nc];
                                q.push(node(nr, nc, level[nr][nc]));
                        }
                }
        }
        return level[x][y];

}

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &r, &c);

                for(int i = 1; i <= r; i ++){
                        for(int j = 1; j <= c; j ++){
                                scanf("%d", &mat[i][j]);
                        }
                }

                scanf("%d %d %d", &x, &y, &ti);

                int ans = bfs();
                if(ans <= ti){
                        printf("YES\n");
                        printf("%d\n", ti - ans);
                }
                else printf("NO\n");

        }

        return 0;
}
