//
// Created by Gavei on 2022/5/31.
//

#include "iostream"
#include "cstring"
#include "vector"
using namespace std;
const int N = 510;
int n, m, edge1[N][N], edge2[N][N], dist1[N], dist2[N], S, T;

pair<int, string> dijkstra(int e1[][N], int e2[][N], int type){
    int cost[N] = {0};
    memset(cost, 0x3f, sizeof cost);
    cost[S] = 0;
    int pre[N];
    bool st[N] = {false};
    memset(dist1, 0x3f, sizeof dist1);
    memset(dist2, 0x3f, sizeof dist2);
    dist1[S] = 0;
    dist2[S] = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 0; j < n; ++j) {
            if (!st[j] && (t == -1 || dist1[j] < dist1[t]))
                t = j;
        }
        st[t] = true;

        for (int j = 0; j < n; ++j) {
            if (dist1[j] > dist1[t] + e1[t][j]){
                dist1[j]  = dist1[t] + e1[t][j];
                if (type == 0)
                    cost[j] = cost[t] + e2[t][j];
                else
                    cost[j] = cost[t] + 1;
                pre[j] = t;
            }
            else if (dist1[j] == dist1[t] + e1[t][j]) {
                if (cost[j] > cost[t] + type == 0 ? e2[t][j] : 1){
                    cost[j] = cost[t] + type == 0 ? e2[t][j] : 1;
                    pre[j] = t;
                }
            }
        }
    }
    vector<int> path;
    for (int i = T; i != S; i = pre[i])
        path.push_back(i);
    string res = to_string(S);
    for (int i = path.size() - 1; i >=0 ; --i) {
        res += "->" + to_string(path[i]);
    }
    return {dist1[T], res};
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, o, l, t;
        cin >> a >> b >> o >> l >> t;
        edge1[a][b] = l;
        edge2[a][b] = t;
        if (!o) {
            edge1[b][a] = edge1[a][b];
            edge2[b][a] = edge2[a][b];
        }
    }
    cin >> S >> T;
    auto res1 = dijkstra(edge1, edge2, 0);
    auto res2 = dijkstra(edge2, edge1, 1);
    if (res1.second == res2.second)
        printf("Distance = %d; Time = %d: %s\n", res1.first, res2.first, res1.second.c_str());
    else{
        printf("Distance = %d: %s\n", res1.first, res1.second.c_str());
        printf("Time = %d: %s\n", res2.first, res2.second.c_str());
    }
    return 0;
}