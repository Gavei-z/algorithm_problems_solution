//
// Created by Gavei on 2022/4/6.
//

#include "iostream"

using namespace std;

typedef long long LL;
string n1, n2;
LL tag, radix;

LL get(char c)
{
    if(c <= '9')
        return c - '0';
    else
        return c - 'a' + 10;
}
LL calc(string num, LL radix)
{
    LL res = 0;
    for(auto c : num)
    {
        if(res * radix + get(c) > 1e16) return 1e18;
        res = res * radix + get(c);
    }
    return res;
}
int main(){
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2) swap(n1,n2);
    LL target = calc(n1, radix);
    LL r = target + 1;
    LL l = 0;
    for(auto c : n2) l = max(l,get(c) + 1);
    while(l < r){
        LL mid = (l + r) >> 1;
        if((double)calc(n2, mid) >= target) r = mid;
        else l = mid + 1;
    }
    if(calc(n2, r) != target) cout <<"Impossible";
    else cout << r << endl;
    return 0;
}