#include <bits/stdc++.h>
#define UNIVISITED -1

using namespace std;

int n,m;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

vvi graph;
vector<bool> visited;
vi dfsNum, dfsLow;

vi S; // Holds currently visiting nodes

// list that holds nodes in each scc
vector<vector<int> > scc;

int sccCount = 0;

void TarjanSCC(int u) {
    dfsLow[u] = dfsNum[u] = sccCount++;
    S.push_back(u);
    visited[u] = true;
    for (int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        if (dfsNum[v] == UNIVISITED) TarjanSCC(v);
        if (visited[v]) dfsLow[u] = min(dfsLow[u], dfsLow[v]);
    }
    if (dfsLow[u] == dfsNum[u]) {
        int v;
        while (v = S.back() != u) {
            S.pop_back(); visited[v] = false;
            scc[sccCount-1].push_back(v);
        }
        scc[sccCount-1].push_back(u); visited[u] = false;
    }
}