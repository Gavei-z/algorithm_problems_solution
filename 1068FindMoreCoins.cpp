//
// Created by Gavei on 2022/7/10.
//

#include "iostream"
#include "algorithm"

using namespace std;

const int N = 10010, M = 110;
int n, m, dp[N][M], v[N], c[N][M];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    sort(v + 1, v + 1 + n, greater<int>());
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j >= v[i]) {
                if (v[i] + dp[i - 1][j - v[i]] > dp[i - 1][j]) {
                    dp[i][j] = v[i] + dp[i - 1][j - v[i]];
                    c[i][j] = v[i];
                } else
                    dp[i][j] = dp[i - 1][j];
            } else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[n][m] != m)
        cout << "No Solution";
    else {
        bool is_first = true;
        while (n) {
            if ( m >= v[n] && dp[n - 1][m - v[n]] == (m - v[n])) {
                if (is_first) {
                    cout << v[n];
                    is_first = false;
                } else
                    cout << " " << v[n];
                m -= v[n];
            }
            n--;
        }

    }
    return 0;
}