//
// Created by 10263 on 2022/9/3.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 110;

int n, m, maxd = -1;
string g[N];

bool st[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
struct Node {
    int x, y, d;
};
Node s;
vector<Node> a;
vector<int> tpath;
vector<vector<int>> path;
void dfs(Node u) {
    if (u.d > maxd) {
        a.clear();
        a.push_back(u);
        return;
    } else if (u.d == maxd) {
        a.push_back(u);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int xx = u.x + dx[i];
        int yy = u.y + dy[i];
        if (!st[xx][yy] && xx >= 0 && xx < n && yy >= 0 && yy < m) {
            st[xx][yy] = true;
            dfs({xx, yy, u.d + 1});
            st[xx][yy] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < m; ++j)
            if (g[i][j] == 'X')
                s = {i, j, 0};
    }
    st[s.x][s.y] = true;
    dfs(s);
    st[s.x][s.y] = false;
    // 在所有a点到达终点路径种选择最小路径p1
    for (int i = 0; i < a.size(); ++i) {
        int x = a[i].x, y = a[i].y;
        dfs2(x, y);
    }
    sort(path.begin(), path.end());
    vector<int> p1 = path[0];
    // 在所有空地运行p1 ,得到？点
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

        }
    }
    // 在 所有节点？到达终点的路径种 选最小路径p2
    // 在剩余？点运行p2得到新的？点 知道？点为0

    return 0;
}