#include <bits/stdc++.h>

using namespace std;

typedef int T; // Change here for different weight types

struct edge {
    int u, v;
    T d;
};

vector <edge> mst;

struct edgeCmp {
    int operator()(const edge& a, const edge& b) { return a.d > b.d; }
};

T Prim(vector <vector <pair<int, T> > >& w) {
    mst.clear();
    priority_queue<edge, vector<edge>, edgeCmp> E;
    int n=w.size();
    vector<bool> ins(n, false);

    ins[0] = true;
    for (pair<int,int> p : w[0]) { // Node 0 is the root of the MST
        edge e;
        e.u = 0; e.v = p.first; e.d = p.second;
        E.push(e);
    }
    T weight = 0;
    while (mst.size() < n && !E.empty()) {
        edge cur = E.top(); E.pop();
        if (!ins[cur.v]) {
            mst.push_back(cur);
            weight += cur.d;
            for (pair<int, int> p : w[cur.v]) {
                if (!ins[p.first]){
                    edge e;
                    e.u = cur.v; e.v = p.first; e.d = p.second;
                    E.push(e);
                }
            }
        }
    }

    return weight;
}
