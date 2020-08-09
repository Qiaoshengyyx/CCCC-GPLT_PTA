#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, pos=1, last=-1;
    scanf("%d", &N);
    vector<int> teams(N+1);
    vector<int> index[N+1];
    for(int i=1; i<=N; i++){
        scanf("%d", &teams[i]);
        teams[i] *= 10;
    }
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=1; i<=N; i++){
            if(teams[i] > 0){
                flag = true;
                if(last != i){
                    index[i].push_back(pos++);
                }else{
                    pos++;
                    index[i].push_back(pos++);
                }
                last = i;
                teams[i]--;
            }
        }
    }
    for(int i=1; i<=N; i++){
        printf("#%d\n",i);
        int cnt = 0;
        for(int j=0; j<index[i].size(); j++){
            printf("%s%d", cnt==0?"":" ", index[i][j]);
            cnt++;
            if(cnt == 10){
                printf("\n");
                cnt=0;
            }
        }
    }
    return 0;
}

//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//int main(){
//    int n,t,a[1010]={0},sch[100001]={0};
//    cin>>n;
//    vector<vector<int>> v(n+1);
//    for(int i=1;i<=n;i++){
//        cin>>t;
//        a[i]=t*10;
//    }
//    int sum=0,index=1;
//    while(true){
//        sum=0;
//        for(int i=1;i<=n;i++){
//            if(a[i]>0){
//                if(sch[index-1]!=i){
//                    v[i].push_back(index);
//                    sch[index]=i;
//                }else{
//                    index++;
//                    v[i].push_back(index);
//                    sch[index]=i;
//                }
//                a[i]--;
//                index++;
//            }else sum++;
//        }
//        if(sum==n) break;
//    }
//    for(int i=1;i<=n;i++){
//        cout<<"#"<<i<<endl;
//        int k=1;
//        for(int j=0;j<v[i].size();j++){
//            if(k!=1) cout<<' ';
//            cout<<v[i][j];
//            if(k%10==0){
//                cout<<endl;
//                k=0;
//            }
//            k++;
//        }
//    }
//
//
//    return 0;
//}
