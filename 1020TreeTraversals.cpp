//
// Created by Gavei on 2022/4/20.
//

#include "iostream"
#include "algorithm"
#include "map"
#include "queue"
using namespace std;

const int N = 40;
int n, postorder[N], inorder[N];
map<int, int> pos, l, r;

int build_tree(int il, int ir, int pl, int pr) {
    // pr为根
    int ro = postorder[pr], rpos = pos[ro];
    if (il < rpos)
        l[ro] = build_tree(il, rpos - 1, pl, rpos - 1 - il + pl);
    if (ir > rpos)
        r[ro] = build_tree(rpos + 1, ir, rpos - il + pl, pr - 1);
    return ro;
}

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        cout << top << " ";
        if (l.count(top)) cout << l[top];
        if (r.count(top)) cout << r[top];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> postorder[i];
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }

    int root = build_tree(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}