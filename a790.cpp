//
// Created by 10263 on 2022/9/8.
//
#include "iostream"

using namespace std;

int main() {
    double n;
    cin >> n;
    double l = -10000, r = 10000;
    while (l + 1e-8 < r)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n)
            r = mid;
        else
            l = mid;
    }
    printf("%lf\n", l);
    return 0;
}