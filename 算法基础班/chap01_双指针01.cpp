/*
https://www.acwing.com/problem/content/801/
*/

#include<iostream>
using namespace std;

const int N = 100005;
int a[N],s[N];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    int res = 0;
    for(int i=0,j=0;i<n;i++){
        s[a[i]]++;
        //如果输入的a[i]和之前的a[i-1]重复，j就向前移动
        while(j<=i && s[a[i]]>1){
            //注意顺序 先减少值再移动j,否则报错
            s[a[j]]--;
            j++;
        }

        res = max(res,i-j+1);
    }
    cout << res;
    return 0;
}