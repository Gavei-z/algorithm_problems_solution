//
// Created by Gavei on 2022/4/4.
//

#include "iostream"

using namespace std;

double coef1[1005], coef2[1005], coef_res[2005];

int main() {
    int k;
    cin >> k;
    while (k--) {
        int e;
        double c;
        cin >> e >> c;
        coef1[e] += c;
    }
    cin >> k;
    while (k--) {
        int e;
        double c;
        cin >> e >> c;
        coef2[e] += c;
    }
    for (int i = 0; i <= 1000; ++i) {
        if (coef1[i])
            for (int j = 0; j <= 1000; ++j) {
                if (coef2[j] != 0) {
                    coef_res[i + j] += coef1[i] * coef2[j];
                }
            }
    }
    int cnt = 0;
    for (int i = 0; i <= 2000; ++i) {
        if(coef_res[i])
            cnt ++;
    }
    cout << cnt;
    for (int i = 2000; i >= 0; --i) {
        if (coef_res[i]){
            printf(" %d %.1lf", i, coef_res[i]);
        }
    }
    return 0;
}