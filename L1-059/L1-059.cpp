#include<bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    string s;
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; i++){
        getline(cin, s);
        int d1 = s.find(","), d2=s.find(".");
        if(d1 <= 2 || s.substr(d1-3,3) != "ong" || s.substr(d2-3, 3) != "ong"){
            printf("Skipped\n");
        }else{
            int num = 0, j=0, len = s.size();
            for(j=0; j<len; j++){
                if(s[j] == ' ') num++;
            }
            for(j=0;num >2 ;j++){
                if(s[j] == ' ') num--;
                printf("%c", s[j]);
            }
            printf("qiao ben zhong.\n");
        }
    }
    return 0;
}
