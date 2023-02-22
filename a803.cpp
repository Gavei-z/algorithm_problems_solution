//
// Created by UestcGavei on 2022/9/22.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
typedef pair<int, int> PII;
vector<PII> v;

int n;
const int N = 100010;

vector<PII> merge() {
    vector<PII> res;
    int st = -2e9, ed = -2e9;
    for (auto s:v) {
        if (s.first > ed) {
            if (st != -2e9)
                res.push_back({st, ed});
            st = s.first, ed = s.second;
        } else
            ed = max(ed, s.second);
    }
    if (st != -2e9)
        res.push_back({st, ed});
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    sort(v.begin(), v.end());
    vector<PII> res = merge();
    cout << res.size() << endl;
}