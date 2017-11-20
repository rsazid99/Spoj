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


int n, x, y;
vector<int> v;

int main()
{
        int last =  1;
        for(int i = 0; i <= 300; i ++){
                int num = 6 * i + last;
                v.push_back(num);
                last = num;
        }

        while(scanf("%d", &n) != EOF){

                if(n == 1){
                        printf("0 0\n");
                        continue;
                }

                int lo = lower_bound(v.begin(), v.end(), n) - v.begin();
                int st = v[lo - 1];
                x = lo, y = 0;

                if(n > st && n <= st + lo){
                        for(int i = 1; i <= lo; i ++){
                                x --;
                                y ++;
                                st ++;
                                if(st == n) break;
                        }
                        printf("%d %d\n", x, y);
                        continue;
                }
                else st += lo, x -= lo, y += lo;

                if(n > st && n <= st + lo){
                        for(int i = 1; i <= lo; i ++){
                                x --;
                                st ++;
                                if(st == n) break;
                        }
                        printf("%d %d\n", x, y);
                        continue;
                }
                else st += lo, x -= lo;

                if(n > st && n <= st + lo){
                        for(int i = 1; i <= lo; i ++){
                                y --;
                                st ++;
                                if(st == n) break;
                        }
                        printf("%d %d\n", x, y);
                        continue;
                }
                else st += lo, y -= lo;

                if(n > st && n <= st + lo){
                        for(int i = 1; i <= lo; i ++){
                                x ++;
                                y --;
                                st ++;
                                if(st == n) break;
                        }
                        printf("%d %d\n", x, y);
                        continue;
                }
                else st += lo, x += lo, y -= lo;

                if(n > st && n <= st + lo){
                        for(int i = 1; i <= lo; i ++){
                                x ++;
                                st ++;
                                if(st == n) break;
                        }
                        printf("%d %d\n", x, y);
                        continue;
                }
                else st += lo, x += lo;

                if(n > st && n <= st + lo){
                        for(int i = 1; i <= lo; i ++){
                                y ++;
                                st ++;
                                if(st == n) break;
                        }
                        printf("%d %d\n", x, y);
                        continue;
                }
                else st += lo, y += lo;



        }

        return 0;
}
