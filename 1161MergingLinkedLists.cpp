//
// Created by 10263 on 2022/8/16.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
const int N = 100010;
int s1, s2, n;
int v[N], ne[N];
vector<int> l1, l2;

int main() {
    cin >> s1 >> s2 >> n;
    while (n--) {
        int add, num, next;
        scanf("%d %d %d", &add, &num, &next);
        v[add] = num;
        ne[add] = next;
    }
    for (int i = s1; i != -1; i = ne[i])
        l1.push_back(i);
    for (int i = s2; i != -1; i = ne[i])
        l2.push_back(i);
    if (l1.size() < l2.size())
        swap(l1, l2);
    if (l1.size() >= 2 * l2.size()) {
        vector<int> res;
        reverse(l2.begin(), l2.end());
        for (int i = 0, j = 0; i < l1.size(); ++i) {
            res.push_back(l1[i]);
            if ((i + 1) % 2 == 0 && j < l2.size())
                res.push_back(l2[j]), j ++;
        }

        for (int i = 0; i < res.size(); ++i) {
            printf("%05d %d ", res[i], v[res[i]]);
            if (i == res.size() - 1)
                cout << -1 << endl;
            else
                printf("%05d\n",res[i + 1]);
        }
    }
    return 0;
}