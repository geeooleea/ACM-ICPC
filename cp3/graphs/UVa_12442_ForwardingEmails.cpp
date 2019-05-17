#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;

vector<int> reach;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int count = 0;
    if (graph[node] != 0 && !visited[graph[node]]) {
        count += 1 + dfs(graph[node]);
    }
    visited[node] = false;
    reach[node] = count;
    return reach[node];
}

int main() {
    int n,test;
    cin >> test;
    for (int t=0; t<test; t++) {
        cin >> n;
        graph.clear();
        graph.resize(n+1);
        reach.clear();
        reach.resize(n+1,0);
        visited.clear();
        visited.resize(n+1,false);
        int u,v;
        for (int i=0; i<n; i++) {
            cin >> u >> v;
            graph[u] = v;
        }

        int maxi = 1, maxl = 0;
        for (int i=1; i<=n; i++) {
            int d = 0;
            if (reach[i] == 0) d = dfs(i);
            if (d > maxl) {
                maxi = i;
                maxl = d;
            }
        }
        cout << "Case " << t+1 << ": " << maxi << endl;
    }
    return 0;
}