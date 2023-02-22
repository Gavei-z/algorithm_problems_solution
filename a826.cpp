//
// Created by 10263 on 2022/9/24.
//
#include "iostream"
#include "cstring"

using namespace std;

const int N = 100010;
int e[N], ne[N], idx, head;
int n;

void H(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void del(int k) {
    ne[k] = ne[ne[k]];
}

void ins(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

int main() {
    head = -1;
    cin >> n;
    while (n--) {
        char op;
        int k, x;
        cin >> op;
        if (op == 'H') {
            cin >> x;
            H(x);
        } else if (op == 'D') {
            cin >> k;
            if (k == 0)
                head = ne[head];
            else
                del(k - 1);
        } else {
            cin >> k >> x;
            ins(k - 1, x);
        }
    }

    for (int i = head; i != -1 ; i = ne[i])
        cout << e[i] << ' ';
    return 0;
}