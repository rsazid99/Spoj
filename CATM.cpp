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

int n, m, k, x, y, xa, ya, xb, yb;
int level[101][101][4];
int row[] = {1, -1, 0, 0};
int col[] = {0, 0, -1, 1};


void bfs()
{
        queue<ii> q;
        q.push(ii(x, y));
        level[x][y][0] = 0;

        while(!q.empty()){
                ii u = q.front();
                q.pop();

                for(int i = 0; i < 4; i ++){
                        int nr = row[i] + u.ff;
                        int nc = col[i] + u.ss;
                        //cout << nr <<" " << nc << endl;
                        if(nr >= 1 && nr <= n && nc >= 1 && nc <= m && level[nr][nc][0] > level[u.ff][u.ss][0] + 1){
                                level[nr][nc][0] = level[u.ff][u.ss][0] + 1;
                                q.push(ii(nr, nc));
                        }
                }
        }


        q.push(ii(xa, ya));
        level[xa][ya][1] = 0;

        while(!q.empty()){
                ii u = q.front();
                q.pop();

                for(int i = 0; i < 4; i ++){
                        int nr = row[i] + u.ff;
                        int nc = col[i] + u.ss;
                        if(nr >= 1 && nr <= n && nc >= 1 && nc <= m && level[nr][nc][1] > level[u.ff][u.ss][1] + 1){
                                level[nr][nc][1] = level[u.ff][u.ss][1] + 1;
                                q.push(ii(nr, nc));
                        }
                }
        }


        q.push(ii(xb, yb));
        level[xb][yb][2] = 0;

        while(!q.empty()){
                ii u = q.front();
                q.pop();

                for(int i = 0; i < 4; i ++){
                        int nr = row[i] + u.ff;
                        int nc = col[i] + u.ss;
                        if(nr >= 1 && nr <= n && nc >= 1 && nc <= m && level[nr][nc][2] > level[u.ff][u.ss][2] + 1){
                                level[nr][nc][2] = level[u.ff][u.ss][2] + 1;
                                q.push(ii(nr, nc));
                        }
                }
        }


}


int main()
{
        scanf("%d %d", &n, &m);

        scanf("%d", &k);

        while(k --){
                scanf("%d %d %d %d %d %d", &x, &y, &xa, &ya, &xb, &yb);
                memset(level, 63, sizeof level);

                bfs();
                bool flag = false;
                for(int i = 1; i <= n; i ++){
                        if(level[i][1][0] < level[i][1][1] && level[i][1][0] < level[i][1][2]){
                                flag = true;
                        }
                        if(level[i][m][0] < level[i][m][1] && level[i][m][0] < level[i][m][2]){
                                flag = true;
                        }
                }

                for(int i = 1; i <= m; i ++){
                        if(level[1][i][0] < level[1][i][1] && level[1][i][0] < level[1][i][2]){
                                flag = true;
                        }
                        if(level[n][i][0] < level[n][i][1] && level[n][i][0] < level[n][i][2]){
                                flag = true;
                        }
                }
                if(flag) printf("YES\n");
                else printf("NO\n");
        }


        return 0;
}
