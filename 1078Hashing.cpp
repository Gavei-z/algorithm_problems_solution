//
// Created by Gavei on 2022/2/26.
//

#include "iostream"

using namespace std;

int Size, N, num[10010];
bool hashtable[10010] = {false};

bool isprime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void insert(int n) {
    for (int step = 0; step < Size; ++step) {
        int index = (n + step * step) % Size;
        if (!hashtable[index]) {
            cout << index;
            hashtable[index] = true;
            return;
        }
    }
    cout << "-";
}

int main() {
    cin >> Size >> N;
    while (!isprime(Size)) Size++;
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }
    insert(num[0]);
    for (int i = 1; i < N; ++i) {
        cout << " ";
        insert(num[i]);
    }
    return 0;
}