//
// Created by 10263 on 2022/8/27.
//
#include "iostream"
#include "cmath"
#include "algorithm"


using namespace std;
const int N = 20;
int n, a[N], path[N], res;
bool st[N];

bool judge(int pos) {
    if (pos == 0)
        return true;
    int num = path[pos] + path[pos - 1];
    int t = sqrt(num);
    if (t * t == num)
        return true;
    return false;
}

void dfs(int u) {
    if (u == n) {
        res += 1;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (i && a[i] == a[i - 1] && !st[i - 1])
            continue;
        if (!st[i]) {
            path[u] = a[i];
            st[i] = true;
            if (judge(u))
                dfs(u + 1);
            st[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    dfs(0);
    cout << res << endl;
    return 0;
}