#include<bits/stdc++.h>
using namespace std;
vector<set<int>> v;
double cal(int a, int b){
    double Nc = 0, Nt = v[a].size() + v[b].size();
    for(auto it : v[a]){
        if(v[b].count(it)){
            Nc++;
            Nt--;
        }
    }
    return Nc / Nt * 100;
}
int main(int argc, const char * argv[]) {
    int N, k, num, M, a, b;
    double res;
    scanf("%d", &N);
    v.resize(N+1);
    for(int i=0; i<N; i++){
        scanf("%d", &k);
        for(int j=0; j<k; j++){
            scanf("%d", &num);
            v[i+1].insert(num);
        }
    }
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d%d",&a, &b);
        res = cal(a,b);
        printf("%.2lf%%\n",res);
    }
    return 0;
}
