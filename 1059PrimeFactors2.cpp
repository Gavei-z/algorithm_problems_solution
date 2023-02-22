//
// Created by Gavei on 2022/3/23.
//

#include "iostream"

using namespace std;

int main(){
    int n;
    cin >> n;
    printf("%d=", n);
    if(n == 1) cout << "1";
    else{
        bool IsFirst = true;
        for (int i = 2; i <= n / i; ++i) {
            if(n % i == 0){
                // 获得指数
                int exp = 0;
                while(n % i == 0) {
                    exp ++;
                    n /= i;
                }
                if(!IsFirst) cout << "*";
                else IsFirst = false;
                printf("%d", i);
                if(exp > 1)
                    printf("^%d", exp);
            }
        }
        if(n > 1) {
            if(!IsFirst) cout << "*";
            cout << n;
        }
    }
    return 0;
}