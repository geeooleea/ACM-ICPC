#include <bits/stdc++.h>

using namespace std;

typedef long long T; // Change here for different weights

vector<T> dist(10001); 

const T INF = INT64_MAX; // Also remember to change infinity accordingly

struct maxPQ {
    int operator()(const pair<T,int>& a, const pair<T,int>& b) { return a.first > b.first; }
};

void Dijkstra(vector<vector<pair<int,T> > > &graph, int source) {
    fill(dist.begin(), dist.end(), INF);
    priority_queue<pair<T,int>, vector<pair<T,int> >, maxPQ> q;

    dist[source] = 0;
    q.push(make_pair(0, source));

    while (!q.empty()) {
        int u = q.top().second;
        T d = q.top().first;
        q.pop();
        if (d == dist[u]) { // Otherwise it is not the shortest path insertion into the queue
            for (int i=0; i<graph[u].size(); i++) {
                int v = graph[u][i].first; T w = graph[u][i].second;
                if (dist[v] > d+w) {
                    q.push(make_pair(dist[v] = d+w,v));
                }
            }
        }
    }
}