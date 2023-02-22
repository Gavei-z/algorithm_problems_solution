#include <iostream>

using namespace std;

const int N = 40;

int n;
int pre[N], post[N];

int dfs(int l1, int r1, int l2, int r2, string& in)
{
    if (l1 > r1) return 1;
    if (pre[l1] != post[r2]) return 0;

    int cnt = 0;
    for (int i = l1; i <= r1; i ++ )  // 枚举左子树包含的节点数量
    {
        string lin, rin;
        int lcnt = dfs(l1 + 1, i, l2, l2 + i - l1 - 1, lin);
        int rcnt = dfs(i + 1, r1, l2 + i - l1 - 1 + 1, r2 - 1, rin);

        if (lcnt && rcnt)
        {
            in = lin + to_string(pre[l1]) + ' ' + rin;
            cnt += lcnt * rcnt;
            if (cnt > 1) break;
        }
    }

    return cnt;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> pre[i];
    for (int i = 0; i < n; i ++ ) cin >> post[i];

    string in;
    int cnt = dfs(0, n - 1, 0, n - 1, in);

    if (cnt > 1) puts("No");
    else puts("Yes");

    in.pop_back();
    cout << in << endl;

    return 0;
}
