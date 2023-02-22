//
// Created by Gavei on 2022/8/4.
//

#include "iostream"
#include "algorithm"

using namespace std;
const int N = 100010;
int n, p, a[N];

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + res; j < n; ++j) {
            if ((long long)a[i] * p >= a[j])
                res = max(res, j - i + 1);
            else
                break;
        }
    }
    cout << res << endl;
    return 0;
}