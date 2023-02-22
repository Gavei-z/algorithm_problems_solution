//
// Created by Gavei on 2022/4/13.
//

// 23  10111 reverse: 11101
// 23 11101 16+8+4+1
#include "iostream"
#include "cstring"
#include "cmath"
using namespace std;

int n, d;

bool judge(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0){
//            cout << i <<endl;
            return false;
        }
    }
    return true;
}
bool change(int n, int d)
{
    //将n转换为d进制下的数
    int num = n;
    string res;
    while(num)
    {
        res += to_string(num % d);
        num /= d;
    }
    int t = stoi(res,0,d);
    bool f1 = judge(t);
    return f1;
}
int main() {
    while(cin >> n){
        if (n < 0)
            break;
        cin >> d;
        if (!judge(n)){
            cout << "No"<<endl;
        }
        else{
            bool res = change(n, d);
            if (res)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}