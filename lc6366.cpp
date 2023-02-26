// lc problem 6366, q4 of single week competition 334
// The main algorithm is dijkstra with heap optimized
// The shortest distance update need a few tricks, dis[i][j] has the
// same odevity with i + j in a grid.
//

class Solution {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        const int INF = 0x3f3f3f3f;
        int n = grid.size(), m = grid[0].size();
        int dis[n][m];
        memset(dis, 0x3f, sizeof dis);
        dis[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(0, 0, 0);
        while (q.size()) {
            auto [d, x, y] = q.top();
            q.pop();
            for (int i = 0; i < 4; ++ i) {
                int xx = x + dir[i][0], yy = y + dir[i][1];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || dis[xx][yy] != INF)
                    continue;
                int nd = max(d + 1, grid[xx][yy]);
                nd += (nd - xx - yy) % 2;
                if (nd < dis[xx][yy]) {
                    dis[xx][yy] = nd;
                    q.emplace(nd, xx, yy);
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};
