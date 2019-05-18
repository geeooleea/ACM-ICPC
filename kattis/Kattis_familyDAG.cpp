#include <bits/stdc++.h>
#define HILLIBILLY -1
#define NORMAL 0
#define PARADOX 1
using namespace std;

int n,m;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

vvi graph(100);
vvi graphT(100);
vector<bool> visited;
unordered_map<string,int> id;
vector<string> names;

// Modified DFS on transposed graph to find cycles
int anomaly(int u,int source) {
    visited[u] = true;
    bool par = false;
    for (int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            int an = anomaly(v,source);
            if (an != NORMAL) return an;
        } else if (v == source) {
            return PARADOX;
        }
    }
    return NORMAL;
}

int hillibilly(int u) {
    visited[u] = true;
    for (int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            int an = anomaly(v);
            if (an != NORMAL) return an;
        } else {
            return v;
        }
    }
    return NORMAL;
}

int main() {
    string p1, p2, begat;
    bool first = true;
    while (cin >> p1) {
        graph.clear(); graph.resize(100);
        graphT.clear(); graphT.resize(100);
        names.clear(); id.clear();
        int n=0; 
        while (p1.compare("done") != 0) {
            cin >> begat >> p2;
            if (id.count(p1) == 0) { names.push_back(p1); id[p1] = n++; }
            if (id.count(p2) == 0) { names.push_back(p2); id[p2] = n++; }
            graph[id[p1]].push_back(id[p2]);
            graphT[id[p2]].push_back(id[p1]);
            cin >> p1;
        }
        vector<pair<string,string> > anomalies;
        for (int i=0; i<n; i++) {
            visited.assign(n,false);
            if (anomaly(i,i)) {
                anomalies.push_back(make_pair(names[i],"paradox"));
            } else {
                visited.assign(n,false);
                if (hillibilly(i)) 
                    anomalies.push_back(make_pair(names[i],"hillibilly"));
            }
        }

        sort(anomalies.begin(), anomalies.end());
        if (!first) cout << endl; first = false; // Remember kids, good indentation is important
        for (auto p : anomalies) cout << p.first << " " << p.second << endl;
        
    }

    return 0;
}