#include <bits/stdc++.h>

using namespace std;

int p[100000], r[100000];

typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;

int find(int a) {
    if (p[a] == a) {
        return a;
    }
    return (p[a] = find(p[a])); // Compressione dei cammini
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) {
        return;
    }
    // Euristiche sul rango
    if (r[pa] < r[pb]) { // Swap pa and pb
        int tmp = pa;
        pa = pb;
        pb = tmp;
    }
    p[pb] = pa;
    if (r[pa] == r[pb]) {
        r[pa]++;
    }
}

int main() {
    int k;
    while (cin >> k) {
        map<iii, int > c3_to_id;
        map< ii, int> c2_to_id;

        vector<pair<int, int> > needles3, needles2;

        int id3=0, id2=0;

        int x,y,z,x1,y1,z1;

        for (int i=0; i<k; i++) {
            cin >> x >> y >> z >> x1 >> y1 >> z1;
            iii p1_3 = iii(x,ii(y,z));
            iii p2_3 = iii(x1,ii(y1,z1));

            if (c3_to_id.count(p1_3) == 0) c3_to_id[p1_3] = id3++;
            if (c3_to_id.count(p2_3) == 0) c3_to_id[p2_3] = id3++;

            needles3.push_back(make_pair(min(c3_to_id[p1_3],c3_to_id[p2_3]),max(c3_to_id[p1_3],c3_to_id[p2_3])));

            ii p1_2 = ii(x,y);
            ii p2_2 = ii(x1,y1);

            if (c2_to_id.count(p1_2) == 0) c2_to_id[p1_2] = id2++;
            if (c2_to_id.count(p2_2) == 0) c2_to_id[p2_2] = id2++;

            needles2.push_back(make_pair(min(c2_to_id[p1_2],c2_to_id[p2_2]),max(c2_to_id[p1_2],c2_to_id[p2_2])));
        }

        sort(needles2.begin(),needles2.end());
        sort(needles3.begin(),needles3.end());
        needles2.resize(distance(needles2.begin(), unique(needles2.begin(), needles2.end())));
        needles3.resize(distance(needles3.begin(), unique(needles3.begin(), needles3.end())));

        for (int i=0; i<id3; i++) {
            r[i] = 1;
            p[i] = i;
        }

        bool cycle3d = false;

        for (auto needle : needles3) {
            int a = needle.first;
            int b = needle.second;
            if (a == b) continue;

            if (find(a) == find(b)) {
                cycle3d = true;
            }
            merge(a, b);
        }

        for (int i=0; i<id2; i++) {
            r[i] = 1;
            p[i] = i;
        }

        bool cycle2d = false;

        for (auto needle : needles2) {
            int a = needle.first;
            int b = needle.second;
            if (a == b) continue;

            if (find(a) == find(b)) {
                cycle2d = true;
            }
            merge(a, b);
        }

        if (cycle3d) {
            cout << "True closed chains" << endl;
        } else {
            cout << "No true closed chains" << endl;
        }

        if (cycle2d) {
            cout << "Floor closed chains" << endl;
        } else {
            cout << "No floor closed chains" << endl;
        }
    }
    return 0;
}