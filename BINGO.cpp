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

string s, r;
map<string, int> ase;
int tot, game;
int main()
{
        while(getline(cin, s)){
                if(cin.eof()) break;
                stringstream ss(s);

                while(ss >> r){
                        string tmp;
                        for(int i = 0; i < r.size(); i ++){
                                if((r[i] >= 'A' && r[i] <= 'Z')|| (r[i] >='a' && r[i] <= 'z')){
                                        if(r[i] >= 'A' && r[i] <= 'Z') tmp += (r[i] + 32);
                                        else tmp += r[i];
                                }
                                else{
                                        if(tmp == "bullshit"){
                                                game ++;
                                                tot += ase.size();
                                                ase.clear();
                                        }
                                        else if(tmp.size() > 0){
                                                ase[tmp] = 1;
                                        }
                                        tmp.clear();
                                }
                        }
                        if(tmp == "bullshit"){
                                game ++;
                                tot += ase.size();
                                ase.clear();
                        }
                        else if(tmp.size() > 0){
                                ase[tmp] = 1;
                        }
                }


        }
        int gc = __gcd(tot, game);
        tot /= gc;
        game /= gc;
        printf("%d / %d\n", tot, game);

        return 0;
}
