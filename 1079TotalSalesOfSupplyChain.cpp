//
// Created by Gavei on 2022/2/26.
//

#include "iostream"
#include "vector"
#include "cmath"

using namespace std;
struct Node {
    int data;
    vector<int> child;
};
vector<Node> v;
int n;
double res, p, r;

void dfs(int node, int depth) {
    if (v[node].child.size() == 0) {
        res += 1.0 * v[node].data * p * pow(1 + r / 100, depth);
        return;
    }
    for (int i = 0; i < v[node].child.size(); ++i) {
        dfs(v[node].child[i], depth + 1);
    }
}

int main() {
    cin >> n >> p >> r;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            cin >> v[i].data;
        } else {
            for (int j = 0; j < k; ++j) {
                int temp;
                cin >> temp;
                v[i].child.push_back(temp);
            }
        }
    }

    dfs(0, 0);
    printf("%.1lf",res);
    return 0;
}