#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, root, a, maxlevel = 0;
    scanf("%d", &N);
    vector<int> tree[N+1], level(N+1, 1), res;
    for(int i=1; i<=N; i++){
        scanf("%d", &a);
        if(a == -1) {
            root = i;
            continue;
        }
        tree[a].push_back(i);
    }
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        if(level[tmp] > maxlevel){
            maxlevel = level[tmp];
            res.clear();
            res.push_back(tmp);
        }else if(level[tmp] == maxlevel)
            res.push_back(tmp);
        for(int i=0; i<tree[tmp].size(); i++){
            level[tree[tmp][i]] = level[tmp] + 1;
            que.push(tree[tmp][i]);
        }
    }
    printf("%d\n", maxlevel);
    for(int i=0; i<res.size(); i++)
        printf("%s%d", i==0?"":" ", res[i]);
    return 0;
}
