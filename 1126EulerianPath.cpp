//
// Created by Gavei on 2022/5/26.
//

#include "iostream"
#include "vector"

using namespace std;

const int N = 510;

int n, m, deg[N], cnt;
bool st[N];
vector<int> v[N];

void dfs(int node) {
    st[node] = true;
    cnt ++;
    for (int i = 0; i < v[node].size(); ++i) {
        if (!st[v[node][i]])
            dfs(v[node][i]);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    dfs(1);
    cout << deg[1];
    for (int i = 2; i <= n; ++i)
        cout << " " << deg[i];
    cout << endl;
    if (cnt == n) {
        // 连通图
        int odd = 0;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] % 2)
                odd++;
        }
        if (odd == 2)
            puts("Semi-Eulerian");
        else if (odd == 0)
            puts("Eulerian");
        else
            puts("Non-Eulerian");
    }
    else
        puts("Non-Eulerian");
    return 0;
}