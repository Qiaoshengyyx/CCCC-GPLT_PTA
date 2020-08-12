#include<bits/stdc++.h>
using namespace std;
struct person{
    string name;
    int grade,rank;
};
bool cmp(const person& a, const person& b){
    return a.grade == b.grade ? a.name < b.name : a.grade > b.grade;
}
int main(){
    int n, g, k, sc, sum = 0;
    string s;
    cin>>n>>g>>k;
    vector<person> v(n);
    vector<int> vsc;
    for(int i=0;i<n;i++){
        cin>>s>>sc;
        v[i] = {s, sc};
    }
    sort(v.begin(), v.end(), cmp);
    v[0].rank = 1;
    for(int i=0;i<n;i++){
        if(v[i].grade >= g && v[i].grade <=100) sum+=50;
        else if(v[i].grade <g && v[i].grade >=60) sum+=20;
        if(i!=0 && v[i].grade == v[i-1].grade){
            v[i].rank = v[i-1].rank;
        }else if(i!=0 && v[i].grade < v[i-1].grade){
            v[i].rank = i+1;
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<n;i++){
        if(v[i].rank>k) break;
        printf("%d %s %d\n",v[i].rank, v[i].name.c_str(), v[i].grade);
    }
    return 0;
}
