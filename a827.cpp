//
// Created by 10263 on 2022/9/24.
//
#include "iostream"

using namespace std;

const int N = 100010;

int e[N], l[N], r[N], idx;

void ins(int k, int x)
{ // 在k右边插入一个数
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx ++;
}

void del(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int m;
int main() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
    cin >> m;
    while (m--)
    {
        string op;
        int k, x;
        cin >> op;
        if (op == "L") {
            cin >> x;
            ins(0, x);
        } else if (op == "R") {
            cin >> x;
            ins(l[1], x);
        } else if (op == "D") {
            cin >> k;
            del(k + 1);
        } else if (op == "IR") {
            cin >> k >> x;
            ins(k + 1, x);
        } else if (op == "IL") {
            cin >> k >> x;
            ins(l[k + 1], x);
        }
    }
    for (int i = r[0]; i != 1 ; i = r[i])
        cout << e[i] << ' ';
    return 0;
}