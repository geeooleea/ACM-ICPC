#include <bits/stdc++.h>

using namespace std;

int n,m;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

vvi graph;
vvi graphT;

vector<bool> visited;

// Holds top-sort for the second visit
stack<int> S;
// Holds scc-ID for every node
vector<int> scc;

int sccCount = 0;

/**
 * First calls to Kosaraju (pass = 1) builds stack.
 * Second calls (pass = 2) set connected component IDs.
 * 
 * REMEMBER TO CLEAR visited FOR SUBSEQUENT CALLS
 */
void Kosaraju(int u, int pass) {
    visited[u] = true;
    vi neighbor;
    if (pass == 1) neighbor = graph[u]; else neighbor = graphT[u];
    for (int j = 0; j < neighbor.size(); j++) {
        int v = neighbor[j];
        if (!visited[v])
            Kosaraju(v, pass);
    }
    if (pass == 1) S.push(u); 
    else scc[u] = sccCount; // Set connected component to current
}