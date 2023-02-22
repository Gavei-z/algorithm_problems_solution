#include "iostream"
#include "queue"

using namespace std;

const int M = 1300, N = 130, L = 70;
int g[M][N][L], vis[M][N][L];
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int m, n, l, t;
struct Node {
    int x, y, z;
};

bool judge(int x, int y, int z) {
    if (x >= 0 && x < m && y >=0 && y < n && z >= 0 && z < l)
        return true;
    return false;
}

int bfs(int i, int j, int k) {
    vis[i][j][k] = 1;
    queue<Node> q;
    q.push({i, j, k});
    int cnt = 1;
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        for (int i1 = 0; i1 < 6; ++i1) {
            int xx = top.x + dx[i1];
            int yy = top.y + dy[i1];
            int zz = top.z + dz[i1];
            if (judge(xx, yy, zz) && !vis[xx][yy][zz] && g[xx][yy][zz] == 1) {
                q.push({xx, yy, zz});
                vis[xx][yy][zz] = 1;
                cnt += 1;
            }
        }
    }
    if (cnt >= t)
        return cnt;
    return 0;
}

int main() {
    cin >> m >> n >> l >> t;
    for (int k = 0; k < l; ++k)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> g[i][j][k];

    int res = 0;
    for (int k = 0; k < l; ++k)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (g[i][j][k] && !vis[i][j][k])
                    res += bfs(i, j, k);
            }


    cout << res << endl;
    return 0;
}