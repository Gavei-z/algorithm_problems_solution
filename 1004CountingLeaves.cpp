#include "iostream"
#include "vector"

using namespace std;

const int N = 110;
int n, m, maxdepth;
int l[N];
vector<int> v[N];

void dfs(int u, int depth)
{
    maxdepth = max(maxdepth, depth);
    if (!v[u].size())
        l[depth] += 1;
    for (int i = 0; i < v[u].size(); ++i) {
        int t = v[u][i];
        dfs(t, depth + 1);
    }
}
int main() {
    cin >> n >> m;
    while (m--)
    {
        int id, k;
        cin >> id >> k;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            v[id].push_back(x);
        }
    }
    dfs(1,0);
    bool is_first = true;
    for (int i = 0; i <= maxdepth; ++i) {
        if (is_first)
            cout << l[i], is_first = false;
        else
            cout << ' ' << l[i];
    }
    return 0;
}