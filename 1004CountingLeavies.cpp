//
// Created by Gavei on 2022/4/3.
//

#include "iostream"
#include "vector"

using namespace std;
vector<int> v[110];
int n, m, maxdepth;
int record[110];

void dfs(int node, int depth) {
    if(v[node].empty()){
        record[depth] ++;
        maxdepth = max(depth, maxdepth);
        return ;
    }
    for (int i = 0; i < v[node].size(); ++i) {
        dfs(v[node][i], depth + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        while (k--) {
            int t;
            cin >> t;
            v[id].push_back(t);
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= maxdepth; ++i) {
        if (i != 0)
            cout <<" ";
        cout << record[i];
    }
    return 0;

}