//
// Created by Gavei on 2022/5/15.
//

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
const int N = 110;
int n, m, S, w[N];
bool g[N][N];
vector<vector<int>> res;
vector<int> temppath;
void dfs(int node, int s){
    temppath.push_back(w[node]);
    bool isleaf = true;
    for (int i = 0; i < n; ++i)
        if (g[node][i]){
            isleaf = false;
            break;
        }
    if (isleaf)
    {
        if (s == S)
        {
            res.push_back(temppath);
            return ;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (g[node][i])
        {
            dfs(i, s + w[i]);
            temppath.pop_back();
        }
    }
}
int main(){
    cin >> n >> m >> S;
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            int t; cin >> t;
            g[id][t] = true;
        }
    }
    dfs(0, w[0]);
    sort(res.begin(), res.end(), greater<vector<int>>());
    for (auto p: res) {
        cout << p[0];
        for (int i = 1; i < p.size(); ++i) {
            cout << " " << p[i];
        }
        cout << endl;
    }
    return 0;
}