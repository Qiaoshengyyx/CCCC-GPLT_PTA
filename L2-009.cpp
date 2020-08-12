#include<bits/stdc++.h>
using namespace std;
struct person{
    int id,get=0;
    double fen=0;
};
bool cmp(const person& a, const person& b){
    return tie(a.fen, a.get, b.id) > tie(b.fen, b.get, a.id);
}
int main(){
    int n,x,id,mnt,sum;
    cin>>n;
    vector<person> v(n);
    vector<set<int>> s(n);
    for(int i=0;i<n;i++){
        v[i].id=i+1;
        cin>>x;
        sum = 0;
        for(int j=0;j<x;j++){
            cin>>id>>mnt;
            sum+=mnt;
            v[id-1].fen+=mnt;
            v[id-1].get++;
        }
        v[i].fen -= sum;
    }
    for(int i=0;i<n;i++)
        v[i].fen /= 100;
    sort(v.begin(), v.end(), cmp);
    for(int i=0;i<n; i++)
        printf("%d %.2lf\n",v[i].id ,v[i].fen);
    return 0;
}
