//
// Created by 10263 on 2022/8/8.
//

#include "iostream"

using namespace std;
const int N = 110;
int v[N], n;

int judge(int a, int b, int c)
{
    int t = v[a];
    if (t > 0) {
        if (t == b || t == c)
            return 1;
        else
            return 0;
    }
    t = -t;
    if (t == b || t == c)
        return 0;
    else
        return 1;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            int t = judge(i, i, j) + judge(j, i, j);
            if (t == 1) {
                int s = 0;
                for (int k = 1; k <= n; ++k)
                    s += judge(k, i, j);
                if (s == 2) {
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    puts("No Solution");
    return 0;
}