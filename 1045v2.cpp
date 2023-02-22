//
// Created by UestcGavei711 on 2022/7/8.
//

#include "iostream"
#include "algorithm"

using namespace std;

const int N =210, L =10010;

int n, m, l;
int pos[N], dp[L], c[L];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        pos[x] = i;
    }

    cin >> l;
    int cnt = 1;
    for (int i = 1; i <= l; ++i) {
        int x;
        cin >> x;
        if (pos[x] != 0)
            c[cnt++] = x;
    }
    for (int i = 1; i <= cnt - 1; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (pos[c[i]] >= pos[c[j]])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp + 1, dp + 1 + cnt);
    return 0;
}