//
// Created by UestcGavei711 on 2022/5/18.
//

#include "iostream"
#include "cstring"
#include "vector"

using namespace std;
const int N = 1010;
int n, lo[N];
bool isMax = false, isMin = false;
vector<int> path;
void dfs(int node){
    path.push_back(lo[node]);
    if (node * 2 > n){
        cout << path[0];
        for (int i = 1; i < path.size(); ++i) {
            cout << " " << path[i];
            if (path[i] <= path[i - 1])
                isMax = true;
            if (path[i] >= path[i - 1])
                isMin = true;
        }
        cout << endl;

    }
    if (2 * node + 1 <= n) dfs(2 * node + 1);
    if (2 * node <= n) dfs(2 * node);
    path.pop_back();
}
int main(){
    cin >> n;
    memset(lo, -1, sizeof lo);
    for (int i = 1; i <= n; ++i)
        cin >> lo[i];
    dfs(1);
    if (isMax && isMin)
        cout << "Not Heap";
    else if (isMin)
        cout << "Min Heap";
    else
        cout << "Max Heap";
    return 0;
}