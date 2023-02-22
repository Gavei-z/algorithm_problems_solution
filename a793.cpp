//
// Created by 10263 on 2022/9/13.
//
#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

vector<int> A;

vector<int> mul(vector<int>& A, int b)
{
    vector<int> res;
    int t = 0;
    for (int i = 0; i < A.size(); ++i) {
        t += A[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }
    while (t)
        res.push_back(t % 10), t /= 10;
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
    return res;
}
int main() {
    string a;
    int b;
    cin >> a >> b;
    for (int i = a.size() -1 ; i >= 0; --i)
        A.push_back(a[i] - '0');
    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; --i)
        cout << C[i];
    return 0;
}