//
// Created by Gavei on 2022/5/4.
//

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main(){
    string A;
    vector<int> a, b;
    cin >> A;
    for (int i = A.size() - 1; i >= 0; --i) a.push_back(A[i] - '0');
    int t = 0;
    for (int i = 0; i < A.size(); ++i) {
        int sum = a[i] * 2 + t;
        b.push_back(sum % 10);
        t = sum / 10;
    }
    if (t) b.push_back(t);
    vector<int> c = b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = c.size() - 1; i >= 0; --i)
        cout << c[i];
    return 0;
}