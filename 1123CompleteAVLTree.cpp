//
// Created by Gavei on 2022/5/11.
//

#include "iostream"
#include "vector"
#include "queue"
using namespace std;
const int N = 30;
int n, l[N], r[N], v[N], h[N], idx, maxpos;
vector<int> levelorder;
void update(int node){
    h[node] = max(h[l[node]], h[r[node]]) + 1;
}
void L(int& u){
    int p = r[u];
    r[u] = l[p], l[p] = u;
    update(u), update(p);
    u = p;
}
void R(int& u){
    int p = l[u];
    l[u] = r[p], r[p] = u;
    update(u), update(p);
    u = p;
}
int get_balance(int u){
    return h[l[u]] - h[r[u]];
}
void insert(int& u, int w){
    if(!u)
        u = ++idx, v[u] = w;
    else if (w < v[u]) {
        insert(l[u], w);
        if (get_balance(u) == 2) {
            if (get_balance(l[u]) == 1)
                R(u);
            else
                L(l[u]), R(u);
        }
    }
    else{
        insert(r[u], w);
        if (get_balance(u) == -2){
            if (get_balance(r[u]) == -1)
                L(u);
            else
                R(r[u]), L(u);
        }
    }
    update(u);
}
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int top = q.front();
        levelorder.push_back(v[top]);
        q.pop();
        if (l[top] != 0)
            q.push(l[top]);
        if (r[top] != 0)
            q.push(r[top]);
    }
}
void dfs(int node, int pos){
    if (pos > maxpos)
        maxpos = pos;
    if (l[node] != 0)
        dfs(l[node], 2 * pos);
    if (r[node] != 0)
        dfs(r[node], 2 * pos + 1);
}
int main(){
    cin >> n;
    int root = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        insert(root, t);
    }
    // 样例数据到这没问题
    bfs(root);
    cout << levelorder[0];
    for (int i = 1; i < levelorder.size(); ++i)
        cout << " " << levelorder[i];

    dfs(root, 1);
    if (maxpos == n)
        cout << endl << "YES";
    else
        cout << endl << "NO";
    return 0;
}