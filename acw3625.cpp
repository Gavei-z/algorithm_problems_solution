//
// Created by 10263 on 2022/8/23.
//
#include "iostream"

using namespace std;
typedef long long LL;
const int MOD = 233333;
int x,n;

LL qmi(int a, int q)
{
    LL res = 1;
    while (q)
    {
        if (q & 1) res = (LL) (res * a) % MOD;
        q >>= 1;
        a = (LL) a * a % MOD;
    }
    return res;
}
int main() {
    cin >> x >> n;
    cout << qmi(x, n) << endl;
    return 0;
}