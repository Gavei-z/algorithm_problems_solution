//
// Created by UestcGavei on 2022/9/29.
//
#include "iostream"

using namespace std;
const int N = 100010;

int q[N], n, hh, tt = -1;

int main() {
    cin >> n;
    while (n--)
    {
        string op;
        int x;
        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[++ tt] = x;
        } else if (op == "pop")
        {
            if (hh <= tt)
                hh ++;
        } else if (op == "empty") {
            if (hh > tt)
                puts("YES");
            else
                puts("NO");
        } else if(op == "query")
            cout << q[hh] << endl;
    }

    return 0;
}