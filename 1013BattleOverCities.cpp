//
// Created by Gavei on 2022/4/12.
//

#include "iostream"

using namespace std;

const int N = 1010;
int n, m ,k, d[N][N];
bool vis[N];
void dfs(int node)
{
    vis[node] = true;
    for (int i = 1; i <=n ; ++i) {
        if (vis[i] == false && d[node][i] == 1)
            dfs(i);
    }
}
int main(){
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        d[a][b] = d[b][a] = 1;
    }
    for (int i = 0; i < k; ++i) {
        int a, cnt = 0;
        cin >> a;
        fill(vis, vis + 1010, false);
        vis[a] = true;
        for (int j = 1; j <= n; ++j) {
            if (vis[j] == false)
                dfs(j), cnt++;
        }
        printf("%d\n", cnt-1);
    }
    return 0;
}