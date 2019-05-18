#include <bits/stdc++.h>

using namespace std;

long long n;
vector<vector<long long> > capacity;
vector<vector<int> > adj;

long long bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, long long> > q;
    q.push(make_pair(s, INT64_MAX));

    while (!q.empty()) {
        int u = q.front().first;
        long long flow = q.front().second;
        q.pop();

        for (int v : adj[u]) {
            if (parent[v] == -1 && capacity[u][v] > 0) { // Unvisited and non-zero capacity
                parent[v] = u;
                long long new_flow = min(flow, capacity[u][v]);
                if (v == t)
                    return new_flow;
                q.push(make_pair(v, new_flow));
            }
        }
    }

    return 0;
}

long long maxflow(int s, int t) {
    long long flow = 0;
    vector<int> parent(n);
    long long new_flow;

    while ((new_flow = bfs(s,t,parent)) > 0) { // While there is any positive flow
        flow += new_flow;
        int cur = t;
        while (cur != s) { // Reduce capacities of all edges in the shortest path
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    int m,s,t;

    cin >> n >> m >> s >> t;
    vector<vector<long long> > original(n,vector<long long>(n,0));
    capacity.assign(n,vector<long long>(n,0));
    adj.resize(n);
    int from,to,cap;
    for (int i=0; i<m; i++) {
        cin >> from >> to >> cap;
        if (from != to) {
            capacity[from][to] += cap;
            original[from][to] += cap;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
    }
    
    maxflow(s,t);

    vector<int> parent(n);
    bfs(s,t,parent);

    int count = 0; for (int i=0; i<n; i++) count += (parent[i] >= 0 ? 1 : 0);

    cout << ++count << endl; // also count the sink (parent == -2)

    for (int i=0; i<n; i++)
        if (i == s || parent[i] >= 0)
            cout << i << endl;

    return 0;
}