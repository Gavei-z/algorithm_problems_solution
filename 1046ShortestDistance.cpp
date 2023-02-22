//
// Created by Gavei on 2022/8/3.
//

#include "iostream"

using namespace std;
const int N = 100010;
int n, m, s[N], sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        sum += x;
        s[i] = sum;
    }
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int l = s[b - 1] - s[a - 1];
        int res = min(l, sum - l);
        cout << res << endl;
    }
    return 0;
}