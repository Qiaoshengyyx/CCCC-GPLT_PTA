#include<bits/stdc++.h>
using namespace std;
int main(){
    int start,n,val,a1,a2;
    int value[100000]={-1},next[100000]={-1}, visit[10010]={0};
    vector<int> v,v2;
    scanf("%d%d", &start, &n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a1, &val, &a2);
        value[a1] = val;
        next[a1] = a2;
    }
    int s=start;
    while(s!=-1){
        if(visit[abs(value[s])] == 0){
            visit[abs(value[s])] = 1;
            v.push_back(s);
        }else
            v2.push_back(s);
        s=next[s];
    }
    for(int i=0;i<v.size();i++){
        printf("%05d %d ",v[i], value[v[i]]);
        if(i==v.size()-1) printf("-1\n");
        else printf("%05d\n",v[i+1]);
    }
    for(int i=0;i<v2.size();i++){
        printf("%05d %d ",v2[i], value[v2[i]]);
        if(i==v2.size()-1)printf("-1\n");
        else printf("%05d\n",v2[i+1]);
    }
    return 0;
}
