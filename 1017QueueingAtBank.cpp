//
// Created by Gavei on 2022/4/13.
//

#include "iostream"
#include "queue"
#include "algorithm"

using namespace std;

const int N = 10010, K = 110;

struct Person {
    int arrive_time, service_time;

    bool operator<(const Person &t) const {
        return arrive_time < t.arrive_time;
    }
} p[N];

int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int h, m, s, proc;
        scanf("%d:%d:%d %d", &h, &m, &s, &proc);
        proc = min(proc, 60);
        p[i] = {h * 3600 + m * 60 + s, proc * 60};
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; ++i) q.push(8 * 3600);
    sort(p, p + n);
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].arrive_time > 17 * 3600)
            break;

        int top = q.top();
        q.pop();

        int start = max(top, p[i].arrive_time);
        sum += start - p[i].arrive_time;
        cnt += 1;
        q.push(start + p[i].service_time);
    }
    printf("%.1lf", (double) sum * 1.0 / cnt / 60);
    return 0;
}