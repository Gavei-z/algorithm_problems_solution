#include "iostream"
#include "stack"

using namespace std;

const int N = 100010;
stack<int> stk;
int n, cnt[N], c[N];

int lowbit(int x) {
    return (x & -x);
}

void add(int x, int y) {
    for (; x <= N; x += lowbit(x))
        c[x] += y;
}

int ask(int x) {
    int s = 0;
    for (; x; x -= lowbit(x))
        s += c[x];
    return s;
}

void peek() {
    if (stk.empty()) {
        printf("Invalid\n");
        return;
    }
    int k = stk.size() % 2 == 0 ? stk.size() / 2 : (stk.size() + 1) / 2;
    int l = 1, r = N;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int num = ask(mid);
        if (num >= k) r = mid; else l = mid + 1;
    }
    printf("%d\n", l);
}

int main() {
    cin >> n;
    while (n--) {
        char op[20];
        scanf("%s", op);
        if (op[1] == 'o') {
            if (stk.empty())
                printf("Invalid\n");
            else {
                printf("%d\n", stk.top());
                add(stk.top(), -1);
                stk.pop();
            }
        } else if (op[1] == 'u') {
            int x;
            scanf("%d", &x);
            stk.push(x);
            add(x, 1);
        } else {
            peek();
        }
    }
    return 0;
}