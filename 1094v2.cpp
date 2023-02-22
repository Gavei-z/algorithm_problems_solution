//
// Created by Gavei on 2022/5/15.
//

#include "iostream"
#include "vector"

using namespace std;

const int N = 110;
int n, m, maxnum = 1, level = 1, book[N];
bool g[N][N];
vector<int> v[N];
void dfs(int node, int depth){
    book[depth] ++;
    for (int i = 1; i <= n; ++i) {
        if (g[node][i])
            dfs(i, depth + 1);
    }
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            int t; cin >> t;
            g[id][t] = true;
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        if (book[i] > maxnum)
        {
            maxnum = book[i];
            level = i;
        }
    cout << maxnum << " " << level;
    return 0;
}