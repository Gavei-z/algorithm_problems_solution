//
// Created by Gavei on 2022/3/16.
//
#include "iostream"
#include "algorithm"

using namespace std;

struct Number {
    int idx;
    string res = "";
};

int n;
string a, b;

Number fun(string num) {
    Number ans;
    int pos1 = 0, pos2 = 0;// pos1 point, pos2 number
    //得到小数点位置，计算指数为多少
    while (num[pos2] == '0' || num[pos2] == '.') pos2++;
    if (num.find('.') == string::npos) {
        pos1 = num.length();
    } else {
        pos1 = num.find('.');
    }
    if(pos2 == num.length())
        ans.idx = 0;
    else if(pos2 > pos1)
        ans.idx = pos1 - pos2 + 1;
    else
        ans.idx = pos1 - pos2;

    if (pos1 > pos2) {
        ans.res += num.substr(pos2, pos1);
        if (pos1 != num.length())
            ans.res += num.substr(pos1 + 1);
    }
    else {
        if(pos2 == num.length())
            ans.res = "0";
        else
            ans.res += num.substr(pos2);
    }
    if(ans.res.length() > n)
        ans.res = ans.res.substr(0, n);
    else
    {
        int Len = ans.res.length();
        for (int i = 0; i < (n-Len); ++i) {
            ans.res += "0"; // 位数不够，末尾补0
        }
    }

    return ans;
}

int main() {
    cin >> n >> a >> b;
    Number n1 = fun(a);
    Number n2 = fun(b);
    if (n1.res == n2.res && n1.idx == n2.idx) {
        cout << "YES 0." << n1.res << "*" << "10^" << n2.idx;
    } else {
        cout << "NO 0." << n1.res << "*" << "10^" << n1.idx <<" 0." << n2.res << "*10^" << n2.idx;
    }
    return 0;
}
