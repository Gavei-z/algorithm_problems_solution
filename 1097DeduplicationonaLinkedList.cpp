//
// Created by Gavei on 2022/2/18.
//

#include "iostream"
#include "cmath"
#include "algorithm"

using namespace std;
const int N = 100000;
struct Node {
    int address, key, next;
    int num = 2 * N;
};
Node node[N];
bool book[N];

bool cmp(Node n1, Node n2) {
    return n1.num < n2.num;
}

int main() {
    int head, n;
    cin >> head >> n;
    for (int i = 0; i < n; ++i) {
        int add;
        cin >> add;
        cin >> node[add].key >> node[add].next;
        node[add].address = add;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = head; i != -1; i = node[i].next) {
        // 从头遍历到尾，且排序了
        // 当前节点key值没有重复，num赋值cnt1
        if (book[abs(node[i].key)] == false) {
            book[abs(node[i].key)] = true;
            node[i].num = cnt1;
            cnt1++;
        } else {
            node[i].num = N + cnt2;
            cnt2++;
        }
    }

    int cnt = cnt1 + cnt2;
    sort(node, node + N, cmp);
    for (int i = 0; i < cnt; ++i) {
        if (i != cnt1 - 1 && i != cnt - 1) {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);
        } else {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }
    return 0;
}