//
// Created by 10263 on 2022/8/14.
//

#include "iostream"
#include "cstring"

using namespace std;

const int N = 30;
int n;
string d[N];
int l[N], r[N], pre[N];

void post(int root)
{
    cout << "(";
    if (l[root] == -1 && r[root] != -1) {
        cout << d[root];
        post(r[root]);
        cout << ")";
    } else {
        if (l[root] != -1)
            post(l[root]);
        if (r[root] != -1)
            post(r[root]);
        cout << d[root] << ")";
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i] >> l[i] >> r[i];
        if (l[i] != -1)
            pre[l[i]] = i;
        if (r[i] != -1)
            pre[r[i]] = i;
    }
    int ro = 1;
    while (pre[ro] != 0) ro++;
    post(ro);
    return 0;
}