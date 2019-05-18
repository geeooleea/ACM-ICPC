#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n==0) break;
        priority_queue<long long, vector<long long>, greater<long long> > q;
        int k;
        for (int i=0; i<n; i++) {
            cin >> k; q.push(k);
        }
        long long x,y;
        long long cost = 0;
        while (q.size() > 1) {
            x = q.top(); q.pop();
            y = q.top(); q.pop();
            cost += x+y;
            q.push(x+y);
        }
        cout << cost << endl;
    }
    return 0;
}