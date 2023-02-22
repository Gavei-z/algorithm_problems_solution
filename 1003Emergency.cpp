//
// Created by Gavei on 2022/3/30.
//

#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;

int edge[510][510], v[510], dist[510], sum[510], cnt[510];
bool st[510];
int n, m, c1, c2;

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[c1] = 0;
    sum[c1] = v[c1], cnt[c1] = 1;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 0; j < n; ++j)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;

        for (int j = 0; j < n; ++j) {
            if (dist[j] > dist[t] + edge[t][j]) {
                dist[j] = dist[t] + edge[t][j];
                sum[j] = sum[t] + v[j];
                cnt[j] = cnt[t];
            } else if (dist[j] == dist[t] + edge[t][j]) {
                cnt[j] += cnt[t];
                sum[j] = max(sum[j], sum[t] + v[j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    memset(edge, 0x3f, sizeof edge);
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        edge[a][b] = edge[b][a] = min(edge[a][b], l);
    }
    dijkstra();
    cout << cnt[c2] << " " << sum[c2];
    return 0;
}
//
//#include <cstring>
//#include <iostream>
//
//using namespace std;
//
//const int N = 510;
//
//int n, m, S, T;
//int w[N], d[N][N];
//int dist[N], cnt[N], sum[N];
//bool st[N];
//
//void dijkstra()
//{
//    memset(dist, 0x3f, sizeof dist);
//    dist[S] = 0, cnt[S] = 1, sum[S] = w[S];
//
//    for (int i = 0; i < n; i ++ )
//    {
//        int t = -1;
//        for (int j = 0; j < n; j ++ )
//            if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                t = j;
//        st[t] = true;
//
//        for (int j = 0; j < n; j ++ )
//            if (dist[j] > dist[t] + d[t][j])
//            {
//                dist[j] = dist[t] + d[t][j];
//                cnt[j] = cnt[t];
//                sum[j] = sum[t] + w[j];
//            }
//            else if (dist[j] == dist[t] + d[t][j])
//            {
//                cnt[j] += cnt[t];
//                sum[j] = max(sum[j], sum[t] + w[j]);
//            }
//    }
//}
//
//int main()
//{
//    cin >> n >> m >> S >> T;
//
//    for (int i = 0; i < n; i ++ ) cin >> w[i];
//
//    memset(d, 0x3f, sizeof d);
//    while (m -- )
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        d[a][b] = d[b][a] = min(d[a][b], c);
//    }
//
//    dijkstra();
//
//    cout << cnt[T] << ' ' << sum[T] << endl;
//
//    return 0;
//}
//
