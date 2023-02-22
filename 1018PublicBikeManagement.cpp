//
// Created by Gavei on 2022/4/18.
//

#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

const int N = 510;
vector<int> pre[N], minpath, temppath;
int weigh[N], edge[N][N], dist[N];
bool vis[N];
int cmax, n, sp, m, minsent = 1 << 20, minback = 1 << 20;

void dfs(int sp) {
    temppath.push_back(sp);
    if (sp == 0) {
        int sent = 0, back = 0;
        for (int i = temppath.size() - 1; i >= 0; --i) {
            int id = temppath[i];
            if (weigh[id] >= 0)
                back += weigh[id];
            else if (back >= -weigh[id])
                back -= -weigh[id];
            else{
                sent += (-weigh[id] - back);
                back = 0;
            }
        }
        if (sent < minsent) {
            minsent = sent;
            minpath = temppath;
            minback = back;
        } else if (sent == minsent && back < minback) {
            minback = back;
            minpath = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < pre[sp].size(); ++i)
        dfs(pre[sp][i]);
    temppath.pop_back();
}

void dijsktra() {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    for (int i = 0; i <= n; ++i) {
        int t = -1;
        for (int j = 0; j <= n; ++j) {
            if (!vis[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        vis[t] = true;

        for (int j = 0; j <= n; ++j) {
                if (dist[j] > dist[t] + edge[t][j]) {
                    dist[j] = dist[t] + edge[t][j];
                    pre[j].clear();
                    pre[j].push_back(t);
                } else if (dist[j] == dist[t] + edge[t][j]) {
                    pre[j].push_back(t);
                }
        }
    }
}

int main() {
    memset(edge, 0x3f, sizeof edge);
    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> weigh[i];
        weigh[i] -= cmax / 2;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        edge[a][b] = edge[b][a] = min(edge[a][b], t);
    }
    dijsktra();
//    for (int i = 1; i <= n; ++i) {
//        cout << dist[i] << " ";
//    }
//    cout << endl;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j < pre[i].size(); ++j) {
//            cout << pre[i][j] << " " ;
//        }
//        cout << endl;
//    }
    dfs(sp);
    cout << minsent << " " << 0;
    for (int i = minpath.size() - 2; i >= 0 ; --i) {
        cout << "->" << minpath[i];
    }
    cout << " " <<minback;
    return 0;
}