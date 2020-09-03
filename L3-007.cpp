#include<bits/stdc++.h>
using namespace std;
int edge[510][510], Time[510][510], start, end_;
int mindis = INT_MAX;
int cost_dis = 0, cost_time = 0;
vector<int> path_time, path_dis, tmp;
vector<vector<int>> before;
void dfs(int v, int type){
    tmp.push_back(v);
    if(v == start){
        if(type == 1){ // distance
            if(path_dis.size() > tmp.size() || path_dis.size() == 0){
                path_dis = tmp;
            }
        }else if(type == 2){ // time
            int tmpdis = 0;
            for(int i=tmp.size()-1; i>0; i--)
                tmpdis += edge[tmp[i]][tmp[i-1]];
            if(tmpdis < mindis){
                path_time = tmp;
                mindis = tmpdis;
            }
        }
        tmp.pop_back();
        return;
    }
    for(auto it : before[v])
        dfs(it, type);
    tmp.pop_back();
}
vector<vector<int>> dijkstra(int cost[510][510], int n, int type){
    vector<vector<int>> before(n, vector<int>());
    vector<int> dis(n, INT_MAX);
    vector<bool> visit(n, false);
    dis[start] = 0;
    for(int i=0; i<n; i++){
        int u = -1, mindis = INT_MAX;
        for(int j=0; j<n; j++){
            if(!visit[j] && dis[j] < mindis){
                u = j;
                mindis = dis[j];
            }
        }
        if(u == -1 || u == end_) break;
        visit[u] = true;
        for(int v=0; v<n; v++){
            if(!visit[v] && cost[u][v] != -1){
                if(cost[u][v] + dis[u] < dis[v]){
                    dis[v] = cost[u][v] + dis[u];
                    before[v].clear();
                    before[v].push_back(u);
                }else if(cost[u][v] + dis[u] == dis[v])
                    before[v].push_back(u);
            }
        }
    }
    if(type == 1) cost_dis = dis[end_];
    else cost_time = dis[end_];
    return before;
}
void printRes(vector<int> path){
    for(int i=path.size()-1; i>=0; i--)
        printf(" %d%s", path[i], i==0?"":" =>");
}
int main(int argc, const char * argv[]) {
    int N, M, a, b, w, le, t;
    memset(edge, -1, sizeof(edge));
    memset(Time, -1, sizeof(Time));
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++){
        scanf("%d%d%d%d%d", &a, &b, &w, &le, &t);
        edge[a][b] = le;
        Time[a][b] = t;
        if(w == 0){
            edge[b][a] = le;
            Time[b][a] = t;
        }
    }
    scanf("%d%d", &start, &end_);
    before = dijkstra(edge, N, 1);
    dfs(end_, 1);
    before = dijkstra(Time, N, 2);
    dfs(end_, 2);
    if(path_dis == path_time){
        printf("Time = %d; Distance = %d:", cost_time, cost_dis);
        printRes(path_time);
    }else{
        printf("Time = %d:", cost_time);
        printRes(path_time);
        printf("\nDistance = %d:", cost_dis);
        printRes(path_dis);
    }
    return 0;
}
