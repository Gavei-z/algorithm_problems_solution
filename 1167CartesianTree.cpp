//
// Created by 10263 on 2022/8/18.
//
// 给一个小顶堆的中序遍历，要求输出层序遍历

#include "iostream"
#include "map"
#include "queue"
#include "vector"

using namespace std;
map<int, int> le, ri;
vector<int> res;
const int N = 50;
int n, in[N];

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int top = q.front();
        res.push_back(top);
        q.pop();
        if (le.count(top))
            q.push(le[top]);
        if (ri.count(top))
            q.push(ri[top]);
    }
    for (int i = 0; i < res.size(); ++i) {
        if (!i)
            cout << res[i];
        else
            cout << " " << res[i];
    }
}

int build(int l, int r) {
    int ro = 1 << 20, ropos = -1;
    for (int i = l; i <= r; ++i)
        if (in[i] < ro)
            ro = in[i], ropos = i;
    if (l < ropos)
        le[ro] = build(l, ropos - 1);
    if (r > ropos)
        ri[ro] = build(ropos + 1, r);
    return ro;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    int root = build(0, n - 1);
    bfs(root);
    return 0;
}