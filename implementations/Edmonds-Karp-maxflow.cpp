#include <bits/stdc++.h>
using namespace std;

#define llinf 100000000

typedef long long T;

struct Graph {
    T n;
    vector<vector<T> > capacity;
    vector<vector<int> > adj;

    Graph(int size) {
        n = size;
        capacity.assign(n, vector<T>(n,0));
        adj.resize(n);
    }

    public: void addEdge(int u, int v, T cap) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += cap;
    }

    public: T maxflow(int s, int t) {
        T flow = 0;
        vector<int> parent(n);
        T new_flow;

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
    // Useful to find edges in mincut
    public: T bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, T> > q;
        q.push(make_pair(s, INT64_MAX));

        while (!q.empty()) {
            int u = q.front().first;
            T flow = q.front().second;
            q.pop();

            for (int v : adj[u]) {
                if (parent[v] == -1 && capacity[u][v] > 0) { // Unvisited and non-zero capacity
                    parent[v] = u;
                    T new_flow = min(flow, capacity[u][v]);
                    if (v == t)
                        return new_flow;
                    q.push(make_pair(v, new_flow));
                }
            }
        }

        return 0;
    }
};

// Solves Kattis mincut
int main() {

    int n,m,s,t;

    cin >> n >> m >> s >> t;
    Graph G(n);
    int from,to,cap;
    for (int i=0; i<m; i++) {
        cin >> from >> to >> cap;
        if (from != to) {
            G.addEdge(from,to,cap);
        }
    }
    
    G.maxflow(s,t);

    vector<int> parent(n);
    G.bfs(s,t,parent);

    int count = 0; for (int i=0; i<n; i++) count += (parent[i] >= 0 ? 1 : 0);

    cout << ++count << endl; // also count the sink (parent == -2)

    for (int i=0; i<n; i++)
        if (i == s || parent[i] >= 0)
            cout << i << endl;

    return 0;
}