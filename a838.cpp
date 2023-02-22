//
// Created by 10263 on 2022/10/14.
//
#include "iostream"

using namespace std;

const int N = 100010;
int n, m, h[N], sz;

void down(int x) {
    int t = x;
    if (2 * x <= sz && h[2 * x] < h[t])
        t = 2 * x;
    if (2 * x + 1 <= sz && h[2 * x + 1] < h[t])
        t = 2 * x + 1;
    if (t != x)
    {
        swap(h[x], h[t]);
        down(t);
    }
}

int main() {
    cin >> n >> m;
    sz = n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = n / 2; i; i--)
        down(i);

    while (m--) {
        cout << h[1] << ' ';
        swap(h[1], h[sz]);
        sz--;
        down(1);
    }
    return 0;
}