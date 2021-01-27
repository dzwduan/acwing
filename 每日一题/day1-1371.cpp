//凑货币 总和
//完全闭包问题 dp
//状态方程 f[i,j] = f[i-1,j-v] + f[i,j-v]


#include<iostream>
using namespace std;


const int N =30,M=10010;
int n,m;
long long  f[N][M];

int main(){
    cin>>n>>m;
    f[0][0] = 1;//初始状态一个货币都没有总钱数一定0，只有一种方案

    for(int i=1;i<=n;i++){
        int v;
        cin>>v; //当前货币面值
        for(int j=0;j<=m;j++){//j代表面值
            f[i][j] = f[i-1][j];
            if(j>=v) f[i][j]+=f[i][j-v];
        }
    }

    cout<<f[n][m]<<endl;
    return 0;
}

