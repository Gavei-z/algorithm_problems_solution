//
// Created by 10263 on 2023/1/3.
//
#include "iostream"
#include "algorithm"
#include "numeric"

using namespace std;

const int N = 500010;
int arr[N], n;
bool check(int g, int num) {
    int cnt = 0;
    for (int i = 0, s = 0; i < n; ++i) {
        s += arr[i];
        if (s > num) return false;
        else if (s == num) {
            cnt ++;
            s = 0;
        }
    }
    if (cnt == g) return true;
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int sum = 0;
        cin >> n;
        for (int i = 0; i < n; ++ i) scanf("%d", &arr[i]);
        sum = accumulate(arr, arr + n, 0);
//        cout << sum << '\n';
        for (int i = n; i >= 1; -- i)
            if (sum % i == 0 && check(i, sum / i)) {
                printf("%d\n", n - i);
                break;
            }
    }
    return 0;
}