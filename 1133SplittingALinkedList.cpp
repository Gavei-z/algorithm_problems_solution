//
// Created by UestcGavei711 on 2022/7/24.
//

#include "iostream"
#include "vector"

using namespace std;

const int N = 100010;

int n, k, s, e[N], ne[N];
vector<int> v, neg, nneg;

int main() {
    cin >> s >> n >> k;
    for (int i = 0; i < n; ++i) {
        int add, num, next;
        cin >> add >> num >> next;
        e[add] = num;
        ne[add] = next;
    }
    while (s != -1) {
        if (e[s] < 0)
            neg.push_back(s);
        else
            nneg.push_back(s);
        s = ne[s];
    }
    vector<int> res, res2;
    for (int i = 0; i < nneg.size(); ++i) {
        if (e[nneg[i]] <= k)
            res.push_back(nneg[i]);
        else
            res2.push_back(nneg[i]);
    }
    for (int i = 0; i < neg.size(); ++i) {
        printf("%05d %d ", neg[i], e[neg[i]]);
        if (i == neg.size() - 1) {
            if (res.size())
                printf("%05d\n", res[0]);
            else
                cout << -1 << endl;
        } else
            printf("%05d\n", neg[i + 1]);
    }
    for (int i = 0; i < res.size(); ++i) {
        printf("%05d %d ", res[i], e[res[i]]);
        if (i == res.size() - 1) {
            if (res2.size())
                printf("%05d\n", res2[0]);
            else
                cout << -1 << endl;
        } else
            printf("%05d\n", res[i + 1]);
    }
    for (int i = 0; i < res2.size(); ++i) {
        printf("%05d %d ", res2[i], e[res2[i]]);
        if (i == res2.size() - 1)
            cout << -1 << endl;
        else
            printf("%05d\n", res2[i + 1]);
    }
    return 0;
}