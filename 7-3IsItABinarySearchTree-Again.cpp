//
// Created by 10263 on 2022/9/3.
//
#include "iostream"
#include "cstring"
#include "vector"

using namespace std;
const int N = 10010;
int n, l[N], r[N], a[N];
vector<int> v;
bool res = true;

void in(int ro) {
    if (ro != -1 && l[ro] != -1) {
        if (a[l[ro]] >= a[ro])
            res = false;
        in(l[ro]);
    }
    v.push_back(a[ro]);
    if (ro != -1 && r[ro] != -1) {
        if (a[r[ro]] < a[ro])
            res = false;
        in(r[ro]);
    }
}

int main() {
    memset(a, -1, sizeof a);
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[2 * i] != -1)
            l[i] = 2 * i;
        if (a[2 * i + 1] != -1)
            r[i] = 2 * i + 1;
    }
    in(1);
    if (res)
        puts("YES");
    else
        puts("NO");
    bool is_first = true;
    for (int i = 0; i < v.size(); ++i) {
        if (is_first)
            cout << v[i], is_first = false;
        else
            cout << ' ' << v[i];
    }
    return 0;
}