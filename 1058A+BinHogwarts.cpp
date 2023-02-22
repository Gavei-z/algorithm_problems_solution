//
// Created by Gavei on 2022/3/11.
//
#include "iostream"
#include "algorithm"

using namespace std;
int a1, a2, a3, b1, b2, b3;

int main() {
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    int res3 = a3 + b3 ;
    int res2 = a2 + b2 + res3 / 29;
    res3 = res3 % 29;
    int res1 = a1 + b1 + res2 / 17;
    res2 = res2 % 17;
    cout << res1 << "." << res2 << "." << res3;
}
