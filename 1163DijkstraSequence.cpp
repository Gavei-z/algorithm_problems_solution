//
// Created by 10263 on 2022/8/14.
//

#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

const int N = 1010;
int nv, ne, k, edge[N][N], dist[N];
bool st[N];

void dij(int s) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[s] = 0;
    for (int i = 1; i <= nv; ++i) {
        int t = -1;
        for (int j = 1; j <= nv; ++j)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        for (int j = 1; j <= nv; ++j) {
            if (dist[j] > dist[t] + edge[t][j])
                dist[j] = dist[t] + edge[t][j];
        }
    }
}


int main() {
    memset(edge, 0x3f, sizeof edge);
    cin >> nv >> ne;
    while (ne--) {
        int a, b, l;
        cin >> a >> b >> l;
        edge[a][b] = edge[b][a] = l;
    }
    cin >> k;
    while (k--) {
        bool res = true;
        vector<int> v;
        for (int i = 0; i < nv; ++i) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        dij(v[0]);
//        for (int i = 1; i < nv; ++i)
//            cout << dist[v[i]] << " ";
        for (int i = 0; i + 1 < nv; ++i) {
            if (dist[v[i + 1]] < dist[v[i]])
                res = false;
        }
        if (res)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}