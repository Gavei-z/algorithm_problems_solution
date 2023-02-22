//
// Created by 10263 on 2022/9/3.
//
#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int n, k;
long long minx = 1e11;
vector<long long> v;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        long long x;
        scanf("%lld", &x);
        int l = v.size();
        if (l < k)
            v.push_back(x), minx = min(x, minx);
        else if (x > minx) {
            // 替换最小值
            for (int j = 0; j < l; ++j) {
                if (v[j] == minx) {
                    v.erase(v.begin() + j);
                    v.push_back(x);
                }
            }
            // 更新最小值
            minx = 1e11;
            for (int m = 0; m < v.size(); ++m)
                minx = min(v[m], minx);
        }
    }
    sort(v.begin(), v.end(), greater<long long>());
    bool is_first = true;
    for (int i = 0; i < v.size() && i < k; ++i) {
        if (is_first)
            cout << v[i], is_first = false;
        else
            cout << ' ' << v[i];
    }
    return 0;
}