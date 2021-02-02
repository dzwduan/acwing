//最优解一定是0-100
//只需枚举所有可能区间 [0-17] [1 18] ... [83,100]
// 如果在区间内，不变；在区间左边，变成左边界；在区间右边，变成右边界

#include<iostream>
using namespace std;

const int N=1010;
int h[N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int res = 1e8;
    //寻找区间
    for(int i=0;i+17<=100;i++){
        int l = i, r = i+17;
        int sum = 0;

        for(int i=0;i<n;i++){
            if(h[i]<l) sum+=(h[i]-l)*(h[i]-l);
            if(h[i]>r) sum+=(h[i]-r)*(h[r]-r);
        }
        res = min(sum,res);
    }
    cout<<res<<endl;
    return 0;
}