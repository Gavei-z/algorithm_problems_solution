//
// Created by 10263 on 2022/9/24.
//
#include "iostream"

using namespace std;

const int N = 100010;
int a[N], tt;
int m;
void push(int x) {
    a[++ tt] = x;
}
void pop() {
    tt --;
}
int main() {
    cin >> m;
    while (m--)
    {
        string op;
        int x;
        cin >> op;
        if (op == "push")
        {
            cin >> x;
            push(x);
        } else if (op == "pop")
            pop();
        else if (op == "query")
            cout << a[tt] << endl;
        else {
            if (tt > 0)
                puts("NO");
            else
                puts("YES");
        }
    }
    return 0;
}