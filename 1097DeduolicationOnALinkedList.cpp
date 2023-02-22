#include "iostream"
#include "vector"

using namespace std;

const int N = 100010;
int head, n, k[N], ne[N];
bool st[N];
vector<int> a, b;
int main(){
    cin >> head >> n;
    for (int i = 0; i < n; ++i) {
        int add, key, next;
        cin >> add >> key >> next;
        k[add] = key, ne[add] = next;

    }

    for (int i = head; i != -1 ; i = ne[i]) {
         if (!st[abs(k[i])])
             a.push_back(i), st[abs(k[i])] = true;
         else
             b.push_back(i);
    }

    for (int i = 0; i < a.size(); ++i) {
        printf("%05d %d ", a[i], k[a[i]]);
        if (i == a.size() - 1) cout << -1 << endl;
        else printf("%05d\n", ne[a[i]]);
    }

    for (int i = 0; i < b.size(); ++i) {
        printf("%05d %d ", b[i], k[b[i]]);
        if (i == b.size() - 1) cout << -1 << endl;
        else printf("%05d\n", ne[b[i]]);
    }
    return 0;
}