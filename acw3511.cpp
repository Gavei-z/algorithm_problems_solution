//
// Created by 10263 on 2022/8/22.
//
#include "iostream"
#include "utility"
#include "set"

using namespace std;

typedef pair<int, int> PII;
int a[3];
set<PII> ab;
set<int> cc;

void pour(int arr[], int i, int j) {
    int t = min(arr[i], a[j] - arr[j]);
    arr[i] -= t, arr[j] += t;
}

void dfs(int u, int v, int w) {
    int b[3];
    ab.insert({u, v});
    cc.insert(w);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            b[0] = u, b[1] = v, b[2] = w;
            if (i != j) {
                pour(b, i, j);
                if (!ab.count({b[0], b[1]}))
                    dfs(b[0], b[1], b[2]);
            }
        }

}

int main() {
    while (cin >> a[0] >> a[1] >> a[2]) {
        ab.clear();
        cc.clear();
        dfs(0, 0, a[2]);
        cout << cc.size() << endl;
    }
    return 0;
}