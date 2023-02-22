//
// Created by UestcGavei711 on 2022/7/12.
//

#include "iostream"
#include "unordered_set"
#include "unordered_map"
#include "vector"

using namespace std;

int n, m;
unordered_map<int, vector<int>> mp;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        int a[100000] = {0};
        vector<int> v;
        bool f = true;
        for (int j = 0; j < k; ++j) {
            int x;
            scanf("%d", &x);
            v.push_back(x);
            a[x] = 1;
        }
        for (int j = 0; j < v.size(); ++j) {
            int x = v[j];
            for (int l = 0; l < mp[x].size(); ++l) {
                if (a[mp[x][l]]) {
                    f = false;
                }
            }
        }
        if (f)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}