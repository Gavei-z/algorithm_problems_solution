//
// Created by Gavei on 2022/5/24.
//

#include "iostream"
#include "vector"

using namespace std;

const int N = 1010, M = 10010;
int n, m, k, in[N], tin[N];
vector<int> v[N];
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in[b] ++, tin[b]++;
    }
    cin >> k;
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j) in[j] = tin[j];
        vector<int> path;
        bool judge = true;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            path.push_back(x);
        }
        for (int j = 0; j < n; ++j) {
            if (in[path[j]] != 0){
                judge = false;
                break;
            }
            for (int l = 0; l < v[path[j]].size(); ++l) {
                in[v[path[j]][l]]--;
            }
        }
        if (!judge) res.push_back(i);
    }
    cout << res[0];
    for (int i = 1; i < res.size(); ++i)
        cout << " " << res[i];
    return 0;
}