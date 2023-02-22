//
// Created by Gavei on 2022/5/7.
//

#include "iostream"
#include "stack"
#include "vector"
#include "cstring"

using namespace std;
const int N = 40;
int n, l[N], r[N], pos[N];
stack<int> s;
vector<int> pre, in, post;

int dfs(int il, int ir, int pl, int pr){
    int root = pre[pl];
    int rp = pos[root];
    if (il < rp)
        l[root] = dfs(il, rp - 1, pl + 1, rp - il + pl);
    if (rp < ir)
        r[root] = dfs(rp + 1, ir, rp - il + pl + 1, pr);
    return root;
}
void posttravesal(int node){
    if (l[node] != -1)
        posttravesal(l[node]);
    if (r[node] != -1)
        posttravesal(r[node]);
    post.push_back(node);
}
int main(){
    cin >> n;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for (int i = 0; i < 2 * n; ++i) {
        string op;
        cin >> op;
        if (op == "Push"){
            int node;
            cin >> node;
            s.push(node);
            pre.push_back(node);
        }
        else{
            in.push_back(s.top());
            pos[s.top()] = in.size() - 1;
            s.pop();
        }
    }
    int root = dfs(0, n - 1, 0, n - 1);
    posttravesal(root);
    cout << post[0];
    for (int i = 1; i < post.size(); ++i)
        cout << " " << post[i];
    return 0;
}