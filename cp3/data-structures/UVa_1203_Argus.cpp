#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

unordered_map<int,int> period; 

int main() {
    string s; int k;
    priority_queue<ii, vector<ii>, greater<ii> > q;
    while (cin >> s) {
        if (s.compare("#") == 0) break;
        ii query;
        cin >> query.second >> query.first;
        period[query.second] = query.first;
        q.push(query);
    }
    cin >> k;
    for (int i=0; i<k; i++) {
        ii res = q.top(); q.pop();
        cout << res.second << endl;
        res.first += period[res.second];
        q.push(res);
    }
    return 0;
}