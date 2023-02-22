//
// Created by 10263 on 2022/9/16.
//
#include "iostream"

using namespace std;
const int N = 100010;
int n, m, a[N], b[N];
void insert(int l, int r, int v)
{
    b[l] += v;
    b[r + 1] -= v;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        insert(i, i, a[i]);
    while (m --)
    {
        int l, r, v;
        scanf("%d %d %d", &l, &r, &v);
        insert(l, r, v);
    }
    for (int i = 1; i <= n; ++i)
        b[i] += b[i - 1];
    for (int i = 1; i <= n; ++i) printf("%d ", b[i]);
    return 0;
}