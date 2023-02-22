//
// Created by UestcGavei711 on 2022/6/3.
//

#include "iostream"
#include "vector"
#include "cstring"
#include "algorithm"

using namespace std;

const int N = 210;

int n, m, k, g[N][N];
bool st[N];
vector<int> nodes;

bool check(int j, vector<int> lst) {
    for (int i1 = 0; i1 < lst.size(); ++i1) {
        if (!g[j][lst[i1]])
            return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        int l;
        cin >> l;
        memset(st, 0 ,sizeof st);
        vector<int> v(l);
        for (int j = 0; j < l; ++j)
            cin >> v[j], st[v[j]] = true;
        bool judge = true, judge2 = true; // 彼此是朋友
        for (int j = 0; j < l; ++j)
            for (int i1 = j + 1; i1 < l; ++i1)
                if (!g[v[j]][v[i1]]) {
                    judge = false;
                    break;
                }
        int moreone;
        for (int j = 1; j <= n; ++j)
            if (!st[j] && check(j, v)) {
                moreone = j;
                judge2 = false;
                break;
            }
        if (judge && judge2)
            printf("Area %d is OK.\n", i);
        else if (judge && !judge2)
            printf("Area %d may invite more people, such as %d.\n", i, moreone);
        else
            printf("Area %d needs help.\n", i);


    }
    return 0;
}