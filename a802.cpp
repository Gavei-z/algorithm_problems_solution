//
// Created by UestcGavei on 2022/9/22.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
typedef pair<int, int> PII;
const int N = 300010;

int n, m, a[N], s[N];
vector<int> all;
vector<PII> query, add;

int find(int x)
{
    int l = 0, r = all.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (all[mid] >= x) r = mid;
        else
            l = mid + 1;
    }
    return l + 1;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        query.push_back({a, b});
        all.push_back(a);
        all.push_back(b);
    }
    // 去重
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    // 处理插入
    for (int i = 0; i < n; ++i) {
        int x = add[i].first, c = add[i].second;
        a[find(x)] += c;
    }

    // 处理查询
    for (int i = 1; i <= all.size(); ++i)
        s[i] = s[i- 1] + a[i];

    for (int i = 0; i < query.size(); ++i) {
        int l = find(query[i].first), r = find(query[i].second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}