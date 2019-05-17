#include <bits/stdc++.h>
#define INF 100000

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
    int s,r,f,t;
    string state;
    int id = 2; // source id = 0; sink id = 1 
    cin >> s >> r >> f >> t;
    unordered_map<string,int> ids;
    n = s+2*t+2;
    capacity.assign(n, vector<long long>(n,0));
    adj.resize(n);

    for (int i=0; i<r; i++) {
        cin >> state;
        if (ids.count(state) == 0) {
            ids[state] = id++;
        }
        adj[0].push_back(ids[state]);
        capacity[0][ids[state]] = 1;
    }
    
    for (int i=0; i<f; i++) {
        cin >> state;
        if (ids.count(state) == 0) {
            ids[state] = id++;
        }
        adj[ids[state]].push_back(1);
        capacity[ids[state]][1] = 1;
    }
    
    int m;
    for (int i=0; i<t; i++) {
        cin >> m;
        int vin = i+s+2, vout = i+s+t+2;
        adj[vin].push_back(vout);
        capacity[vin][vout] = 1;
        for (int j=0; j<m; j++) {
            cin >> state;
            if (ids.count(state) == 0) {
                ids[state] = id++;
            }
            //if (ids[state] < r+2 || ids[state] >= r+f+2) {
                adj[ids[state]].push_back(vin);
                capacity[ids[state]][vin] = 1;
            //}
            
            //if (ids[state] >= r+2) {
                adj[vout].push_back(ids[state]);
                capacity[vout][ids[state]] = 1;
            // }
        }
    }

    cout << maxflow(0,1) << endl;

    return 0;
}