#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int x[1000];
int y[1000];

double maxedge = 0.0;

typedef double T;

struct edge
{
    int u, v;
    T d;
};

struct edgeCmp
{
    int operator()(const edge &a, const edge &b) { return a.d > b.d; }
};

int find(vector<int> &C, int x) { return (C[x] == x) ? x : C[x] = find(C, C[x]); }

T Kruskal(vector<vector<T>> &w)
{
    int n = w.size();
    T weight = 0;

    vector<int> C(n), R(n);
    for (int i = 0; i < n; i++)
    {
        C[i] = i;
        R[i] = 0;
    }

    vector<edge> T;
    priority_queue<edge, vector<edge>, edgeCmp> E;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (w[i][j] >= 0)
            {
                edge e;
                e.u = i;
                e.v = j;
                e.d = w[i][j];
                E.push(e);
            }

    while (T.size() < n - 1 && !E.empty())
    {
        edge cur = E.top();
        E.pop();

        int uc = find(C, cur.u), vc = find(C, cur.v);
        if (uc != vc)
        {
            T.push_back(cur);
            weight += cur.d;
            if (cur.d > maxedge) {
                maxedge = cur.d;
            }

            if (R[uc] > R[vc])
                C[vc] = uc;
            else if (R[vc] > R[uc])
                C[uc] = vc;
            else
            {
                C[vc] = uc;
                R[uc]++;
            }
        }
    }

    return weight;
}

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<vector<double> > graph(n,vector<double>(n,-1));
    double dist;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j != i) {
                dist = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
                graph[i][j] = dist;
                graph[j][i] = dist;
            }
        }
    }
    Kruskal(graph);
    cout << (int)ceil(maxedge) << endl;
    return 0;
}