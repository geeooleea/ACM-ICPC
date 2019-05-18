#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int v[100001];
int tail[100001] = {0};
int p[100001];
int n = 0;

int binary_search(int l, int r, int i) {
    while (r-l > 1) {
        int m = l+(r-l)/2;
        if(v[tail[m]] >= v[i]) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int lis() {
    int len = 1;
    tail[0] = 0;
    p[0] = 0;
    for (int i=1; i<n; i++) {
        if (v[i] <= v[tail[0]]) {
            p[i] = i;
            tail[0] = i;
        } else if (v[i] > v[tail[len-1]]) {
            p[i] = tail[len-1];
            tail[len++] = i;
        } else {
            int index = binary_search(-1,len-1,i);
            p[i] = tail[index-1];
            tail[index] = i;
        }
    }
    
    return len;
}

int main() {
    while (cin >> v[n]) {
        n++;
    }
    int len = lis();
    cout << len << endl << "-" << endl;
    
    int i = tail[len-1];
    
    stack<int> s;
    s.push(i);
    while (p[i] != i) {
        s.push(p[i]);
        i = p[i];
    }

    while (!s.empty()) {
        cout << v[s.top()] << endl;
        s.pop();
    }
}