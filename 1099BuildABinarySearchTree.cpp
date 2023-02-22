//
// Created by Gavei on 2022/4/13.
//

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
const int N = 110;
vector<int> v[110];
struct Node{
    int data, l ,r;
}node[N];
int n, cnt, maxdepth, num[N];
void dfs(int root, int depth)
{
    maxdepth = max(depth, maxdepth);
    if (node[root].l != -1)
        dfs(node[root].l, depth + 1);
    node[root].data = num[cnt++];
    if (node[root].r != -1)
        dfs(node[root].r, depth + 1);
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        node[i].l = a, node[i].r = b;
    }
    for(int i = 0; i < n; ++i) cin >> num[i];
    sort(num, num + n);
    dfs(0,0);
    v[0].push_back(0);
    for (int i = 0; i <= maxdepth; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            if (i) cout << " ";
            cout << node[v[i][j]].data;
            if (node[v[i][j]].l != -1) v[i+1].push_back(node[v[i][j]].l);
            if (node[v[i][j]].r != -1) v[i+1].push_back(node[v[i][j]].r);
        }
    }
    return 0;
}