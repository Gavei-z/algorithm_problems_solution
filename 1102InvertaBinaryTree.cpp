//
// Created by 10263 on 2022/8/31.
//
#include "iostream"
#include "vector"
#include "queue"
#include "cstring"

using namespace std;

const int N = 20;
int n, l[N], r[N], fa[N];
vector<int> res_in;
void dfs(int ro)
{
    int t = l[ro];
    l[ro] = r[ro];
    r[ro] = t;
    if (l[ro] != -1)
        dfs(l[ro]);
    if (r[ro] != -1)
        dfs(r[ro]);
}

void level(int ro)
{
    queue<int> q;
    q.push(ro);
    vector<int> v;
    while (!q.empty())
    {
        int top = q.front();
        v.push_back(top);
        q.pop();
        if (l[top] != -1)
            q.push(l[top]);
        if (r[top] != -1)
            q.push(r[top]);
    }
    bool is_first = true;
    for (int i = 0; i < v.size(); ++i) {
        if (is_first)
            cout << v[i], is_first = false;
        else
            cout << ' ' << v[i];
    }
    cout << endl;
}

void in(int ro)
{
    if (l[ro] != -1)
        in(l[ro]);
    res_in.push_back(ro);
    if (r[ro] != -1)
        in(r[ro]);
}
int main() {
    memset(fa, -1, sizeof fa);
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char a, b;
        cin >> a >> b;
        if (a != '-')
            l[i] = a - '0', fa[a - '0'] = i;
        if (b != '-')
            r[i] = b - '0', fa[b - '0'] = i;
    }
    int ro = 0;
    while (fa[ro] != -1)
        ro ++;
    dfs(ro);
    level(ro);
    in(ro);
    bool f = true;
    for (int i = 0; i < res_in.size(); ++i) {
        if (f)
            cout << res_in[i], f = false;
        else
            cout << ' ' << res_in[i];
    }
    return 0;
}