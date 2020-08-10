#include<bits/stdc++.h>
using namespace std;
int father[110];
int findFa(int x){
    return x == father[x] ? x : father[x] = findFa(father[x]);
}
void Union(int a, int b){
    int fa=findFa(a), fb=findFa(b);
    if(fa > fb) father[fa] = fb;
    else father[fb] = fa;
}
int main(int argc, const char * argv[]) {
    int N, M, K, a, b, c, enemy[110][110];
    for(int i=0; i<110; i++)
        father[i] = i;
    scanf("%d%d%d",&N, &M, &K);
    fill(enemy[0], enemy[0]+110*110, 0);
    for(int i=0; i<M; i++){
        scanf("%d%d%d", &a, &b, &c);
        if(c == 1){
            Union(a, b);
        }else{
            enemy[a][b] = -1;
            enemy[b][a] = -1;
        }
    }
    for(int i=0; i<K; i++){
        scanf("%d%d", &a, &b);
        int fa = findFa(a), fb = findFa(b);
        if(fa == fb){
            if(enemy[a][b] == 0) printf("No problem\n");
            else printf("OK but...\n");
        }else{
            if(enemy[a][b] == 0) printf("OK\n");
            else printf("No way\n");
        }
    }
    return 0;
}
