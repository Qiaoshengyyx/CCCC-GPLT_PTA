#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, avg = 0, res, mindis = INT_MAX;
    string s;
    scanf("%d", &N);
    vector<int> grade(N);
    unordered_map<int, string> index2name;
    for(int i=0; i<N; i++){
        cin>>s>>grade[i];
        index2name[i] = s;
        avg += grade[i];
    }
    avg = avg/N/2;
    for(int i=0; i<N; i++){
        int dis = abs(grade[i] - avg);
        if(dis < mindis){
            mindis = dis;
            res = i;
        }
    }
    printf("%d %s", avg, index2name[res].c_str());
    return 0;
}
