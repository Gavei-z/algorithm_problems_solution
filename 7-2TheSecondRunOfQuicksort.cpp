//
// Created by 10263 on 2022/9/4.
//
#include "iostream"
#include "algorithm"

using namespace std;

const int N = 100010;
int k, n, arr[N], b[N];

/*
1
8
5 2 16 12 28 60 32 72
 */

bool judge(int x, int p1, int p2)
{
    for (int i = p1; i <= x - 1; ++i)
        if (arr[i] > arr[x])
            return false;
    for (int i = x + 1; i <= p2; ++i)
        if (arr[i] < arr[x])
            return false;
    return true;
}
bool fun(int p) {
    bool t1 = false, t2 = false;
    //  看左边
    if (p == 0)
        t1 = true;
    else {
        for (int i = 0; i < p; ++i)
            if (judge(i, 0, p - 1)) {
                t1 = true;
                break;
            }
    }

    // 看右边
    if (p == n - 1)
        t2 = true;
    else {
        for (int i = p + 1; i < n; ++i)
            if (judge(i, p + 1, n - 1)) {
                t2 = true;
                break;
            }
    }
    return (t1 && t2);
}

void solution1() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    bool res = false;

    for (int i = 0; i < n; ++i) {
        if (judge(i, 0, n - 1)) // 第一个找到了
        {
            if (fun(i)) {
                res = true;
                break;
            }
        }
    }

    if (res)
        puts("Yes");
    else
        puts("No");
}
void solution2() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]), b[i] = arr[i];

    bool res = false;
    int cnt = 0;
    int l = 0, r = n - 1, k = 3;
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i) {
        if (arr[i] == b[i]) {
            cnt ++;
            if (i == l) {
                k--;
                l ++;
            }
            if (i == r) {
                k--;
                r--;
            }
        }
    }
    if (cnt >= k)
        res = true;
    if (res)
        puts("Yes");
    else
        puts("No");
}
int main() {
    cin >> k;
    while (k--)
    {
        solution1();
//            solution2();
    }

    return 0;
}