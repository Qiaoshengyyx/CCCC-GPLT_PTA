#include<bits/stdc++.h>
using namespace std;
int edge[210][210], maxTown = 0, maxEnemy = 0, cnt=0;
vector<vector<int>> pre;
vector<int> counts,path, tmp;
unordered_map<string, int> str2id;
unordered_map<int, string> id2str;
void dfs(int v){
    tmp.push_back(v);
    if(v == 0){
        cnt++;
        int tmpTown = tmp.size()-1, tmpEnemy = 0;
        for(int i=0; i<tmp.size()-1; i++)
            tmpEnemy += counts[tmp[i]];
        if(tmpTown > maxTown || (tmpTown == maxTown && tmpEnemy > maxEnemy)){
            maxTown = tmpTown;
            maxEnemy = tmpEnemy;
            path = tmp;
        }
        tmp.pop_back();
        return;
    }
    for(auto it : pre[v])
        dfs(it);
    tmp.pop_back();
}
int main(int argc, const char * argv[]) {
    int N, K, id=0, d;
    string a, b;
    memset(edge, -1, sizeof(edge));
    scanf("%d%d", &N, &K);
    pre.resize(N);
    counts.resize(N);
    cin>>a>>b;
    str2id[a] = id;
    id2str[id++] = a;
    str2id[b] = id;
    id2str[id++] = b;
    for(int i=0; i<N-1; i++){
        cin>>a>>d;
        if(str2id.count(a) == 0){
            str2id[a] = id;
            id2str[id++] = a;
        }
        counts[str2id[a]] = d;
    }
    for(int i=0; i<K; i++){
        cin>>a>>b>>d;
        int ida = str2id[a], idb = str2id[b];
        edge[ida][idb] = d;
        edge[idb][ida] = d;
    }
    vector<int> dis(N, INT_MAX);
    vector<bool> visit(N, false);
    dis[0] = 0;
    for(int i=0; i<N; i++)
    {
        int u = -1, mindis = INT_MAX;
        for(int j=0; j<N; j++){
            if(!visit[j] && dis[j] < mindis){
                u = j;
                mindis = dis[j];
            }
        }
        if(u == -1 || u == 1) break;
        visit[u] = true;
        for(int v=0; v<N; v++){
            if(!visit[v] && edge[u][v] != -1){
                if(edge[u][v] + dis[u] < dis[v]){
                    dis[v] = edge[u][v] + dis[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(edge[u][v] + dis[u] == dis[v])
                    pre[v].push_back(u);
            }
        }
    }
    dfs(1);
    for(int i=path.size()-1; i>=0; i--){
        printf("%s%s", id2str[path[i]].c_str(), i==0?"":"->");
    }
    printf("\n%d %d %d", cnt, dis[1], maxEnemy);
    return 0;
}
