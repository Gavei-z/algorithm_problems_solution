//
// Created by UestcGavei711 on 2022/7/11.
//

#include "iostream"

using namespace std;

const int M = 1010;
int n, m, cnt[M];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x <= m)
            cnt[x]++;
    }
    for (int i = 1; i <= m; ++i) {
        if (cnt[i]) {
            cnt[i]--;
            if (cnt[m - i]) {
                cout << i << " " << m - i;
                return 0;
            }
        }
    }
    puts("No Solution");
    return 0;
}