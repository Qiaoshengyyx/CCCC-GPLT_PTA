#include<bits/stdc++.h>
using namespace std;
struct person{
    string name;
    int num;
    double avg;
};
int main(int argc, const char * argv[]) {
    int N, K, label;
    string name;
    scanf("%d", &N);
    vector<person> v;
    for(int i=0; i<N; i++){
        cin>>name>>K;
        set<int> s;
        for(int j=0; j<K; j++){
            scanf("%d", &label);
            s.insert(label);
        }
        int sum = s.size();
        double avg = K * 1.0 / sum;
        v.push_back({name, sum, avg});
    }
    sort(v.begin(), v.end(), [](const person& a, const person& b){
        return tie(a.num, b.avg) > tie(b.num, a.avg);
    });
    for(int i=0; i<v.size() && i<3; i++)
        printf("%s%s",i==0?"":" ", v[i].name.c_str());
    for(int j=3-v.size(); j>0; j--)
        printf(" -");
    
    return 0;
}
