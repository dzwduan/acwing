//棋盘挑战 暴力搜索
//每行每列只有一个棋子且每个对角线上不多于一个棋子


/*
对角线最多 2*N-1条
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 15;
int n;
bool col[N],dg[N*2],udg[N*2];
int path[N],ans;

void dfs(int x){
    if(x>n){ //已经填完了前n行
        ans++;
        if(ans <=3){
            for(int i=1;i<=n;i++){
                cout<<path[i]<<' ';
            }
            cout<<endl;
        }
    }

    for(int y=1;y<=n;y++){
        if(!col[y] && !dg[x+y] && !udg[x-y+n]){//行列对角线都没有
            path[x] = y;
            col[y] = dg[x+y] = udg[x-y+n] = true; //填完标记
            dfs(x+1); //搜索下一层
            col[y] = dg[x+y] = udg[x-y+n] = false; //恢复现场
            path[x] = 0;
        }
    }
}

int main(){
    cin>>n;
    dfs(1); //从第一行开始遍历
    cout<<ans<<endl;
    return 0;
}

