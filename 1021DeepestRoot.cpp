//
// Created by 10263 on 2022/8/28.
//
/*#include "iostream"
#include "vector"
#include "cstring"

using namespace std;
const int N = 10010;
int n, p[N], md = 0;
int st[N];
vector<int> v[N];
vector<int> res;

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int dfs(int u) {
    int depth = 0;
    for (int i = 0; i < v[u].size(); ++i) {
        if (!st[v[u][i]]) {
            st[v[u][i]] = 1;
            depth = max(depth, dfs(v[u][i]) + 1);
        }
    }
    return depth;
}

int main() {
    for (int i = 1; i <= N; ++i)
        p[i] = i;
    md = 0;
    cin >> n;
    int k = n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        int fa = find(a), fb = find(b);
        if (fa != fb) {
            p[fb] = fa;
            k--;
        }
    }
    if (k != 1)
        printf("Error: %d components\n", k);
    else {
        for (int i = 1; i <= n; ++i) {
            memset(st, 0, sizeof st);
            st[i] = 1;
            int t = dfs(i);
            if (t > md) {
                md = t;
                res.clear();
                res.push_back(i);
            } else if (t == md)
                res.push_back(i);
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}*/

//
// Created by Gavei on 2022/4/26.
//

#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

const int N = 10010;
vector<int> v[N], node;
int n, p[N], maxdepth;
bool vis[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int dfs(int x) {
    vis[x] = true;
    int depth = 0;
    for (int i = 0; i < v[x].size(); ++i)
        if (vis[v[x][i]] == false)
            depth = max(depth, dfs(v[x][i]) + 1);
    return depth;
}

int main() {
    cin >> n;
    int k = n; // 一开始有n个集合
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i <= n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        if (find(a) != find(b)) {
            p[find(a)] = find(b);
            k--;
        }
    }
    if (k != 1)
        printf("Error: %d components", k);
    else {
        for (int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof vis);
            int deep = dfs(i);
            if (deep > maxdepth) {
                maxdepth = deep;
                node.clear();
                node.push_back(i);
            } else if (deep == maxdepth) {
                node.push_back(i);
            }
        }
        for (int i = 0; i < node.size(); ++i)
            cout << node[i] << endl;
    }
    return 0;
}
