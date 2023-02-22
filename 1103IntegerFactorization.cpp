//
// Created by UestcGavei711 on 2022/7/2.
//

#include "iostream"
#include "cmath"
#include "vector"

using namespace std;

int n, k, p, v[30], S = -1;
vector<int> path, t_path;

void dfs(int num, int i, int sum, int cnt) {
    if (num == 0 && cnt == k) {
        if (sum > S) {
            S = sum;
            path = t_path;
            return;
        }
    }

    // 当前这个数字有i种取法
    for (int j = i; j >= 1; --j) {
        if (num - v[j] >= 0) {
            t_path.push_back(j);
            dfs(num - v[j], j, sum + j, cnt + 1);
            t_path.pop_back();
        }
    }
}

int main() {
    cin >> n >> k >> p;
    int i = 1;
    for (; pow(i, p) <= n; ++i) {
        v[i] = pow(i, p);
    }
    i -= 1;
    dfs(n, i, 0, 0);
    if (S == -1)
        puts("Impossible");
    else {
        printf("%d = ", n);
        bool is_first = true;
        for (int j = 0; j < path.size(); ++j) {
            if (is_first) {
                printf("%d^%d", path[j], p);
                is_first = false;
            } else {
                printf(" + %d^%d", path[j], p);
            }
        }
    }
    return 0;
}