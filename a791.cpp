//
// Created by 10263 on 2022/9/9.
//
#include "iostream"
#include "vector"

using namespace std;

vector<int> A, B, C;
vector<int> add(vector<int> &A, vector<int> &B) {
    int t = 0;
    vector<int> res;
    for (int i = 0; i < A.size() || i < B.size(); ++i) {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        res.push_back(t % 10);
        t /= 10;
    }
    if (t)
        res.push_back(t);
    return res;
}
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - '0');
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    return 0;
}