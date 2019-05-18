#include <bits/stdc++.h>

using namespace std;

int main() {
    int test, n;
    cin >> test;
    for (int t=0; t<test; t++) {
        cin >> n;
        int m = 1000,M = 0,s;
        for (int i=0; i<n; i++) {
            cin >> s;
            m = min(s,m);
            M = max(s,M);
        }
        cout << 2*(M-m) << endl;
    }
    return 0;
}