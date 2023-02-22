//
// Created by 10263 on 2022/8/23.
//
#include "iostream"
#include "vector"
#include "map"

using namespace std;
vector<int> v;
map<char, char> l, r;
string pre, in;

char build(int pl, int pr, int il, int ir) {
    char ro = pre[pl];
    int ropos = 0;
    while (in[ropos] != ro)
        ropos++;
    if (il < ropos)
        l[ro] = build(pl + 1, ropos - 1 - il + pl + 1, il, ropos - 1);
    if (ir > ropos)
        r[ro] = build(ropos + 1 - ir + pr, pr, ropos + 1, ir);
    return ro;
}

void post(char root) {
    if (l.count(root))
        post(l[root]);
    if (r.count(root))
        post(r[root]);
    cout << root;
}

int main() {
    while (cin >> pre >> in) {
        l.clear(), r.clear();
        char root = build(0, pre.length() - 1, 0, in.length() - 1);
        post(root);
        cout << endl;
    }
    return 0;
}