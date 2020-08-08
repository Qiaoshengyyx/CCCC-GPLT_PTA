#include<bits/stdc++.h>
using namespace std;
int main(){
    int num=0,sum;
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]!='6') cout<<s[i];
        else{
            sum=0;
            while(i!=s.length() && s[i]=='6' ){
                sum++;
                i++;
            }
            i--;
            if(sum>3 && sum<=9) cout<<'9';
            else if(sum>9) cout<<"27";
            else{
                for(int k=0;k<sum;k++)
                    cout<<'6';
            }
        }
    }
    return 0;
}
