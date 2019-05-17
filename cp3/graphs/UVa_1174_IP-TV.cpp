#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef int T;

struct edge
{
  int u, v;
  T d;
};

struct edgeCmp
{
  int operator()(const edge& a, const edge& b) { return a.d > b.d; }
};

int find(vector <int>& C, int x) { return (C[x] == x) ? x : C[x] = find(C, C[x]); }

T Kruskal(vector <vector <T> >& w)
{
  int n = w.size();
  T weight = 0;
  
  vector <int> C(n), R(n);
  for(int i=0; i<n; i++) { C[i] = i; R[i] = 0; }
  
  vector <edge> T;
  priority_queue <edge, vector <edge>, edgeCmp> E;
  
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
      if(w[i][j] >= 0)
      {
        edge e;
        e.u = i; e.v = j; e.d = w[i][j];
        E.push(e);
      }
      
  while(T.size() < n-1 && !E.empty())
  {
    edge cur = E.top(); E.pop();
    
    int uc = find(C, cur.u), vc = find(C, cur.v);
    if(uc != vc)
    {
      T.push_back(cur); weight += cur.d;
      
      if(R[uc] > R[vc]) C[vc] = uc;
      else if(R[vc] > R[uc]) C[uc] = vc;
      else { C[vc] = uc; R[uc]++; }
    }
  }
  
  return weight;
}

int main() {
    int test;
    cin >> test;
    int n,m;

    for (int t=0; t<test; t++) {
        cin >> n >> m;
        vector<vector<int> > graph(n,vector<int>(n,-1));
        unordered_map<string,int> cities;
        int x = 0, w;
        for (int i=0; i<m; i++) {
            string s1, s2;
            cin >> s1 >> s2 >> w;
            if (cities.count(s1) == 0) {
                cities[s1] = x++;
            }
            if (cities.count(s2) == 0) {
                cities[s2] = x++;
            }

            graph[cities[s1]][cities[s2]] = w;
            graph[cities[s2]][cities[s1]] = w;
        }

        cout << Kruskal(graph) << endl;
        if (t<test-1) cout << endl;
    }
    
    return 0;
}