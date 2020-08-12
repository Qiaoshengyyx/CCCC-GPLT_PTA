#include<bits/stdc++.h>
using namespace std;
struct node{
    int id, data, next;
};
int main(int argc, const char * argv[]) {
    int start, N, a, b, c;
    node arr[100010];
    vector<node> v, v2;
    scanf("%d%d", &start, &N);
    for(int i=0; i<N; i++){
        scanf("%d%d%d", &a, &b, &c);
        arr[a] = {a, b, c};
    }
    int tmp = start;
    while(tmp != -1){
        v.push_back(arr[tmp]);
        tmp = arr[tmp].next;
    }
    int left = 0, right = v.size()-1;
    while(1){
        v2.push_back(v[right]);
        right--;
        if(right == left-1) break;
        v2.push_back(v[left]);
        left++;
        if(right == left-1) break;
    }
    for(int i=0; i<v2.size(); i++){
        if(i==v2.size()-1) printf("%05d %d -1\n",v2[i].id, v2[i].data);
        else printf("%05d %d %05d\n",v2[i].id, v2[i].data, v2[i+1].id);
    }
    return 0;
}
