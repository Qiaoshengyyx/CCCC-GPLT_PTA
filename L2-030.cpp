#include<bits/stdc++.h>
using namespace std;
struct node{
    string ming;
    char sex;
};
unordered_map<string, node> mapp; // 记录一个人的名, 第二个记录该人的父亲的名 和 该人的性别, 且题目保证不存在两人同名,所以可以用map

bool judge(string a1, string a2){
//    // 错误做法
//    string f1 = a1, f2 = a2;
//    for(int i=1; i<=5 && !f1.empty(); f1=mapp[f1].ming, i++){
//        f2 = a2;
//        for(int j=1; j<5 && !f2.empty(); f2=mapp[f2].ming, j++){
//            if(f1 == f2) return false;
//        }
//    }
//    return true;
    int i=1, j;
    for(string f1 = a1; !f1.empty(); f1 = mapp[f1].ming, i++){
        j = 1;
        for(string f2 = a2; !f2.empty(); f2 = mapp[f2].ming, j++){
            if(i>=5 && j>=5) return true;
            if(f1 == f2 && (i<5 || j<5)) return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int N, M;
    string xing, ming, a1, b1, a2, b2;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        cin>>ming>>xing;
        if(xing.back() == 'n')
            mapp[ming] = {xing.substr(0, xing.size()-4), 'm'};
        else if(xing.back() == 'r')
            mapp[ming] = {xing.substr(0, xing.size()-7), 'f'};
        else
            mapp[ming].sex = xing.back();
    }
    
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        cin>>a1>>b1>>a2>>b2;
        if(mapp.find(a1) == mapp.end() || mapp.find(a2) == mapp.end()) printf("NA\n");
        else if(mapp[a1].sex == mapp[a2].sex) printf("Whatever\n");
        else {
            if(judge(a1, a2)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
