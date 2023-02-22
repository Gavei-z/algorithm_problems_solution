//
// Created by 10263 on 2022/8/12.
//

#include "iostream"
#include "algorithm"

using namespace std;

const int N = 100010;
int n, a[N];

void solution1() {
    for (int i = n; i >= 1; --i) {
        if (n - i + 1 >= a[i] - 1) {
            cout << a[i] - 1 << endl;
            return;
        }
    }
}

void solution2() {
    for (int i = n; i >= 0; --i) {
        if (a[n - i + 1] > i) {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n + 1);
    solution1();
    return 0;
}