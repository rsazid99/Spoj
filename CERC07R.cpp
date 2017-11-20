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

unordered_map<string, unordered_map<string, int> > ase;
string ln1, ln2, s1, s2, p, q;
int main()
{
        ios_base::sync_with_stdio(false);cin.tie(0);
        ase["cs"]["Kamen"] = 1, ase["cs"]["Nuzky"] = 2, ase["cs"]["Papir"] = 3;
        ase["en"]["Rock"] = 1, ase["en"]["Scissors"] = 2, ase["en"]["Paper"] = 3;
        ase["fr"]["Pierre"] = 1, ase["fr"]["Ciseaux"] = 2, ase["fr"]["Feuille"] = 3;
        ase["de"]["Stein"] = 1, ase["de"]["Schere"] = 2, ase["de"]["Papier"] = 3;
        ase["hu"]["Ko"] = 1, ase["hu"]["Koe"] = 1, ase["hu"]["Ollo"] = 2, ase["hu"]["Olloo"] = 2, ase["hu"]["Papir"] = 3;
        ase["it"]["Sasso"] = 1, ase["it"]["Roccia"] = 1, ase["it"]["Forbice"] = 2, ase["it"]["Carta"] = 3,ase["it"]["Rete"] = 3;;
        ase["jp"]["Guu"] = 1, ase["jp"]["Choki"] = 2, ase["jp"]["Paa"] = 3;
        ase["pl"]["Kamien"] = 1, ase["pl"]["Nozyce"] = 2, ase["pl"]["Papier"] = 3;
        ase["es"]["Piedra"] = 1, ase["es"]["Tijera"] = 2, ase["es"]["Papel"] = 3;
        bool brk = false;
        int tt = 1;
        while(true){
                cin >> ln1 >> s1;
                cin >> ln2 >> s2;
                int w1 = 0, w2 = 0;
                while(true){
                        cin >> p;
                        if(p == "-") break;
                        else if(p == "."){
                                brk = true;
                                break;
                        }
                        else{
                                cin >> q;
                                int sc1 = ase[ln1][p];
                                int sc2 = ase[ln2][q];

                                if(sc1 == 1 && sc2 == 2) w1 ++;
                                else if(sc1 == 2 && sc2 == 1) w2 ++;
                                else if(sc1 == 2 && sc2 == 3) w1 ++;
                                else if(sc1 == 3 && sc2 == 2) w2 ++;
                                else if(sc1 == 1 && sc2 == 3) w2 ++;
                                else if(sc1 == 3 && sc2 == 1) w1 ++;
                        }
                }
                cout << "Game #"<< tt ++ <<":"<< endl;
                if(w1 == 1) cout << s1 <<": " << w1 << " point\n";
                else cout << s1 <<": " << w1 << " points\n";
                if(w2 == 1) cout << s2 <<": " << w2 << " point\n";
                else cout << s2 <<": " << w2 << " points\n";

                if(w1 < w2) cout << "WINNER: " << s2 << endl;
                else if(w1 > w2) cout << "WINNER: " << s1 << endl;
                else cout << "TIED GAME\n";
                cout << endl;

                if(brk) break;


        }

        return 0;
}
