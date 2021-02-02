//假设末尾有k个0
//结果 n!/10^k mod 10
//如何求k的个数  质因数分解，看2和5的个数，k=min(α，b)
// n!/10^k = 2^(a-k)*5^(b-k)*p1^a1 * p2^a2 ... pn^an
// a*b mod c = a mod c  * b mod c

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int res = 1, d2 = 0, d5 = 0;
    //求2和5质因数个数，对每个数都求一遍，因为是阶乘！
    for (int i = 1; i <= n; i++)
    {
        //注意i不能变
        int x = i;
        while (x % 2 == 0)
            x /= 2, d2++;
        while (x % 5 == 0)
            x /= 5, d5++;
        res = res * x % 10;
    }

    int k = min(d2, d5);

    for (int i = 0; i < d2 - k; i++)
        res = res * 2 % 10;
    for (int i = 0; i < d5 - k; i++)
        res = res * 5 % 10;

    cout << res << endl;
    return 0;
}
