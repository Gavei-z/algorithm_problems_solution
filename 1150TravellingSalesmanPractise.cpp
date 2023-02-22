//
// Created by UestcGavei711 on 2022/5/23.
//

#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

const int N = 210;
int n, m, k, edge[N][N];

int main() {
    cin >> n >> m;
    memset(edge, 0x3f, sizeof edge);
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        edge[a][b] = edge[b][a] = d;
    }
    cin >> k;
    int mindis = 1 << 20, pathidx = 0;
    for (int i = 1; i <= k; ++i) {
        bool isNA = false, isfull = true, issame = true;
        int nn;
        cin >> nn;
        int book[N] = {0}, dist = 0;
        vector<int> path;
        for (int j = 0; j < nn; ++j) {
            int t;
            cin >> t;
            path.push_back(t), book[path[j]]++;
            if (j > 0 && edge[path[j]][path[j - 1]] == 0x3f3f3f3f) {
                isNA = true;
            } else if (j > 0)
                dist += edge[path[j]][path[j - 1]];
        }
        if (path[0] != path[path.size() - 1])
            issame = false;
        for (int j = 1; j <= n; ++j)
            if (book[j] == 0) {
                isfull = false;
                break;
            }
        if (dist < mindis && !isNA && isfull) {
            pathidx = i;
            mindis = dist;
        }

        if (isNA)
            printf("Path %d: NA (Not a TS cycle)\n", i);
        else if (isfull && nn == n + 1 && issame)
            printf("Path %d: %d (TS simple cycle)\n", i, dist);
        else if (isfull && nn > n + 1 && issame)
            printf("Path %d: %d (TS cycle)\n", i, dist);
        else
            printf("Path %d: %d (Not a TS cycle)\n", i, dist);
    }
    printf("Shortest Dist(%d) = %d", pathidx, mindis);
    return 0;
}