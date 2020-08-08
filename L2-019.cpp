#include<bits/stdc++.h>
using namespace std;
struct person{
    string name;
    int num;
};
unordered_map<string, int> mapp;
vector<person> maybe;
int main(int argc, const char * argv[]) {
    int N, M, t;
    double avg = 0;
    string name;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        cin>>name;
        mapp[name] = 0;
    }
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        cin>>name>>t;
        avg += t;
        if(mapp.count(name) == 0)
            maybe.push_back({name, t});
    }
    avg /= M;
    sort(maybe.begin(), maybe.end(), [](const person &a, const person &b){
        return a.name < b.name;
    });
    bool flag = false;
    for(int i=0; i<maybe.size(); i++){
        if(maybe[i].num > avg){
            flag = true;
            cout<<maybe[i].name<<endl;
        }
    }
    if(flag == false) cout<<"Bing Mei You";
    return 0;
}
