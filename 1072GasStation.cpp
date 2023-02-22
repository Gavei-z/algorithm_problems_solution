//
// Created by Gavei on 2022/5/22.
//

#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "string.h"
using namespace std;

const int N = 1020;
int n, m, k, D, edge[N][N], dist[N], res, mmdis;
double S;
// 服务的最大距离D
// 要求最小距离最大
// 要求平均距离最小
int fun(string s){
    return n + stoi(s.substr(1));
}
void dijsktra(int start)
{
    bool st[N] = {false};
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    for (int i = 0; i < n + m; ++i) {
        int t = -1;
        for (int j = 1; j <= n + m; ++j) {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        st[t] = true;
        for (int j = 1; j <= n + m; ++j) {
            dist[j] = min(dist[j], dist[t] + edge[t][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > D)
            return ;
    }
    int mindis = 1 << 20, sum = 0;
    for (int i = 1; i <= n; ++i) {
        mindis = min(mindis, dist[i]);
        sum += dist[i];
    }
    if (mindis > mmdis)
    {
        mmdis = mindis;
        S = (double)sum;
        res = start;
    }
    else if (mindis == mmdis && sum < S)
    {
        S = (double)sum;
        mmdis = mindis;
        res = start;
    }
}
int main(){
    cin >> n >> m >> k >> D;
    memset(edge, 0x3f, sizeof edge);
    for (int i = 0; i < k; ++i) {
        string a, b;
        int e1, e2, d;
        cin >> a >> b >> d;
        if (a[0] == 'G')
            e1 = fun(a);
        else
            e1 = stoi(a);
        if (b[0] == 'G')
            e2 = fun(b);
        else
            e2 = stoi(b);
        edge[e1][e2] = edge[e2][e1] = d;
    }
    for (int i = n + 1; i <= n + m; ++i) {
        dijsktra(i);
    }
    if (res == 0)
    {
        cout << "No Solution" << endl;
    }
    else{
        char t = '0' + res - n;
        cout << "G" << t << endl;
        printf("%.1lf %.1lf",(double)mmdis, S / n);
    }

    return 0;
}