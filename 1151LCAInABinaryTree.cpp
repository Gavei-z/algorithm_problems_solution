//
// Created by UestcGavei711 on 2022/5/18.
//

#include "iostream"
#include "vector"
#include "map"

using namespace std;

const int N = 10010;
int n, m, pre[N], in[N];
//map<int, bool> M;
map<int, int> pos;

int LCA(int il, int ir, int pl, int u, int v) {
    int ro = pre[pl];
    int ropos = pos[ro], upos = pos[u], vpos = pos[v];
    if ((ropos >= upos && ropos <= vpos) || (ropos >= vpos && ropos <= upos))
        return ro;
    if (upos < ropos && vpos < ropos)// 左子树
        return LCA(il, ropos - 1, pl + 1, u, v);
    if (upos > ropos && vpos > ropos)// 右子树
        return LCA(ropos + 1, ir, ropos -1 - il + pl + 1 + 1, u, v);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        pos[in[i]] = i;
//        M[in[i]] = true;
    }
    for (int i = 0; i < n; ++i) cin >> pre[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        int cntu = pos.count(u), cntv = pos.count(v);
        if (cntu == 0 && cntv == 0)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (cntu == 0 || cntv == 0)
            printf("ERROR: %d is not found.\n", cntu == 0 ? u : v);
        else {
            int lca = LCA(0, n - 1, 0, u, v);
            if (lca == u || lca == v)
                printf("%d is an ancestor of %d.\n", lca, lca == u ? v : u);
            else
                printf("LCA of %d and %d is %d.\n", u, v, lca);
        }
    }
    return 0;
}