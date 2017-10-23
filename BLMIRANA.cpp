//####################################################################
//#####In the Name Of Allah,the Most Gracious,the Most Merciful.######
//####################################################################

#include <bits/stdc++.h>
using namespace std;

#define maxn            100010
#define esp             1e-6
#define mod             1000000007
#define ll              long long
#define inf             1061109567
#define ff  first
#define ss  second

typedef pair<double, int> ii;

int Set(int N, int pos) {return N = N | (1 << pos);}
int reset(int N, int pos) {return N = N & ~ (1 << pos);}
bool check(ll N, int pos) {return (bool) (N & (1LL << pos));}

int n;

const double PI = acos(-1);

struct point{
        double x, y, r;
};
point po[2 * maxn];

vector<ii> v;


double angle(double x, double y)
{
        if(x >= 0 && y >= 0 ) return 90 - atan2(y, x) * 180 / PI + 90;

        else if(x < 0 && y >= 0) return (atan2(y, x) * 180 / PI) * -1.0;

        else if(x < 0 && y < 0) return 360 - (atan2(y, x) * 180 / PI);

        else return (-1.0 * atan2(y, x) * 180 / PI) + 180;
}
bool cmp(ii a, ii b)
{
        if(fabs(a.first - b.first) <= esp) return a.second < b.second;
        return a.first < b.first + esp;
}

int main()
{
        int t, tt = 1;
        scanf("%d", &t);

        while(t --){
                scanf("%d", &n);

                for(int i = 1; i <= n; i ++){
                        scanf("%lf %lf %lf", &po[i].x, &po[i].y, &po[i].r);
                }
                int ext = 0;
                for(int i = 1; i <= n; i ++){
                        double a = sqrt((po[i].x * po[i].x) + (po[i].y * po[i].y));
                        if(a < po[i].r){
                                ext ++;
                                continue;
                        }
                        double m = angle(po[i].x , po[i].y);
                        double b = sqrt((a * a) - (po[i].r * po[i].r));
                        double m1 = acos(b / a) * 180.0 / PI;

                        double ang1 = m - m1;
                        double ang2 = m + m1;

                        v.push_back(ii(ang1, -1));
                        v.push_back(ii(ang2, +1));


                }

                sort(v.begin(), v.end(), cmp);
                int mx = 0, add = 0;
                for(int i = 0; i < v.size(); i ++){
                        if(v[i].second == -1) add ++;
                        else add --;
                        mx = max(mx, add);
                }

                printf("%d\n", mx + ext);
                v.clear();

        }

        return 0;
}
