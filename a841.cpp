//
// Created by UestcGavei on 2022/10/19.
//

#include "iostream"

using namespace std;
typedef unsigned long long ULL;
const int N = 100010, P = 131;
ULL p[N], h[N];
int n, m;
char str[N];

ULL get_num(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m;
    scanf("%s", str + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    while (m--)
    {
       int l1, r1, l2, r2;
       cin >> l1 >> r1 >> l2 >> r2;
       if (get_num(l1, r1) == get_num(l2, r2))
           puts("Yes");
       else
           puts("No");
    }
    return 0;
}