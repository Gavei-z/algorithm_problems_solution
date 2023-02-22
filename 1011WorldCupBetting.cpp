//
// Created by Gavei on 2022/4/9.
//

#include "iostream"

using namespace std;
double res = 1;

void fun(double a, double b, double c){
    double m = max(a,max(b,c));
    if(m == a)
        cout << "W ";
    else if(m == b)
        cout << "T ";
    else
        cout << "L ";
    res *= m;
}
int main(){
    for(int i = 0; i < 3; ++i)
    {
        double w, t, l;
        cin >> w >> t >> l;
        fun(w, t, l);
    }
    printf("%.2lf", (res * 0.65 -1) * 2);
    return 0;
}