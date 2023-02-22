//
// Created by 10263 on 2022/10/14.
//
#include "iostream"
#include "string.h"
#include "algorithm"

using namespace std;
const int N = 100010;
int n;
int hp[N], ph[N], h[N], sz = 0, m = 0;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int x) {
    int u = x;
    if (h[2*x] < h[x] && 2 * x <= sz)
        u = 2 * x;
    if (h[2 * x + 1] < h[u] && 2 * x + 1 <= sz)
        u = 2 * x + 1;
    if (u != x)
    {
        heap_swap(u, x);
        down(u);
    }
}

void up(int x)
{
    while (x / 2 && h[x / 2] > h[x])
    {

        heap_swap(x, x / 2);
        x /= 2;
    }
}
int main() {
    cin >> n;
    while (n--) {
        char op[10];
        int x, k;
        scanf("%s", op);
        if (!strcmp(op, "I")) {
            cin >> x;
            sz++;
            m++;
            h[sz] = x;
            hp[sz] = m;
            ph[m] = sz;
            up(sz);
        } else if (!strcmp(op, "DM")) {
            heap_swap(1, sz);
            sz --;
            down(1);
        } else if (!strcmp(op, "D")) {
            cin >> k;
            k = ph[k];
            heap_swap(k, sz);
            sz --;
            down(k), up(k);
        } else if (!strcmp(op, "C")) {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        } else cout << h[1] << endl;
    }
    return 0;
}