//
// Created by Gavei on 2022/5/8.
//

#include "iostream"
#include "vector"

using namespace std;
const int N = 40;
int n, pre[N], post[N], pos[N];
bool unique = true;
vector<int> in;
void getIn(int l1, int r1, int l2, int r2)
{
    if (l1 == r1){
        in.push_back(pre[l1]);
        return ;
    }
    if (pre[l1] == post[r2]){
        int rson = post[r2 - 1];
        int rsonpos = pos[rson];
        if (rsonpos - l1 > 1) // 存在左子树
            getIn(l1 + 1, rsonpos - 1, l2, rsonpos - 1 - l1 - 1 + l2);
        else
            unique = false;
        in.push_back(pre[l1]);
        getIn(rsonpos, r1,rsonpos - r1 + r2 - 1 , r2 - 1);
    }
}
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> pre[i], pos[pre[i]] = i;
    for (int i = 0; i < n; ++i) cin >> post[i];
    getIn(0, n - 1, 0, n - 1);
    if (unique)
        puts("Yes");
    else
        puts("No");
    cout << in[0];
    for (int i = 1; i < in.size(); ++i)
        cout << " " << in[i];
    cout << endl;
    return 0;
}