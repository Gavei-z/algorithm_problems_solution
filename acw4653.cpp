//
// Created by 10263 on 2023/1/4.
//
#include "iostream"
#include "utility"
#include "vector"
#include "algorithm"

using namespace std;

typedef pair<int, int> PII;
vector<PII> v;
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        int sum = 0, num = i;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        v.push_back(make_pair(sum, i));
    }
    sort(v.begin(), v.end());
    cout << v[m - 1].second << endl;
    return 0;
}