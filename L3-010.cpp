#include<bits/stdc++.h>
using namespace std;
map<int, int> tree;
int maxIndex = 0;
void create(int a, int index){
    if(tree.count(index) == 0){
        tree[index] = a;
        maxIndex = max(maxIndex, index);
        return;
    }
    if(a > tree[index]) create(a, 2*index);
    else if(a < tree[index]) create(a, 2*index+1);
}
int main(int argc, const char * argv[]) {
    int N, a;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &a);
        create(a, 1);
    }
    bool flag = true;
    for(auto it : tree){
        printf("%s%d", flag?"":" ", it.second);
        flag = false;
    }
    if(maxIndex == N) printf("\nYES");
    else printf("\nNO");
    return 0;
}
