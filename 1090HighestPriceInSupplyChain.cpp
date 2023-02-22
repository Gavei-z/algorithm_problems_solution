//
// Created by Gavei on 2022/2/12.
//
#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

const int N = 100010;
vector<int> v[N];
int n, root;
double p, r;
int MaxDepth,num;


void dfs(int node, int depth) {
    if (v[node].size() == 0) {
        if (depth == MaxDepth)
            num++;
        else if (depth > MaxDepth) {
            num = 1;
            MaxDepth = depth;
        }
        return;

    }
    for (int i = 0; i < v[node].size(); ++i) {
        dfs(v[node][i], depth + 1);
    }
}

int main() {
    cin >> n >> p >> r;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp == -1)
            root = i;
        else{
            v[temp].push_back(i); // push_back了儿子
//            for(int j = 0; j < v[temp].size(); ++j)
//                cout<<v[temp][j]<<" ";
        }

    }
    dfs(root, 0);
    printf("%.2f %d", p * pow(1 + r / 100, MaxDepth), num);
    return 0;
}