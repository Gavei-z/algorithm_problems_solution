//
// Created by 10263 on 2022/9/19.
//
#include "iostream"

using namespace std;
const int N = 100010;
int n, m, x;
int A[N], B[N];

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < m; ++i)
        cin >> B[i];

    for (int i = n - 1, j = 0; i >= 0; --i) {
        while (j < m && A[i] + B[j] < x)
            j++;
        if (A[i] + B[j] == x) {
            cout << i << ' ' << j << endl;
            break;
        }
    }
    return 0;
}