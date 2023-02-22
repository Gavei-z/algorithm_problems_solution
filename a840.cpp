//
// Created by UestcGavei on 2022/10/17.
//
#include "iostream"
#include "cstring"

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int n, h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k ++;
        if (k == N)
            k = 0;
    }
    return k;
}
int main() {
    memset(h, 0x3f, sizeof h);
    cin >> n;
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int p = find(x);
        if (*op == 'I')
           h[p] = x;
        else {
            if (h[p] != null)
                puts("Yes");
            else puts("No");
        }
    }
    return 0;
}