//
// Created by 10263 on 2022/8/18.
//

#include "iostream"
#include "cstring"

using namespace std;

const int N = 1010;

int t, s, g[N][N], f[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int dfs(int i, int j)
{
    if (f[i][j] != -1)
        return f[i][j];
    f[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
        int a = i + dx[k], b = j + dy[k];
        if (a >= 0 && a < s && b >= 0 && b < s && g[a][b] == g[i][j] + 1)
            f[i][j] = max(f[i][j], dfs(a, b) + 1);
    }
    return f[i][j];
}
int main() {
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        memset(f, -1, sizeof f);
        cin >> s;
        for (int i = 0; i < s; ++i)
            for (int j = 0; j < s; ++j)
                cin >> g[i][j];
        int cnt = 0, res = s * s + 1;
        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < s; ++j) {
                int t = dfs(i, j);
                if (t > cnt || t == cnt && g[i][j] < res)
                    cnt = t, res = g[i][j];
            }
        }
        printf("Case #%d: %d %d\n", k, res, cnt);
    }
    return 0;
}