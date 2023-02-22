//
// Created by Gavei on 2022/5/26.
//

#include "iostream"
#include "vector"

using namespace std;

const int N = 110;
int n, k, line[10000][10000]; // pair
vector<int> v[N], path, tpath;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int m, pre;
        scanf("%d %d", &m, &pre);
        for (int j = 0; j < m - 1; ++j) {
            int t;
            scanf("%d", &t);
            line[pre][t] = i;
            pre = t;
        }
    }
    cin >> k;
    while (k--) {
        int S, E;
        dfs(S, E);

    }


    return 0;
}