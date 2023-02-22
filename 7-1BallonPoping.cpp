//
// Created by 10263 on 2022/9/4.
//
#include "iostream"
#include "algorithm"

using namespace std;

const int N = 100010;
int n, h, arr[N];
int maxn = -1, res;

int main() {
    cin >> n >> h;
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
        cnt++;
        // 保持[i, j]区间的arr长度永远小于等于h
        while (arr[i] - arr[j] > h) {
            j++;
            cnt--;
        }
        if (cnt > maxn) {
            maxn = cnt;
            res = arr[i] - h;
        }
    }
    cout << res << ' ' << maxn;
    return 0;
}