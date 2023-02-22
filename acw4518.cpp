//
// Created by 10263 on 2022/8/31.
//
#include "iostream"
#include "algorithm"

using namespace std;
const int N = 400;

int n, d[N], c[3];
int f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    for (int i = 0; i < 3; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + c[0];
        int j7 = i - 1;
        while (d[i] - d[j7] <= 6 && j7 >= 1)
            j7--;
        int j30 = i - 1;
        while (d[i] - d[j30] <= 29 && j30 >= 1)
            j30--;
        f[i] = min({f[i], f[j7] + c[1], f[j30] + c[2]});
    }
    cout << f[n] << endl;
    return 0;
}