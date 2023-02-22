//
// Created by UestcGavei on 2022/9/27.
//
#include "iostream"
#include "stack"
#include "map"

using namespace std;
map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/',2}};
stack<int> num;
stack<char> op;

void eval() {
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    int x;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else
        x = a / b;
    num.push(x);
}

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        auto c =  str[i];
        if (isdigit(c)) {
            int x = 0, j = i;
            while (j < str.length() && isdigit(str[j]))
                x = x * 10 + str[j ++] - '0';
            num.push(x);
            i = j - 1;
        }
        else if (c == '(') op.push(c);
        else if (c == ')') {
            while (op.top() != '(') eval();
            op.pop();
        } else {
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
                eval();
            op.push(c);
        }
    }
    while (op.size()) eval();
    cout << num.top() << endl;
    return 0;
}
