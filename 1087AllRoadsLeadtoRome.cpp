//
// Created by Gavei on 2022/2/10.
//
#include "iostream"
#include "map"
#include "vector"

using namespace std;

const int N = 210;
const int inf = 1 << 20;
int n, k;
int dis[N], weigh[N], edge[N][N];
int cntpath, maxsum;
double maxavg;
map<string, int> m1;
map<int, string> m2;
vector<int> pre[N], tmppath, path;
bool visit[N];

void dfs(int v) {
    tmppath.push_back(v);
    if (v == 1) {
        int sum = 0;
        for (int i = 0; i < tmppath.size() - 1; ++i) {
            sum += weigh[tmppath[i]];
        }
        double avg = 1.0 * sum / (tmppath.size() - 1);
        if (sum > maxsum) {
            maxsum = sum;
            path = tmppath;
            maxavg = avg;
        } else {
            if (sum == maxsum && avg > maxavg) {
                maxavg = avg;
                path = tmppath;
            }
        }
        cntpath++;
        tmppath.pop_back();
        return;
    }
    for (int i = pre[v].size() - 1; i >= 0; --i)
    {
        dfs(pre[v][i]);
    }
    tmppath.pop_back();

}

int main() {
    fill(edge[0], edge[0]+N*N,inf);
    fill(dis, dis+N,inf);
    cin >> n >> k;
    string sc;
    cin >> sc;
    // 给城市编号，出发城市编号1
    m1[sc] = 1;
    m2[1] = sc;
    for (int i = 1; i <= n - 1; ++i) {
        string city;
        cin >> city >> weigh[i + 1];
        m1[city] = i + 1;
        m2[i + 1] = city;
    }
    for (int i = 0; i < k; ++i) {
        string c1, c2;
        cin >> c1 >> c2 >> edge[m1[c1]][m1[c2]];
        edge[m1[c2]][m1[c1]] = edge[m1[c1]][m1[c2]];

    }
    dis[1] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, mindis = inf;
        for (int j = 1; j <= n; ++j) {
            if (!visit[j] && dis[j] < mindis) {
                u = j;
                mindis = dis[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = true;

        // 更新最短路径
        for (int v = 1; v <= n; ++v) {
            if (!visit[v] && edge[u][v] != inf) { // 在集合U中
                if (dis[v] > dis[u] + edge[u][v]) {
                    pre[v].clear();
                    pre[v].push_back(u);
                    dis[v] = dis[u] + edge[u][v];
                } else {
                    if (dis[v] == dis[u] + edge[u][v])
                        pre[v].push_back(u);
                }
            }
        }
    }
    int rom = m1["ROM"];
    dfs(rom);
    cout << cntpath <<" "<< dis[rom] <<" "<< maxsum <<" "<< (int) maxavg << endl;
    for(int i = path.size() - 1; i >= 1; --i)
    {
        cout << m2[path[i]] << "->";
    }
    cout<<"ROM";
    return 0;
}