//
// Created by UestcGavei on 2022/10/6.
//
#include "iostream"

using namespace std;

const int N = 100010;
int n, son[N][26], idx, cnt[N];
char str[N];
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main() {
    cin >> n;
    char op[2];
    while (n--) {
        scanf("%s %s", op, str);
        if (*op == 'I')
            insert(str);
        else
            printf("%d\n", query(str));
    }
    return 0;
}