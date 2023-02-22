//
// Created by Gavei on 2022/3/29.
//

#include "iostream"
#include "set"
using namespace std;

double c[1010];

int main() {
    int n = 2;
    while (n--) {
        int k;
        cin >> k;
        while (k--) {
            int exp;
            double cof;
            cin >> exp >> cof;
            c[exp] += cof;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 1000; ++i) {
        if(c[i]) cnt ++;
    }
    cout << cnt;
    for (int i = 1000; i >= 0; --i) {
        if (c[i] != 0.0) printf(" %d %.1lf", i,c[i]);
    }
    return 0;
}