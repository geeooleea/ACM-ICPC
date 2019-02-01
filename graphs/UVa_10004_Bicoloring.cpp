#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int color[201];

int main() {
    int n,m;
    while (cin >> n) {
        if (n==0) break;
        cin >> m;

        vector<vector<int> > graph(n);
        int u,v;
        for (int i=0; i<n; i++) color[i] = 0;
        for (int i=0; i<m; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;
        color[0] = 1;
        q.push(0);
        bool bicolorable = true;
        while (!q.empty() && bicolorable) {
            int u = q.front(); q.pop();
            for (int i=0; i<graph[u].size() && bicolorable; i++) {
                int v = graph[u][i];
                if (color[v] == 0) {
                    color[v] = (color[u] == 1 ? 2 : 1);
                    q.push(v);
                } else if (color[v] == color[u]) {
                    bicolorable = false;
                }
            }
        }
        if (bicolorable) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}