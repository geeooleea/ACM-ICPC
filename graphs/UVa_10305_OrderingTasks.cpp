#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topSort(int node, vector<vector<int> > &graph, bool visited[], stack<int> &s) {
    visited[node] = true;
    for (int i=0; i<graph[node].size(); i++) {
        if (!visited[graph[node][i]]) topSort(graph[node][i], graph, visited, s);
    }
    s.push(node);
}

int main() {
    int n,m;

    while (cin >> n >> m) {
        if (!n && !m) break;
        vector<vector<int> > graph(n+1);
        stack<int> s;
        int from, to;
        bool visited[100];
        for (int i=1; i<=n; i++) visited[i] = false;
        for (int i=0; i<m; i++) {
            cin >> from >> to;
            graph[from].push_back(to);
        }

        /*
        for (int i=1; i<=n; i++) {
            cout << i << ": ";
            for (int j=0; j<graph[i].size(); j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        */

        for (int i=1; i<=n; i++) {
            if (!visited[i]) topSort(i, graph, visited, s);
        }
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    return 0;
}   