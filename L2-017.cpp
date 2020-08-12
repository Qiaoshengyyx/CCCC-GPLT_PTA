#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    vector<int> v(N+1, 0);
    for(int i=1; i<=N; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    
    for(int i=1; i<=N; i++)
        v[i] += v[i-1];
    int mid = N/2, maxDiff=0, res;
    for(int i=0; i<=1; i++){
        if(maxDiff < abs(v[N]-2*v[mid+i])){
            maxDiff = abs(v[N] - 2*v[mid+i]);
            res = mid+i;
        }
    }
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", N-res, res, maxDiff);
    return 0;
}
