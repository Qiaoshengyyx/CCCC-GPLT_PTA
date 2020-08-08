#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> door;
int res;
void bfs(int root){
    queue<int> que;
    que.push(root);
    while(!que.empty()){
        int tmp = que.front();
        res = tmp;
        que.pop();
        for(int i=0; i<door[tmp].size(); i++){
            que.push(door[tmp][i]);
        }
    }
}
int main(int argc, const char * argv[]) {
    int N, K, root;
    scanf("%d", &N);
    door.resize(N+1);
    vector<bool> visit(N+1, false);
    for(int i=1; i<=N; i++){
        scanf("%d", &K);
        door[i].resize(K);
        for(int j=0; j<K; j++){
            scanf("%d", &door[i][j]);
            visit[door[i][j]] = true;
        }
    }
    for(int i=1; i<=N; i++)
        if(!visit[i]) root = i;
    bfs(root);
    printf("%d", res);
    return 0;
}
