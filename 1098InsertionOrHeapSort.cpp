//
// Created by Gavei on 2022/2/21.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
int n;

void DownAjust(vector<int> &b, int low, int high) {
    int i = 1, j = 2 * i; // 父节点, 左儿子
    while (j <= high) {
        // 找到堆下最小键值的节点, 和堆顶交换
        if (j + 1 <= high && b[j + 1] > b[j]) j++; // 是否右儿子更大
        if (b[i] >= b[j]) break;
        swap(b[i], b[j]);
        i = j;
        j = i * 2;
    }
}

int main() {
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    // 先判断是否是插入排序
    int p = 2;
    while (p <= n && b[p - 1] <= b[p]) p++;
    int index = p;
    while (p <= n && a[p] == b[p]) p++;
    if (p == n + 1) {
        cout << "Insertion Sort" << endl;
        sort(b.begin() + 1, b.begin() + index + 1);
    } else {
        cout << "Heap Sort" << endl;
        // 堆排序，堆顶肯定是最大的
        p = n;
        while (p > 2 && b[p] >= b[1]) p--;
        swap(b[1], b[p]);
        DownAjust(b, 1, p - 1);
    }
    cout << b[1];
    for (int i = 2; i <= n; ++i) {
        cout << " " << b[i];
    }
    return 0;
}