#include <iostream>
#include <vector>
using namespace std;

const int N = 50010;

vector<int> v[N];

int n, r1, r2;
int p[N];

void dfs(int u, int fa) {
    p[u] = fa;
    for (int i:v[u]) {
        if (i != fa) {
            p[i] = u;
            dfs(i, u);
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &r1, &r2);
    for (int i = 1; i <= n; ++i) {
        if (i != r1) {
            int fa;
            cin >> fa;
            v[i].push_back(fa);
            v[fa].push_back(i);
        }
    }
    
    dfs(r2, -1);
    for (int i = 1; i <= n; ++i) 
        if (i != r2)
            cout << p[i] << ' ';
    
    return 0;
}