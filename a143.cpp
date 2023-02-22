//
// Created by 10263 on 2022/10/8.
//
#include "iostream"

using namespace std;
const int N = 100010, M = 3000000;
int son[M][2], idx, a[N];
int n;

void insert (int x) {
    int p = 0;
    for (int i = 30; ~i; --i) {
        int &s = son[p][x >> i & 1];
        if (!s)
            s = ++ idx;
        p = s;
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; ~i; --i) {
        int s = x >> i & 1;
        if (son[p][!s]){
            res += 1 << i;
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }
    return res;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = max(res, query(a[i]));
    cout << res << endl;
    return 0;
}