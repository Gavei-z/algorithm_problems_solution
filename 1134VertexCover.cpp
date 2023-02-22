//
// Created by UestcGavei711 on 2022/5/26.
//

#include "iostream"

using namespace std;
const int N = 10010;
int n, m, k;
struct edge {
    int a, b;
} E[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        E[i] = {a, b};
    }
    cin >> k;
    while (k--) {
        int v;
        cin >> v;
        bool st[N] = {false};
        for (int i = 0; i < v; ++i) {
            int t;
            cin >> t;
            st[t] = true;
        }
        bool res = true;
        for (int i = 0; i < m; ++i)
            if (!st[E[i].a] && !st[E[i].b]) {
                res = false;
                break;
            }
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}