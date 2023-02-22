#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 100003;

int h[N], e[N], ne[N], idx;
void insert(int x) {
    int t = (x % M + M) % M;
    e[idx] = x;
    ne[idx] = h[t];
    h[t] = idx ++;
}

bool find(int x) {
    int t = (x % M + M) % M;
    for (int i = h[t]; i != -1; i = ne[i]) 
        if (e[i] == x) return true;
    return false;
}
int main (){
    memset(h, -1, sizeof h);
    char op[2];
    int x, n;
    cin >> n;
    while (n--) {
        scanf("%s %d", op, &x);
        if (*op == 'I') insert(x);
        else if (*op == 'Q') {
            if (find(x))
                puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
