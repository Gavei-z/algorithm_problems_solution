//
// Created by UestcGavei on 2022/9/29.
//
#include "iostream"

using namespace std;

const int N = 100010;
int n, a[N], stk[N], tt = 0;
int main() {
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        while (tt > 0 && stk[tt] >= x)
            tt --;
        if (tt > 0)
            cout << stk[tt] << ' ';
        else cout << - 1 << ' ';
        stk[++ tt] = x;
    }
    return 0;
}