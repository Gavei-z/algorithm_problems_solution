//
// Created by Gavei on 2022/4/13.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void down(int low, int high, vector<int> &b) {
    int i = low, j = 2 * i;
    while (j <= high) {
        if (j + 1 <= high && b[j + 1] > b[j]) j += 1;
        if (b[i] > b[j]) break;
        swap(b[i], b[j]);
        i = j, j = 2 * i;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    int p = 1, index = 0;
    while (p + 1 <= n && b[p] <= b[p + 1]) p++;
    index = p + 1;
    while (b[index] == a[index] && index <= n) ++index;
    if (index == n + 1) {
        cout << "Insertion Sort" << endl;
        sort(b.begin() + 1, b.begin() + 2 + p);
    } else {
        cout << "Heap Sort" << endl;
        int tp = -1;
        for (int i = n; i >= 2; --i) {
            if (b[i] < b[1]) {
                tp = i;
                break;
            }
        }
        swap(b[1], b[tp]);
        down(1, tp - 1, b);
    }
    for (int i = 1; i <= n; ++i) {
        if (i != 1)
            cout << " ";
        cout << b[i];
    }
    return 0;
}