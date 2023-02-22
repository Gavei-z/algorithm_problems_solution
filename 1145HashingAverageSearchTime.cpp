//
// Created by UestcGavei711 on 2022/7/13.
//

#include "iostream"
#include "cstring"

using namespace std;

const int N = 10010;

int msize, n, m, a[N], res[N];

bool judge(int x) {
    if (x == 1)
        return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin >> msize >> n >> m;
    while (!judge(msize)) msize ++;
    memset(res, 0, sizeof res);
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        int cnt = 0;
        bool f = false;
        for (int j = 0; j < msize; ++j) {
            int idx = (x + j * j) % msize;
            cnt ++;
            if (!a[idx]) {
                a[idx] = 1;
                res[idx] = x;
                f = true;
                break;
            }
        }
        if (!f)
            printf("%d cannot be inserted.\n", x);
    }

    double sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        for (int j = 0; j <= msize; ++j) {
            sum += 1;
            int idx = (x + j * j) % msize;
            if (res[idx] == x || res[idx] == 0)
                break;
        }
    }
    printf("%.1lf\n", sum / m);
    return 0;
}