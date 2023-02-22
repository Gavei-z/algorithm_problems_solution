//
// Created by Gavei on 2022/4/4.
//

#include "iostream"

using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = 0;
    int last = 0;
    while(n--)
    {
        int cur;
        cin >> cur;
        if (cur > last)
            sum += (cur - last) * 6;
        else sum += (last - cur) * 4;
        last = cur;
        sum += 5;
    }
    cout << sum;
    return 0;
}