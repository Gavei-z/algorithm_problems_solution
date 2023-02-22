//
// Created by Gavei on 2022/5/14.
//

#include "iostream"
#include "map"
#include "vector"
#include "algorithm"

using namespace std;
int k, n;
vector<int> pre, in;
map<int, int> pos, l, r;
bool res = true;

int build(int il, int ir, int pl, int pr) {
    int ro = pre[pl];
    int ropos = pos[abs(ro)];
    if (ropos < il || ropos > ir){
        res = false;
        return 0;
    }
    if (il < ropos)
        l[ro] = build(il, ropos - 1, pl + 1, ropos - 1 - il + pl + 1);
    if (ropos < ir)
        r[ro] = build(ropos + 1, ir, ropos - 1 - il + pl + 1 + 1, pr);
    return ro;
}

void judge1(int root) {
    if (root < 0 && (l[root] < 0 || r[root] < 0)) {
        res = false;
        return;
    }
    if (l.count(root))
        judge1(l[root]);
    if (r.count(root))
        judge1(r[root]);
}

int getNum(int root) {
    int ln = 0, rn = 0;
    if (l.count(root))
        ln = getNum(l[root]);
    if (r.count(root))
        ln = getNum(r[root]);
    return root > 0 ? max(ln, rn) + 1 : max(ln, rn);
}

void judge2(int root) {
    int lcnt = 0, rcnt = 0;
    if (l.count(root))
        lcnt = getNum(l[root]);
    if (r.count(root))
        rcnt = getNum(r[root]);
    if (lcnt != rcnt) {
        res = false;
        return;
    }
    if (l.count(root))
        judge2(l[root]);
    if (r.count(root))
        judge2(r[root]);
}

int main() {
    cin >> k;
    while (k--) {

        pre.clear();in.clear();
        pos.clear();l.clear();r.clear();
        res = true;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            pre.push_back(t);
            in.push_back(abs(t));
        }
        sort(in.begin(), in.end());
        for (int i = 0; i < n; ++i) pos[in[i]] = i;
        // 二叉搜索数的中序遍历是有序的
        int root = build(0, n - 1, 0, n - 1);
        if (root < 0)
            res = false;
        judge1(root);
        judge2(root);
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}