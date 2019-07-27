#include <bits/stdc++.h>

using namespace std;

typedef pair<long long,long long> ii;

int main() {
    int n,m;
    cin >> n >> m;
    priority_queue<long long,vector<long long>, greater<long long> > stations;
    priority_queue<ii, vector<ii>, greater<ii> > tasks;

    long long a,s;
    for (int i=0; i<n; i++) {
        cin >> a >> s;
        tasks.push(ii(a,s));
    }

    int count = 0;
    while (!tasks.empty()) {
        a = tasks.top().first;
        s = tasks.top().second;
        if (!stations.empty()) {
            while (!stations.empty() && a > stations.top()+m) {
                stations.pop();
            }
            if (a >= stations.top() && a <= stations.top()+m) {
                count++; 
                stations.pop();
            }
        }
        stations.push(a + s);
        tasks.pop();
    }

    cout << count << endl;
    return 0;
}