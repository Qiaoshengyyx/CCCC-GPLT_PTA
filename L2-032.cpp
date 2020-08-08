#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, M, K, a;
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<K; i++){
        int pos = 1;
        bool flag = true;
        stack<int> sta;
        for(int j=0; j<N; j++){
            scanf("%d", &a);
            sta.push(a);
            while(!sta.empty() && sta.top() == pos){
                pos++;
                sta.pop();
            }
            if(sta.size() > M) flag = false;
        }
        if(flag && sta.size() == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
