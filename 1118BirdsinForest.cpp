#include "iostream"
#include "unordered_set"
#include "vector"
using namespace std;

const int N = 10010;

int n, k, p[N], cnt;
unordered_set<int> s;

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    for (int i = 0; i < N; ++i) p[i] = i;
    cin >> n;
    while (n--) {
        cin >> k;
        vector<int> v;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            v.push_back(x);
            s.insert(x);
        }
        int head = find(v[0]);
        for (int i = 1; i < v.size(); ++i) {
            int pa = find(v[i]);
            if (pa != head) {
                cnt++;
                p[pa] = head;
            }
        }
    }
    cout << s.size() - cnt << " " << s.size() << endl;
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (pa != pb)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}