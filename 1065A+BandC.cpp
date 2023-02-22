//
// Created by Gavei on 2022/3/24.
//

#include "iostream"

using namespace std;

bool judge(long long a, long long b, long long c) {
    long long d = a + b;
    if (a > 0 && b > 0 && d < 0) return true;
    if (a < 0 && b < 0 && d >= 0) return false; // d >= 0 ?
    return a + b > c;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (judge(a, b, c)) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
}