#include<bits/stdc++.h>
using namespace std;
long long a, b;

#define maxn 1000005

bool mark[maxn + 10];
vector<int> pl, pa, pb;
int cnta[maxn + 10], cntb[maxn + 10];

void sieve()
{
        memset(mark, true, sizeof mark);
        mark[0] = mark[1] = false;
        for(int i = 4; i <= maxn; i += 2) mark[i] = false;


        for(int i = 3; i* i <= maxn; i +=2){
                if(mark[i]){

                for(int j = i * i ; j <= maxn; j += 2 * i) mark[j] = false;

                }

        }

        pl.push_back(2);
        for(int i = 3; i <= maxn; i += 2){
                if(mark[i]) pl.push_back(i);
        }
}

void prime_fac_a(int num)
{
        for(int i = 0; i < pl.size(); i ++){
                long long factor = pl[i];
                if(factor * factor > num) break;
                if(num % factor == 0){
                pa.push_back(factor);
                while(num % factor == 0){
                        cnta[factor] ++;
                        num /= factor;
                }
                }
        }
        if(num > 1){
                pa.push_back(num);
                cnta[num] ++;
        }
}


void prime_fac_b(int num)
{
        for(int i = 0; i < pl.size(); i ++){
                long long factor = pl[i];
                if(factor * factor > num) break;
                if(num % factor == 0){
                pb.push_back(factor);
                while(num % factor == 0){
                        cntb[factor] ++;
                        num /= factor;
                }
                }
        }
        if(num > 1){
                pb.push_back(num);
                cntb[num] ++;
        }
}



int main()
{
        sieve();

        int tt = 1;
        while(scanf("%d %d", &a, &b)){
                if(!a && !b) break;
                memset(cnta, 0, sizeof cnta);
                memset(cntb, 0, sizeof cntb);

                prime_fac_a(a);
                prime_fac_b(b);

                long long dist = 0;
                set<int> se;
                for(int i = 0; i < pa.size(); i ++){
                        if(cntb[pa[i]] == 0) dist += cnta[pa[i]];
                        else dist += abs(cnta[pa[i]] - cntb[pa[i]]);
                        se.insert(pa[i]);
                }

                for(int i = 0; i < pb.size(); i ++){
                        if(cnta[pb[i]] == 0) dist += cntb[pb[i]];
                        se.insert(pb[i]);
                }
                printf("%d. %d:%lld\n",tt ++, se.size(), dist);

                se.clear();
                pa.clear();
                pb.clear();
        }

        return 0;
}

