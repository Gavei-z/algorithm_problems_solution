//
// Created by Gavei on 2022/3/22.
//
#include "iostream"
#include "cstdio"

using namespace std;

int main(){
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int i = 0;
    while(1){
        if(a[i] == b[i] && (a[i]) >= 'A' && a[i] <= 'G')
            break;
        i ++;
    }
    char weekday[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    printf("%s ", weekday[a[i]-'A']);
    i++;
    while(1){
        if(a[i] == b[i] && (a[i] >= '0' && a[i] <= '9' || a[i] >= 'A' && a[i] <= 'N'))
            break;
        i++;
    }
    printf("%02d:", a[i] <= '9' ? a[i] - '0' : a[i] - 'A' + 10);
    int j = 0;
    for (;; ++j) {
        if(c[j] == d[j] && (c[j] >= 'a' && c[j] <= 'z' || c[j] >= 'A' && c[j] <= 'Z')) break;
    }
    printf("%02d", j);
    return 0;
}
