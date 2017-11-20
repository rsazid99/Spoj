//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(int N, int pos) {return (bool) (N & (1 << pos));}

typedef pair<int, int> ii;

char g[100][100];
int r, c, sr, sc, level[100][100][40];
int row[] = {1, -1, 0, 0};
int col[] = {0, 0, -1, 1};
struct node{
        int x, y, val;
        node(int _x, int _y, int _val){
                x = _x;
                y = _y;
                val = _val;
        }

};

int ret_v(char ch)
{
        if(ch == 'b' || ch == 'B') return 1;
        else if(ch == 'y' || ch == 'Y') return 2;
        else if(ch == 'r' || ch == 'R') return 3;
        else if(ch == 'g' || ch == 'G') return 4;
}

int bfs()
{
        queue<node> Q;
        Q.push(node(sr, sc, 0));
        memset(level, -1, sizeof level);
        level[sr][sc][0] = 0;

        while(!Q.empty()){
                node u = Q.front();
                Q.pop();

                if(g[u.x][u.y] == 'X') return level[u.x][u.y][u.val];

                for(int i = 0; i < 4; i ++){
                        int nr = u.x + row[i];
                        int nc = u.y + col[i];
                        if(nr >= 0 && nr < r && nc >= 0 && nc < c && g[nr][nc] != '#'){
                                if((g[nr][nc] == '.' || g[nr][nc] == 'X' || g[nr][nc] == '*') && level[nr][nc][u.val] < 0){
                                        level[nr][nc][u.val] = level[u.x][u.y][u.val] + 1;
                                        Q.push(node(nr, nc, u.val));
                                }
                                else if(g[nr][nc] >= 'a' && g[nr][nc] <= 'z' && level[nr][nc][Set(u.val, ret_v(g[nr][nc]))] < 0){
                                        level[nr][nc][Set(u.val, ret_v(g[nr][nc]))] = level[u.x][u.y][u.val] + 1;
                                        Q.push(node(nr, nc, Set(u.val, ret_v(g[nr][nc]))));
                                }
                                else if(g[nr][nc] >= 'A' && g[nr][nc] <= 'Z' && check(u.val, ret_v(g[nr][nc])) && level[nr][nc][u.val] < 0 && g[nr][nc] != 'X'){
                                        level[nr][nc][u.val] = level[u.x][u.y][u.val] + 1;
                                        Q.push(node(nr, nc, u.val));
                                }
                        }
                }
        }


        return -1;

}

int main()
{
        while(scanf("%d %d", &r, &c)){
                if(!r && !c) break;
                bool flag = false;
                for(int i = 0; i < r; i ++){
                        scanf("%s", g[i]);
                        for(int j = 0; j < c; j ++){
                                if(g[i][j] == '*'){
                                        sr = i;
                                        sc = j;
                                }
                                else if(g[i][j] == 'X'){
                                        flag = true;
                                }
                        }
                }
                if(!flag){
                        printf("The poor student is trapped!\n");
                        continue;
                }

                int ans = bfs();

                if(ans == -1) printf("The poor student is trapped!\n");
                else printf("Escape possible in %d steps.\n", ans);


        }

        return 0;
}
