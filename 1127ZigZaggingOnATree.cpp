//
// Created by Gavei on 2022/5/8.
//

#include "iostream"
#include "cstring"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;
const int N = 40;
int n, in[N],post[N], pos[N], l[1000], r[1000], level[N], maxtop;

int build(int il, int ir, int pl, int pr){
    int ro = post[pr];
    int rpos = pos[ro];
    if (il < rpos)
        l[ro] = build(il, rpos - 1, pl, rpos - 1 - il + pl);
    if (rpos < ir)
        r[ro] = build(rpos + 1, ir, rpos - 1 - il + pl + 1, pr - 1);
    return ro;
}
void bfs(int root, vector<int> *result){
    queue<int> q;
    q.push(root);
    level[root] = 0;
    while(!q.empty()){
        int temp = q.front();
        int toplevel = level[temp];
        maxtop = max(maxtop, toplevel);
        result[toplevel].push_back(temp);
        q.pop();
        if (l[temp] != -1){
            q.push(l[temp]);
            level[l[temp]] = toplevel + 1;
        }
        if (r[temp] != -1){
            q.push(r[temp]);
            level[r[temp]] = toplevel + 1;
        }
    }
}
int main(){

    cin >> n;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for(int i = 0; i < n; ++i) cin >> in[i], pos[in[i]] = i;
    for(int i = 0; i < n; ++i) cin >> post[i];
    int root = build(0, n - 1, 0, n - 1);
    vector<int> result[N];
    bfs(root, result);
    cout << result[0][0];
    for (int i = 1; i <= maxtop; ++i) {
        if (i % 2 == 0)
            for (int j = result[i].size() - 1; j >= 0; --j)
                cout << " " << result[i][j];
        else
            for (int j = 0; j < result[i].size(); ++j)
                cout << " " << result[i][j];
    }
    return 0;
}