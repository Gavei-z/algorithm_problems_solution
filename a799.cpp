//
// Created by UestcGavei on 2022/9/19.
//

#include "iostream"

using namespace std;
const int N = 100010;

int n, a[N];
int st[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        st[a[i]] ++;
        while (st[a[i]] > 1) {
            st[a[j]] --;
            j ++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}