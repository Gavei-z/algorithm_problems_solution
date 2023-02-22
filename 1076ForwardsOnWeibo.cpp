//
// Created by Gavei on 2022/5/21.
//

#include "iostream"
#include "vector"
#include "queue"
#include "cstring"
using namespace std;
const int N = 1010;
int n, l, k, level[N];
vector<int> v[N];

int bfs(int start) {
    queue<int> q;
    q.push(start);
    int res = 0;
    bool book[N] = {false};
    book[start] = true;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        int tl = level[top];
        if (tl < l) {
            for (int i = 0; i < v[top].size(); ++i) {
                if (!book[v[top][i]]) {
                    book[v[top][i]] = true;
                    q.push(v[top][i]);
                    level[v[top][i]] = tl + 1;
                    res++;
                }

            }
        }
    }
    return res;
}

int main() {
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d", &x);
            v[x].push_back(i);
        }
    }
    cin >> k;
    while (k--) {
        int id;
        cin >> id;
        memset(level, 0, sizeof level);
        printf("%d\n", bfs(id));
    }
    return 0;
}