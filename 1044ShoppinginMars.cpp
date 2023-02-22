//
// Created by 10263 on 2022/8/12.
//

#include "iostream"
#include "cmath"
#include "vector"

using namespace std;

const int N = 100010;
int n, m, a[N], sum[N];

void solution1() {
    vector<int> ri, rj;
    int rs = 1 << 20;
    for (int i = 1, s = 0; i <= n; ++i)
        scanf("%d", &a[i]), s += a[i], sum[i] = s;
    for (int i = 1, j = 1; i <= n; ++i) {
        for (; j <= i && sum[i] - sum[j - 1] >= m; ++j) {
            int t = sum[i] - sum[j - 1];
            if (t - m >= 0 && t- m < rs) {
                rs = t - m;
                ri.clear();ri.push_back(i);
                rj.clear();rj.push_back(j);
            }
            else if (t - m >= 0 && t - m == rs)
                ri.push_back(i), rj.push_back(j);
        }
    }
    for (int i = 0; i < ri.size(); ++i)
        printf("%d-%d\n", rj[i], ri[i]);
}

void solution2() {
    vector<int> ri, rj;
    int rs = 1 << 20;
    for (int i = 1, s = 0; i <= n; ++i)
        scanf("%d", &a[i]), s += a[i], sum[i] = s;
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (sum[mid] - sum[i - 1] >= m) r = mid; else l = mid + 1;
        }
        int t = sum[l] - sum[i - 1];
        if (t - m < rs && t - m >= 0) {
            rs = t - m;
            ri.clear();ri.push_back(i);
            rj.clear();rj.push_back(l);
        }
        else if (t - m == rs && t - m >= 0)
            ri.push_back(i), rj.push_back(l);
    }
    for (int i = 0; i < ri.size(); ++i)
        printf("%d-%d\n", ri[i], rj[i]);
}
int main() {
    cin >> n >> m;
    solution2();
    return 0;
}