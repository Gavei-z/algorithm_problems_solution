//
// Created by Gavei on 2022/4/9.
//

#include "iostream"
#include "vector"
#include "cstring"
using namespace std;

const int N = 510;
int n, m, S, T;
int d[N][N], c[N][N];
int dist[N], pre[N], cost[N];
bool st[N];
void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    memset(cost,0x3f,sizeof cost);
    dist[S] = 0; cost[S] = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 0; j < n; ++j) {
            if(!st[j]&&(t == -1||dist[j] < dist[t]))
                t = j;
        }
        st[t] = true;
        for (int j = 0; j < n; ++j) {
            if (dist[j] > dist[t] + d[t][j]){
                pre[j] = t, cost[j]  = cost[t] + c[t][j];
                dist[j] = dist[t] + d[t][j];
            }
            else if(dist[j] == dist[t] + d[t][j] && cost[j] > cost[t] + c[t][j])
                pre[j] = t, cost[j] = cost[t] + c[t][j];
        }
    }
}
int main() {
    cin >> n >> m >> S >> T;
    memset(d,0x3f,sizeof d);
    memset(c,0x3f,sizeof c);

    for (int i = 0; i < m; ++i) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        d[a][b] = d[b][a] = x;
        c[a][b] = c[b][a] = y;
    }

    dijkstra();
    vector<int> path;
    for (int i = T; i != S ; i = pre[i])
        path.push_back(i);
    cout << S ;
    for (int i = path.size()-1; i >= 0 ; --i) {
        cout << " " <<path[i];
    }
    cout << " " << dist[T] << " " << cost[T];
    return 0;
}