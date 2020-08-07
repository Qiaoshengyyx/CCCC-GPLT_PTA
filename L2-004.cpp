#include<bits/stdc++.h>
using namespace std;
bool isMirror = false;
vector<int> pre,post;
int N;
void create(int left, int right){
    if(left > right) return;
    int i = left+1, j = right;
    if(!isMirror){
   
        while(i <= right && pre[left] > pre[i]) i++;
        while(j > left && pre[left] <= pre[j]) j--;
    }else{
        while(i <= right && pre[left] <= pre[i]) i++;
        while(j > left && pre[left] > pre[j]) j--;
    }
    if(i-j != 1) return;
    create(left+1, i-1);
    create(i, right);
    post.push_back(pre[left]);
}
int main(int argc, const char * argv[]) {
    scanf("%d", &N);
    pre.resize(N);
    for(int i=0; i<N; i++)
        scanf("%d", &pre[i]);
    create(0, N-1);
    if(post.size() != N){
        post.clear();
        isMirror = true;
        create(0, N-1);
        if(post.size() != N){
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for(int i=0; i<N; i++)
        printf("%s%d", i==0?"":" ", post[i]);
    return 0;
}

//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int> pre,post;
//bool isMirror=false;
//void getPost(int root, int tail){
//    int i=root+1, j=tail;
//    if(!isMirror){
//        while(i<=tail && pre[root]>pre[i]) i++; // 找到第一个大于root的下标
//        while(j>root && pre[root]<=pre[j]) j--; //找到第一个小于root的下标
//    }else{
//        while(i<=tail && pre[root]<=pre[i]) i++;
//        while(j>root && pre[root]>pre[j]) j--;
//    }
//    if(i-j!=1) return;
//    getPost(root+1, j); //左子树
//    getPost(i, tail); //右子树
//    post.push_back(pre[root]); //构造后序
//    // 构造后序遍历的结果，技巧就是利用递归的方法，找到对应的结点加入post中；
//}
//int main(){
//    int n;
//    cin>>n;
//    pre.resize(n);
//    for(int i=0;i<n;i++)
//        cin>>pre[i];
//    getPost(0,n-1);
//    if(post.size()!=n){
//        isMirror=true;
//        post.clear();
//        getPost(0, n-1);
//        if(post.size()!=n) {
//            cout<<"NO\n";
//            return 0;
//        }
//    }
//    cout<<"YES\n";
//    for(int i=0;i<n;i++){
//        if(i!=0) cout<<' ';
//        cout<<post[i];
//    }
//
//    return 0;
//}
