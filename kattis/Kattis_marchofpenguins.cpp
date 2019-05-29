#include <bits/stdc++.h>
#define llinf 100000000
using namespace std;

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

int n;

int x[101], y[101], num[101], m[101];

double dist(int i, int j) { return pow(x[i]-x[j],2)+pow(y[i]-y[j],2); }

int out(int node) { return n+node; }

int main() {
    double d;
    cin >> n >> d;
    int s = 2*n+1, t = 2*n+2; 
    int tot = 0, count = 0;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i] >> num[i] >> m[i];
        tot += num[i];
    }

    for (int node = 0; node < n; node++) {
        Graph G(2*n+2);
        
        for (int i=0; i<n; i++) {
            G.addEdge(s,i,num[i]);
            G.addEdge(i,out(i),m[i]);
            for (int j=i+1; j<n; j++) {
                if (dist(i,j) <= d*d) {
                    G.addEdge(out(i),j,llinf);
                    G.addEdge(out(j),i,llinf);
                }
            }
        }
        if (G.maxflow(s,node) == tot) {
            cout << node << " ";
            count++;
        }
    }

    if (count == 0) {
        cout << -1;
    }
    cout << endl;

    return 0;
}