#include<bits/stdc++.h>
using namespace std;
int father[1010], cnt[1010];
int findFa(int x){
    return  x == father[x] ? x : father[x] = findFa(father[x]);
}
void Union(int a, int b){
    int fa = findFa(a), fb = findFa(b);
    if(fa > fb) father[fa] = fb;
    else if(fa < fb) father[fb] = fa;
}
int main(int argc, const char * argv[]) {
    int N, K, a;
    scanf("%d", &N);
    memset(cnt, 0, sizeof(cnt));
    vector<int> hobby[1010];
    for(int i=1; i<=N; i++){
        father[i] = i;
        scanf("%d:", &K);
        for(int j=0; j<K; j++){
            scanf("%d", &a);
            hobby[a].push_back(i);
        }
    }
    for(int i=1; i<=1000; i++){
        if(hobby[i].size()!=0){
            a = hobby[i][0];
            for(int j=1; j<hobby[i].size(); j++){
                Union(a, hobby[i][j]);
            }
        }
    }
    set<int> circle;
    for(int i=1; i<=N; i++){
        int fa = findFa(i);
//        printf(" %d", fa);
        circle.insert(fa);
        cnt[fa]++;
    }
    printf("%d\n", circle.size());
    vector<int> num;
    for(int i=1; i<=N; i++)
        if(cnt[i]!=0) num.push_back(cnt[i]);
    sort(num.begin(), num.end());
    for(int i=num.size()-1; i>=0; i--)
        printf("%d%s", num[i],i==0?"":" ");
    return 0;
}
