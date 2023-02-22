//
// Created by Gavei on 2022/7/16.
//

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

const int N = 10010;

int n, p[N], c[N], hc[N], ha[N];
bool st[N];

struct Edge {
    int a, b;
}E[N];
struct Family {
    int head, cnt, e, a;
    bool operator <(const Family &t) const {
        // a / cnt ? t.a / t.cnt
        if (a * t.cnt != t.a * cnt)
            return a * t.cnt > t.a * cnt;
        else
            return head < t.head;
    }
};
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main() {
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int id, fa, ma, k;
        cin >> id >> fa >> ma >> k;
        st[id] = true;
        if (fa != -1)
            E[cnt++] = {id, fa};
        if (ma != -1)
            E[cnt++] = {id, ma};
        for (int j = 0; j < k; ++j) {
            int son;
            cin >> son;
            E[cnt++] = {id, son};
        }
        cin >> hc[id] >> ha[id];
    }

    for (int i = 0; i < N; ++i)
        p[i] = i, c[i] = 1;

    for (int i = 0; i < cnt; ++i) {
        int a = E[i].a, b = E[i].b;
        st[a] = true; st[b] = true;
        int pa = find(a), pb = find(b);
        if (pa != pb)
        {
            if (pa > pb)
                swap(pa, pb);
            c[pa] += c[pb];
            hc[pa] += hc[pb];
            ha[pa] += ha[pb];
            p[pb] = pa;
        }
    }

    vector<Family> f;
    for (int i = 0; i < N; ++i) {
        if (st[i] && p[i] == i)
            f.push_back({i, c[i], hc[i], ha[i]});
    }
    sort(f.begin(), f.end());
    cout << f.size() << endl;
    for (int i = 0; i < f.size(); ++i)
        printf("%04d %d %.3lf %.3lf\n", f[i].head, f[i].cnt, (double) f[i].e / f[i].cnt, (double) f[i].a / f[i].cnt);

    return 0;
}