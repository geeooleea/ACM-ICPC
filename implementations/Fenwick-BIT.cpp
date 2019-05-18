#include<bits/stdc++.h>
#define LSOne(S) (S & (-S))

using namespace std;

typedef long long T;

struct fenwick {
    vector<T> tree;
    int size;

    void build(int n) {
        size = n;
        tree.resize(n+1,0); 
    }

    T rangeSum(int b) {
        T sum = 0;
        while (b!=0) {
            sum += tree[b]; b -= LSOne(b);
        }
        return sum;
    }

    T rangeSum(int a, int b) {
        return rangeSum(b) - (a==1 ? 0 : rangeSum(a-1));
    }

    void update(int k, T v) {
        k++;
        while (k <= size) {
            tree[k] += v;
            k += LSOne(k);
        }
    }
};