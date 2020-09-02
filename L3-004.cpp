#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int> > point;
int M, N, L,T;
vector<vector<int>> image[60];
vector<vector<bool>> visit[60];
int dx[6] = {0, -1, 0, 1, 0, 0}, dy[6] = {-1, 0, 1, 0, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};
int bfs(int i, int j, int k){
    queue<point> que;
    que.push({i,{j, k}});  // L M N
    int sum = 1;
    visit[i][j][k] = true;
    while(!que.empty()){
        point tmp = que.front();
        que.pop();
        int z = tmp.first, x = tmp.second.first, y = tmp.second.second;
        for(int d=0; d<6; d++){
            int newx = x + dx[d], newy = y + dy[d], newz = z + dz[d];
            if(newx < 0 || newx >= M || newy < 0 || newy >= N || newz < 0 || newz >=L || visit[newz][newx][newy] == true || image[newz][newx][newy] == 0)
                continue;
            visit[newz][newx][newy] = true;
            sum++;
            que.push({newz, {newx, newy}});
        }
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    scanf("%d%d%d%d", &M, &N, &L, &T);
    int res=0;
    for(int i=0; i<L; i++){
        image[i].resize(M, vector<int>(N));
        visit[i].resize(M, vector<bool>(N, false));
        for(int j=0; j<M; j++)
            for(int k=0; k<N; k++)
                scanf("%d", &image[i][j][k]);
    }
    for(int i=0; i<L; i++){
        for(int j=0; j<M; j++)
            for(int k=0; k<N; k++){
                if(image[i][j][k] == 1 && !visit[i][j][k]){
                    int t = bfs(i, j, k);
                    if(t >= T)
                        res += t;
                }
            }
    }
    printf("%d", res);
    return 0;
}
