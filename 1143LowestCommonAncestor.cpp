//
// Created by UestcGavei711 on 2022/5/18.
//

#include "iostream"
#include "map"

using namespace std;
const int N = 10010;
map<int, bool> M;
int m, n, pre[N];
int main(){
    cin >> m >> n;
    for (int i = 0; i < n; ++i) cin >> pre[i], M[pre[i]] = true;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        int lca = 0;
        for (int j = 0; j < n; ++j) {
            lca = pre[j];
            if ((lca >= u && lca <= v) || (lca >= v && lca <= u))
                break;
        }
        if (!M[u] && !M[v])
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (!M[u] || !M[v])
            printf("ERROR: %d is not found.\n", !M[u] ? u : v);
        else if (lca == u || lca == v)
            printf("%d is an ancestor of %d.\n", lca, lca == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, lca);
    }
    return 0;
}