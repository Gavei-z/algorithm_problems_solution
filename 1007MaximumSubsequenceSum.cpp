//
// Created by Gavei on 2022/3/29.
//

#include "iostream"

using namespace std;
const int N = 10010;
int w[N];

int main() {
    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> w[i];
    }
    int res = -1, l, r;
    for (int i = 1, f = -1, start = 0; i <= k; ++i) {
        if (f < 0) f = 0, start = i;
        f = w[i] + max(0, f);
        if (res < f){
            res = f;
            l = w[start];
            r = w[i];
        }
    }
    if (res < 0) cout << 0 <<' ' << w[1] <<' ' << w[k];
    else cout << res << ' ' << l << ' ' << r;
    return 0;
}