//
// Created by 10263 on 2023/1/2.
//
#include "iostream"

using namespace std;
typedef long long LL;

const int N = 500010;
int n, l[N], r[N];
string str;
int main() {
    cin >> n;
    cin >> str;
    LL res = 0;
    for (int i = 0, h = 0, g = 0; i < n; ++ i) {
        if (str[i] == 'G') l[i] = h, h = 0, g++;
        else
            l[i] = g, g = 0, h ++;
    }

    for (int i = n - 1, h = 0, g = 0; ~i; -- i) {
        if (str[i] == 'G') r[i] = h, h = 0, g++;
        else
            r[i] = g, g = 0, h ++;
    }

    for (int i = 0; i < n; ++i) {
        res += (LL)l[i] * r[i] + max(l[i] - 1, 0) + max(r[i] - 1, 0);
    }
    cout << res << endl;
    return 0;
}