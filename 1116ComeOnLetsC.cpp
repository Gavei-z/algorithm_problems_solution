//
// Created by UestcGavei711 on 2022/6/1.
//

#include "iostream"

using namespace std;

const int N = 10010;
int n, k, r[N];
bool st[N];
bool judge(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        r[t] = i;
    }
    cin >> k;
    while (k--) {
        int q;
        cin >> q;
        if (r[q] == 0)
            printf("%04d: Are you kidding?\n", q);
        else if (st[q])
            printf("%04d: Checked\n", q);
        else{
            st[q] = true;
            if (r[q] == 1)
                printf("%04d: Mystery Award\n", q);
            else if (judge(r[q]))
                printf("%04d: Minion\n", q);
            else
                printf("%04d: Chocolate\n", q);
        }
    }
    return 0;
}