//
// Created by 10263 on 2023/1/2.
//
#include "iostream"

using namespace std;

const int N = 1000010;
int n, k;
int main() {
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; ++ i) {
        int x = i;
        while (x) {
            int t = x % 10;
            if (t == k) res ++;
            x /= 10;
        }
    }
    cout << res << endl;
    return 0;
}