#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e4+5;
int father[maxN];
int findFa(int a){
    int tmp = a, z;
    while(tmp != father[tmp]){
        tmp = father[tmp];
    }
    while(a != tmp){
        z = father[a];
        father[a] = tmp;
        a = z;
    }
    father[a] = tmp;
    return tmp;
}
void Union(int a, int b){
    int fa = findFa(a), fb = findFa(b);
    if(fa > fb)
        father[fa] = fb;
    else if(fb > fa)
        father[fb] = fa;
}
int main(int argc, const char * argv[]) {
    int N, M, index=0, K, a, b;
    scanf("%d", &N);
    for(int i=0; i<maxN; i++)
        father[i] = i;
    for(int i=0; i<N; i++){
        scanf("%d%d", &K, &a);
        index = max(index, a);
        for(int j=1; j<K; j++){
            scanf("%d", &b);
            index = max(index, b);
            Union(a, b);
            if(b < a) a = b;
        }
    }
    set<int> s;
    for(int i=1; i<=index; i++){
        findFa(i);
        s.insert(father[i]);
    }
    printf("%d %d\n",index, s.size());
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d%d",&a, &b);
        if(father[a] == father[b])
            printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
