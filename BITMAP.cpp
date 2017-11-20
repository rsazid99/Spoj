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

int n, m, mat[200][200];
int level[200][200];
int row[] = {1, -1, 0, 0, -1, -1, 1, 1};
int col[] = {0, 0, -1, 1, -1, 1, -1, 1};
char s[200];
void bfs(int r, int c)
{
        queue<ii> q;
        level[r][c] = 0;
        q.push(ii(r, c));

        while(!q.empty()){
                ii u = q.front();
                q.pop();

                for(int i = 0; i < 8; i ++){
                        int nr = row[i] + u.ff;
                        int nc = col[i] + u.ss;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && level[nr][nc] > level[u.ff][u.ss] + (abs(u.ff - nr) + abs(u.ss - nc))){
                                level[nr][nc] = level[u.ff][u.ss] + (abs(u.ff - nr) + abs(u.ss - nc));
                                q.push(ii(nr, nc));
                        }
                }
        }
}

int main()
{
        int t;
        scanf("%d", &t);

        while(t --){
                scanf("%d %d", &n, &m);

                for(int i = 0; i < n; i ++){
                        scanf("%s", s);
                        for(int j = 0; j < m; j ++){
                                mat[i][j] = s[j] - '0';
                        }
                }
                memset(level, 63, sizeof level);
                for(int i = 0; i < n; i ++){
                        for(int j = 0;j < m; j ++){
                                if(mat[i][j] == 1){
                                        bfs(i, j);
                                }
                        }
                }

                for(int i = 0; i < n; i ++){
                        for(int j = 0;j < m; j ++){
                                printf("%d ", level[i][j]);
                        }
                        printf("\n");
                }

        }

        return 0;
}
