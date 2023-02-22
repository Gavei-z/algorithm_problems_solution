//
// Created by 10263 on 2022/8/26.
//
#include "iostream"

using namespace std;
const int N = 100010;

int n, v[N];

int main() {
    while (cin >> n) {
        int res = 0, l = 1, r = 1;
        int f[N] = {0};
        for (int i = 1; i <= n; ++i)
            cin >> v[i];
        for (int i = 1, t = 1; i <= n; ++i) {
            f[i] = max(v[i], f[i - 1] + v[i]);
            if (f[i - 1] < 0)
                t = i;
            if (f[i] > res)
                res = f[i], l = t, r = i;
        }
        cout << res << " " << l - 1 << " " << r - 1 << endl;
    }
    return 0;
}
