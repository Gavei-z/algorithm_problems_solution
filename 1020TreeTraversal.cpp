//
// Created by UestcGavei711 on 2022/4/22.
//
// 输入后序遍历和中序遍历，输出层序遍历
#include "iostream"
#include "map"
#include "queue"

using namespace std;

const int N = 40;
int n, postorder[N], inorder[N], res[N], rescnt;
map<int, int> pos, l, r;

int build(int il, int ir, int pl, int pr) {
    int R = postorder[pr];
    int Rpos = pos[R];
    if (il < Rpos) l[R] = build(il, Rpos - 1, pl, Rpos - 1 - il + pl);
    if (ir > Rpos) r[R] = build(Rpos + 1, ir, Rpos - 1 - il + pl + 1, pr - 1);
    return R;
}

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        res[rescnt++] = top;
        if (l.count(top)) q.push(l[top]);
        if (r.count(top)) q.push(r[top]);
    }
    for (int i = 0; i < rescnt; ++i) {
        if (i)
            cout << " ";
        cout << res[i];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> postorder[i];
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    int root = build(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}
