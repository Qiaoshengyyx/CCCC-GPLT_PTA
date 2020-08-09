#include<bits/stdc++.h>
using namespace std;
int ifsu[10010]={0};
void initial(){
    ifsu[1] = 1;
    for(int i=2; i<10010; i++){
        if(ifsu[i] == 0){
            for(int j=i+i; j<10010; j+=i)
                ifsu[j] = 1;
        }
    }
}
int main(int argc, const char * argv[]) {
    int a, b, sum, cnt[10010]={-1};
    initial();
    scanf("%d%d", &a, &b);
    map<int, int> mapp;
    bool flag = false;
    for(int i=a; i<=b; i++){
        int tmp = i;
        set<int> appear;
        while(tmp != 1){
            sum = 0;
            do sum += pow(tmp % 10, 2); while(tmp /= 10);
            tmp = sum;
            if(appear.count(tmp)) break;
            else appear.insert(tmp);
            cnt[tmp] = 1;
        }
        if(tmp == 1)
            mapp[i] = (ifsu[i] ? appear.size() : 2*appear.size());
    }
    for(auto it : mapp){
        if(cnt[it.first] != 1){
            flag = true;
            printf("%d %d\n", it.first, it.second);
        }
    }
    if(!flag) printf("SAD");
    return 0;
}
