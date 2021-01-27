/*
核心公式
1. si = a1+a2+...+ai
2. sum(L,R) = al +　al+1 +...+aR = sr - sl-1 (l-1>=0,下标从1开始)

做法：
1.预处理前缀和数组
2.用公式求区间和
*/

#include<iostream>
using namespace std;

const int N = 100010;

int n,m;
int a[N],s[N];

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];

    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}