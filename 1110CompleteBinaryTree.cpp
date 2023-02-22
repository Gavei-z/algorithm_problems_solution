//
// Created by Gavei on 2022/5/11.
//

#include "iostream"

using namespace std;
const int N = 30;
int n, l[N], r[N], maxpos, maxid;
bool has_father[N];
void dfs(int node, int pos)
{
    if (pos > maxpos)
    {
        maxpos = pos;
        maxid = node;
    }
    if (l[node] != -1)
        dfs(l[node], 2 * pos);
    if (r[node] != -1)
        dfs(r[node], 2 * pos + 1);
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        if (a == "-")
            l[i] = -1;
        else
            l[i] = stoi(a), has_father[l[i]] = true;
        if (b == "-")
            r[i] = -1;
        else
            r[i] = stoi(b), has_father[r[i]] = true;
    }
    int root = 0;
    while (has_father[root]) root ++;
    dfs(root, 1);
    if (maxpos == n){
        cout << "YES" << " " << maxid;
    }
    else
        cout << "NO" << " " << root;
    return 0;
}