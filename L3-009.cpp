#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> point;
bool judge(int a1, int b1, int a2, int b2){
    return 1LL*a1*b2 > 1LL*a2*b1;
}
int main(int argc, const char * argv[]) {
    int N, ans = 0, x1, y1, x, y;
    vector<point> vec;
    scanf("%d", &N);
    scanf("%d%d%d%d", &x1, &y1, &x, &y);
    vec.push_back({x1, y1});
    vec.push_back({x, y});
    for(int i=3; i<=N; i++){
        scanf("%d%d", &x, &y);
        bool flag = true;
        while(vec.size() >= 2){
            point p1 = vec.back();
            point p2 = vec[vec.size()-2];
            if(judge(p1.second-y, p1.first-x, p2.second-p1.second, p2.first-p1.first)){
                break;
            }else{
                flag = false;
                vec.pop_back();
            }
        }
        if(flag) ans++;
        vec.push_back({x, y});
    }
    printf("%d", ans);
    return 0;
}
