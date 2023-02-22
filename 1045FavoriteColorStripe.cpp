//
// Created by UestcGavei711 on 2022/7/8.
//

#include "iostream"

using namespace std;

const int N = 210;
int n, m, l;
int fav[N], color[10010], dp[N][10010];

int main(){
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> fav[i];
    cin >> l;
    for (int i = 1; i <= l; ++i)
        cin >> color[i];
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= l; ++j) {
            if (fav[i] == color[j])
                dp[i][j] = max(dp[i][j - 1] + 1, dp[i-1][j]);
            else
                dp[i][j] = max(dp[i][j - 1], dp[i-1][j]);
        }
    }
    cout << dp[m][l];
    return 0;
}