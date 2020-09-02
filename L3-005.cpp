#include<bits/stdc++.h>
using namespace std;
int minIndex = -1, minmaxDis=0;
int edge[1015][1015];
double minAvg;
int main(int argc, const char * argv[]) {
    int N, M, K, Ds, d, c1, c2;
    string s1, s2;
    scanf("%d%d%d%d", &N, &M, &K, &Ds);
    memset(edge, -1, sizeof(edge));
    
    for(int i=0; i<K; i++){
        cin>>s1>>s2>>d;
        if(s1[0] == 'G') c1 = N + stoi(s1.substr(1));
        else c1 = stoi(s1);
        if(s2[0] == 'G') c2 = N + stoi(s2.substr(1));
        else c2 = stoi(s2);
        edge[c1][c2] = d;
        edge[c2][c1] = d;
    }
    for(int i=1; i<=M; i++){
        vector<int> dis(N+M+1, INT_MAX);
        vector<bool> visit(N+M+1, false);
        dis[N+i] = 0;
        for(int j=1; j<N+M+1; j++){
            int u = -1, mindis = INT_MAX;
            for(int k=1; k<N+M+1; k++){
                if(!visit[k] && dis[k] < mindis){
                    u = k;
                    mindis = dis[k];
                }
            }
            if(u == -1) break;
            visit[u] = true;
//            cout<<"u: "<<u<<" ";
            for(int v=1; v<N+M+1; v++){
                if(!visit[v] && edge[u][v] != -1 && edge[u][v] + dis[u] < dis[v])
                    dis[v] = edge[u][v] + dis[u];
            }
        }
        int tmpSum = 0, tmpMin = INT_MAX;
        double tmpAvg;
        bool flag = true;
        for(int j=1; j<=N; j++){
            if(dis[j] > Ds){
                flag = false;
                break;
            }
            tmpMin = min(tmpMin, dis[j]);
            tmpSum += dis[j];
        }
        if(flag == false) continue;
        tmpAvg = tmpSum*1.0/N;
        if(tmpMin > minmaxDis || (tmpMin == minmaxDis && tmpAvg < minAvg)){
            minmaxDis = tmpMin;
            minAvg = tmpAvg;
            minIndex = i;
        }
    }
    if(minIndex == -1) printf("No Solution");
    else printf("G%d\n%.1lf %.1lf", minIndex, minmaxDis*1.0, minAvg);
    return 0;
}
