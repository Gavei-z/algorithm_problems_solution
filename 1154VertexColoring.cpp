#include "iostream"
#include "set"
using namespace std;

const int N = 10010;

int n, m, k, color[N];

struct edge {
    int a, b;
} E[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> E[i].a >> E[i].b;
    cin >> k;
    set<int> s;
    for (int j = 1; j <= k; ++j) {
        s.clear();
        for (int i = 0; i < n; ++i) cin >> color[i];

        bool res = true;
        for (int i = 0; i < m; ++i) {
            if (color[E[i].a] == color[E[i].b])
                res = false;
            else{
                s.insert(E[i].a);
                s.insert(E[i].b);
            }
        }
        if (res)
            printf("%d-coloring\n", s.size());
        else
            cout << "No" << endl;
    }
    return 0;
}