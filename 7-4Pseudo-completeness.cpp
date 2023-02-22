//
// Created by 10263 on 2022/9/4.
//
#include "iostream"
#include "vector"
#include "cstring"
#include "map"
#include "queue"

using namespace std;

const int N = 2010;
int n, in[N], pre[N];
map<int, int> l, r, fa, fa2;
map<int, bool> is_leaf;
vector<int> v, leaf;
vector<int> v2;


int build(int pl, int pr, int il, int ir)
{
    int ro = pre[pl]; // 根节点权值
    int ropos = 0;
    while (in[ropos] != ro) ropos++;
    if (ropos > il)
        l[ro] = build(pl + 1, ropos - 1 - il + pl + 1, il, ropos - 1);

    if (ropos < ir)
        r[ro] = build(ropos + 1 - ir + pr, pr,ropos + 1, ir);

    return ro;
}
void post(int root)
{
    // root 根节点的值
    if (l.count(root)) {
        fa[l[root]] = root; // 记录儿子的父亲
        post(l[root]);
    }
    if (r.count(root)) {
        fa[r[root]] = root;
        post(r[root]);
    }

    if (!l.count(root) && !r.count(root)) {
        // 如果没有左右儿子， 就是叶节点
        leaf.push_back(root);
        is_leaf[root] = true;
    }

    v.push_back(root);
}

bool judge1(int root) {
    bool res = true;
    // 所有非叶子节点有左右儿子，而且所有叶子有相同的深度
    for (int i = 0; i < v.size(); ++i) {
        int node = v[i];
        if (!is_leaf[node]) {
            if (!l.count(node) || !r.count(node))
                res = false;
        }
    }
    int depth = 0, cnt = 0;
    for (int i = 0; i < leaf.size(); ++i) {
        // 遍历所有叶子， 得到深度
        int node = leaf[i];
        int tdepth = 0;
        while (fa.count(node)) {
            node = fa[node];
            tdepth += 1;
        }
        if (tdepth != depth)
        {
            depth = tdepth;
            cnt ++;
        }
    }
    if (cnt > 1)
        res = false;
    return res;
}

bool level(int root)
{
    bool res = true;
    int lcnt = 0;
    queue<int> q;
    q.push(root);
    if (is_leaf[root])
        lcnt ++;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        if (!is_leaf[top]) {
            // 如果不是叶子
            if ((!l.count(top) || !r.count(top)) && lcnt < leaf.size()) {
                res = false;
                break;
            }
        }

        if (l.count(top)) {
            q.push(l[top]);
            if (is_leaf[l[top]])
                lcnt++;
        }
        if (r.count(top)) {
            q.push(r[top]);
            if (is_leaf[r[top]])
                lcnt ++;
        }
    }
    return res;
}

bool judge2(int root)
{
    bool res = true;
    for (int i = 0; i < v.size(); ++i) {
        int node = v[i];
        if (!is_leaf[node])
        {
            if (!l.count(node) || !r.count(node))
                res = false;
        }
    }
    bool res2 = level(root);
    return (res && res2);
}



int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    for (int i = 0; i < n; ++i)
        cin >> pre[i];
    int root = build(0, n - 1, 0, n - 1);
    post(root);

    if (judge1(root)) {
        cout << 1 << endl;
    }
    else if (judge2(root)) {
        cout << 2 << endl;
    }
//    else if (judge3(root)) {
//        cout << 3 << endl;
//    }
    else
        cout << 0 << endl;

    bool is_first = true;
    for (int i = 0; i < v.size(); ++i) {
        if (is_first)
            cout << v[i], is_first = false;
        else
            cout << ' ' << v[i];
    }
    return 0;
}