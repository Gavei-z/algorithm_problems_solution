#include "iostream"
#include "stack"

using namespace std;

const int N = 1010;
int m, n, k;
int arr[N];
int main() {
    cin >> m >> n >> k;
    while(k--)
    {
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        stack<int> stk;
        bool f = true;
        for (int i = 1, j = 0; i <= n; ++i) {
            stk.push(i);
            if (stk.size() > m) {
                f = false;
                break;
            }
            while(stk.size() && stk.top() == arr[j]) {
                stk.pop();
                j++;
            }
        }
        if (stk.size())
            f = false;
        if (f)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}