//
// Created by UestcGavei711 on 2022/5/28.
//

#include "iostream"
#include "set"
#include "vector"

using namespace std;

const int N = 210;
int n, m, k;
bool g[N][N];
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }
    cin >> k;
    while (k--)
    {
        int num;
        bool res = true;
        cin >> num;
        set<int> s;
        vector<int> path;
        for (int i = 1; i <= num; ++i){
            int t;
            cin >> t;
            path.push_back(t);
            s.insert(t);
        }
        if (num != n + 1 || s.size() != n || path[0] != path[num - 1])
            res = false;
        for (int i = 1; i < path.size(); ++i) {
            if (!g[path[i - 1]][path[i]])
                res = false;
        }
        if (res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}