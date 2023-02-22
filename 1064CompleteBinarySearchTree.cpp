//
// Created by Gavei on 2022/3/23.
//

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
vector<int> v, tr;

int n, k;

void dfs(int pos) {
    if (2 * pos <= n) dfs(2 * pos);
    tr[pos] = v[k++];
    if(2 * pos + 1 <= n) dfs(2 * pos + 1);
}

int main() {

    cin >> n;
    v.resize(n);
    tr.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    dfs(1);
    for (int i = 1; i <= n; ++i) {
        if(i != 1) cout << " ";
        cout << tr[i];
    }
    return 0;
}