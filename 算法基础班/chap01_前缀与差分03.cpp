/*
差分 https://www.acwing.com/problem/content/799/

给定 a1 a2 ... an
构造差分数组 bn 使得：
ai = b1 + b2 + ...+ bi  

核心操作：
将a[l~R] 全部加上c 等价于 b[L]+=c, b[R+1] -=c

时间复杂度 o(n) -> o(1)
*/

#include<iostream>
using namespace std;

const int N = 1e+5+5;

int n,m;
int a[N],b[N];

//核心
void insert(int l,int r, int c){
    b[l]+=c;
    b[r+1] -=c;
}

int main(){
    cin>>n>>m;
    int num;
    for(int i=1;i<=n;i++){
        cin >> num;
        insert(i,i,num); //构造差分数组
    }

    //对差分数组l~r上进行+c操作
    while(m--){
        int l,r,c;
        cin >> l >> r>>c;
        insert(l,r,c); 
    }

    //累加和即结果
    for(int i=1;i<=n;i++) a[i] = a[i-1] + b[i]; 
    for(int i=1;i<=n;i++) cout<< a[i]<<' ';

    return 0;
}