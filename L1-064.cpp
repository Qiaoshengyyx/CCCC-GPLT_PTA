#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    string s;
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; i++){
        getline(cin, s);
        cout<<s<<"\nAI: ";
        string r = "";
        for(int j=0; j<s.size(); j++){
            if(s[j] != 'I') r += tolower(s[j]);
            else r += s[j];
        }
        r = regex_replace(r, regex(" +"), " ");  // 多余空格变一个
        r = regex_replace(r, regex("^ | $"), ""); // 去除收尾空格
        r = regex_replace(r, regex(" (\\W)"), "$1"); // 删除标点前面的空格
        
        r = regex_replace(r, regex("\\?"), "!");   //  ？换成！
        r = regex_replace(r, regex("\\b(I|me)\\b"), "A");
        r = regex_replace(r, regex("\\bcan you\\b"), "B");
        r = regex_replace(r, regex("\\bcould you\\b"), "C");
        r = regex_replace(r, regex("A"), "you");
        r = regex_replace(r, regex("B"), "I can");
        r = regex_replace(r, regex("C"), "I could");
        cout<<r<<endl;
    }
    return 0;
}
