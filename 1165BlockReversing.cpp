//
// Created by 10263 on 2022/8/17.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int N = 100010;
int n, k, s;
int v[N], ne[N];
int main() {
    cin >> s >> n >> k;
    while (n--)
    {
        int add, num, next;
        cin >> add >> num >> next;
        v[add] = num, ne[add] = next;
    }
    vector<int> lst;
    for (int i = s; i != -1; i = ne[i])
        lst.push_back(i);
    for (int i = 0; i < lst.size(); i += k) {
        int r = min(i + k, (int)lst.size());
        reverse(lst.begin() + i, lst.begin() + r);
    }
    reverse(lst.begin(), lst.end());
    for (int i = 0; i < lst.size(); ++i) {
        printf("%05d %d ", lst[i], v[lst[i]]);
        if (i == lst.size() - 1)
            cout << -1 << endl;
        else
            printf("%05d\n", lst[i + 1]);
    }
    return 0;
}