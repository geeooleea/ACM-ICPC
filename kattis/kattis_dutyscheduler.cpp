#include <bits/stdc++.h>
using namespace std;

#define llinf 100000000

typedef long long T;

struct Graph {
    T n;
    vector<vector<T> > original;
    vector<vector<T> > capacity;
    vector<vector<int> > adj;

    Graph(int size) {
        n = size;
        capacity.assign(n, vector<T>(n,0));
        original.assign(n, vector<T>(n,0));
        adj.resize(n);
    }

    public: void addEdge(int u, int v, T cap) {
        if (capacity[u][v] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        capacity[u][v] += cap;
        original[u][v] = capacity[u][v];
    }

    public: void restoreCapacity() {
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) capacity[i][j] = original[i][j];
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

    int n,m;
    cin >> m >> n;
    const int source = n+m, sink = n+m+1;
    string s;
    vector<string> name(m);

    Graph G(n+m+2);

    for (int i=0; i<n; i++) G.addEdge(source,i,2);

    vector<vector<bool> > available(m,vector<bool>(n,false));

    for (int i=0; i<m; i++) {
        // cout << i << endl;
        int d;
        cin >> s >> d;
        name[i] = s;
        for (int j=0; j<d; j++) {
            int k;
            cin >> k;
            k--;
            available[i][k] = true;
            G.addEdge(k,n+i,1);
        }
        G.addEdge(n+i,sink,1);
    }

    for (int k=0; k<n; k++) {
        int maxflow = G.maxflow(source,sink);
        if (maxflow == 2*n) {
            cout << k+1 << endl;
            for (int i=0; i<n; i++) { // Check all days
                cout << "Day " << i+1 << ": ";
                for (int j=0; j<m; j++) {
                    if (available[j][i] && G.capacity[i][n+j] == 0) {
                        cout << name[j] << " ";
                    }
                }
                cout << endl;
            }
            break;
        }
        G.restoreCapacity();
        for (int i=0; i<m; i++) G.addEdge(n+i,sink,1);
    }

    return 0;
}