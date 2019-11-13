#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int> V;

int main() {
    int n,m;
    cin >> n >> m;
    string s,t;

    V["English"] = 0;
    for (int i=1; i<=n; i++) {
        cin >> s;
        V[s] = i;
    }
    vector<vector<int> > graph(n+1,vector<int>(n+1,-1));
    for (int i=0; i<m; i++) {
        int w;
        cin >> s >> t >> w;
        graph[V[s]][V[t]] = w;
        graph[V[t]][V[s]] = w;
    }
    queue<int> q;
    vector<int> d(n+1,INT32_MAX);
    q.push(0); // English
    d[0] = 0;
    // BFS, non-weighted dijkstra
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i=0; i<=n; i++) {
            if (graph[u][i] > 0 && d[i] == INT32_MAX && d[i] > d[u]) {
                d[i] = d[u] + 1;
                q.push(i);
            }
        }
    }

    int cost = 0;
    bool ok = true;
    for (int i=1; i<=n && ok; i++) {
        if (d[i] == INT32_MAX) ok = false;
        int mind = INT32_MAX; // Neighbor that is closest to english 
        for (int j=0; j<=n && ok; j++) {
            if (i != j && graph[i][j] > 0 && d[j] == d[i]-1) {
                mind = min(mind,graph[i][j]);
            }
        }
        cost += mind;
    }
    if (ok) cout << cost << endl;
    else cout << "Impossible" << endl;
    return 0;
}