#include <iostream>

using namespace std;

int *p;
int *r;

void init(int n) {
    p = new int[n];
    r = new int[n];
    for (int i=0; i<n; i++) {
        p[i] = i; r[i] = 0;
    }
}

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