#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, M, K, a, b;
    scanf("%d%d%d", &N, &M, &K);
    vector<int> tree[N+1];
    for(int i=0; i<M; i++){
        scanf("%d%d",&a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int i=0; i<K; i++){
        scanf("%d", &a);
        int maxlevel=0, res=-1;
        vector<int> level(N+1, 0);
        vector<bool> visit(N+1, false);
        queue<int> que;
        que.push(a);
        visit[a] = true;
        while(!que.empty()){
            int tmp = que.front();
            que.pop();
            if(level[tmp] > maxlevel){
                maxlevel = level[tmp];
                res = tmp;
            }else if(level[tmp] == maxlevel)
                res = min(res, tmp);
            for(int i=0; i<tree[tmp].size(); i++){
                if(!visit[tree[tmp][i]]){
                    level[tree[tmp][i]] = level[tmp] + 1;
                    visit[tree[tmp][i]] = true;
                    que.push(tree[tmp][i]);
                }
            }
        }
        if(res == -1) printf("0\n");
        else printf("%d\n", res);
    }
    
    return 0;
}
