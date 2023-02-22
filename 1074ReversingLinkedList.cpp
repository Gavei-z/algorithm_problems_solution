//
// Created by UestcGavei711 on 2022/7/23.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 100010;
int s, n, k, e[N], ne[N];
vector<vector<int>> v;

int main() {
    cin >> s >> n >> k;
    for (int i = 0; i < n; ++i) {
        int add, num, next;
        cin >> add >> num >> next;
        e[add] = num;
        ne[add] = next;
    }
    vector<int> t;
    int cnt = 0;
    while (s != -1) {
        t.push_back(s);
        cnt++;
        if (cnt % k == 0) {
            reverse(t.begin(),t.end());
            v.push_back(t);
            t.clear();
        }
        s = ne[s];
    }
    if (t.size())
        v.push_back(t);

    vector<int> res;
    for (int i = 0; i < v.size(); ++i) {
        vector<int> t = v[i];
        for (int j = 0; j < t.size(); ++j)
            res.push_back(t[j]);
    }

    for (int i = 0; i < res.size(); ++i) {
        printf("%05d %d ", res[i], e[res[i]]);
        if (i == res.size() -1)
            cout << -1 << endl;
        else
            printf("%05d\n", res[i + 1]);
    }
    return 0;
}