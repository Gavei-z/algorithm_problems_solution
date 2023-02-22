//
// Created by 10263 on 2022/9/4.
//
#include "iostream"
#include "vector"

using namespace std;
const int N = 100010;

int n, t, m[N];
vector<int> fol[N]; // 每个人的关注
vector<int> fans[N]; // 每个人的粉丝
vector<int> ol;
vector<int> res;
bool st[N];
int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &m[i]); // 用户i关注人数
        for (int j = 0; j < m[i]; ++j) {
            int x;
            scanf("%d", &x);
            fol[i].push_back(x);
            fans[x].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        // 计算每个人的OLI
        if (fans[i].size() >= t * fol[i].size()) {
            ol.push_back(i);
            st[i] = true;
        }
    }

    int maxn = 0;
    for (int i = 0; i < ol.size(); ++i) {
        int cnt = 0;
        for (int j = 0; j < fans[ol[i]].size(); ++j) {
            if (st[fans[ol[i]][j]])
                cnt ++;
        }
        if (cnt > maxn) {
            maxn = cnt;
            res.clear();
            res.push_back(ol[i]);
        }
        else if (cnt == maxn)
            res.push_back(ol[i]);
    }

    bool is_first = true;
    for (int i = 0; i < res.size(); ++i) {
        if (is_first)
            cout << res[i], is_first = false;
        else
            cout << ' ' << res[i];
    }
    return 0;
}