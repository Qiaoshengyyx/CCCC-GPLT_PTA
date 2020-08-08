#include<bits/stdc++.h>
using namespace std;
vector<int> pre,in;
map<int, int> tree;
void create(int root, int left, int right, int index){
    if(left > right) return;
    int i = left;
    while(i <= right && pre[root] != in[i]) i++;
    create(root+i-left+1, i+1, right, index*2+1);
    create(root+1, left, i-1, index*2+2);
    tree[index] = pre[root];
}
int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    pre.resize(N);
    in.resize(N);
    for(int i=0; i<N; i++)
        scanf("%d", &in[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &pre[i]);
    create(0, 0, N-1, 0);
    bool flag = false;
    for(auto it : tree){
        if(flag){
            printf(" %d", it.second);
        }else{
            flag = true;
            printf("%d", it.second);
        }
    }
    return 0;
}
