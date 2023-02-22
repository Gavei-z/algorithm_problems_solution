//
// Created by Gavei on 2022/2/16.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
vector<int> v[110];
int n, m;
int book[110];

void dfs(int index, int depth) {
    book[depth]++;
    for (int i = 0; i < v[index].size(); ++i)
        dfs(v[index][i], depth + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            int son;
            cin >> son;
            v[id].push_back(son);
        }
    }
    dfs(1, 1);
    int maxnum = 0, maxdepth = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (book[i] > maxnum){
            maxnum = book[i];
            maxdepth = i;
        }
    }
    cout<< maxnum << " "<<maxdepth;
    return 0;
}