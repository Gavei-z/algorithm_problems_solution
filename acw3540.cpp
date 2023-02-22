//
// Created by 10263 on 2022/8/25.
//
#include "iostream"
#include "cstring"

using namespace std;
const int N = 110;
int n, v[N], l[N], r[N], w[N], idx;
bool st[N];
void insert(int& u, int x) {
    if (!u)
        u = ++idx, w[u] = x;
    else if (x < w[u])
        insert(l[u], x);
    else if (x > w[u])
        insert(r[u], x);
}
void pre(int root) {
    cout << w[root] << " ";
    if (l[root])
        pre(l[root]);
    if (r[root])
        pre(r[root]);
}
void in(int root) {
    if (l[root])
        in(l[root]);
    cout << w[root] << " ";
    if (r[root])
        in(r[root]);
}

void post(int root) {
    if (l[root])
        post(l[root]);
    if (r[root])
        post(r[root]);
    cout << w[root] << " ";
}
int main() {
    memset(w, -1, sizeof w);
    cin >> n;
    int root = 0;
    for (int i = 1; i <= n; ++i)
        cin >> v[i], insert(root, v[i]);
    pre(1);
    cout << endl;

    in(1);
    cout << endl;
    post(1);
    return 0;
}