#include <bits/stdc++.h>

using namespace std;

int main() {
    int test; cin >> test;

    for (int t=0; t<test; t++) {
        int n; cin >> n;
        vector<char> field(n);
        vector<bool> covered(n,false);
        for (int i=0; i<n; i++) cin >> field[i];
        int count = 0;
        for (int i=1; i<=n; i++) {
            if (field[i-1] == '.') {
                count++; i += 2;
            }
        }
        cout << "Case " << t+1 << ": " << count << endl;
    }
    return 0;
}