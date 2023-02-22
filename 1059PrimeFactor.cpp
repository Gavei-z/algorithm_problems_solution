//
// Created by UestcGavei711 on 2022/7/3.
//

#include "iostream"

using namespace std;

int n;

int main(){
    cin >> n;
    cout << n << "=";
    if (n == 1) cout << 1;
    else {
        int num = n;
        bool is_first = true;
        for (int i = 2; i <= num / i; ++i) {
            if (n % i == 0) {
                // 获得指数
                int k = 0;
                while (n % i == 0) {
                    n /= i;
                    k ++;
                }
                if (is_first)
                    printf("%d", i), is_first = false;
                else
                    printf("*%d", i);
                if (k > 1)
                    printf("^%d", k);
            }
        }
        if (n > 1) {
            if (is_first)
                cout << n ;
            else
                printf("*%d", n);
        }
    }
    return 0;
}