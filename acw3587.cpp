//
// Created by 10263 on 2022/8/23.
//
#include "iostream"
#include "set"

using namespace std;

const int N = 1010;
int p[N];
int n, m;

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i)
            p[i] = i;
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            int fx = find(x), fy = find(y);
            if (fx != fy)
                p[fx] = p[fy];
        }
        set<int> s;
        for (int i = 1; i <= n; ++i)
            s.insert(find(i));
        if (s.size() == 1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}