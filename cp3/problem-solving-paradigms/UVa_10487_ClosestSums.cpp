#include <bits/stdc++.h>

using namespace std;

int main() {

    int t=0,n;
    while (cin >> n && n) {

        vector<long long> v(n);
        for (int i=0; i<n; i++) cin >> v[i];

        vector<long long> sums;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                sums.push_back(v[i]+v[j]);
            }
        }

        // sort(sums.begin(), sums.end());
        cout << "Case " << ++t << ":\n";
        int m,q; cin >> m;
        for (int i=0; i<m; i++) {
            cin >> q;
            int mindiff = q - sums[0];
            for (int x : sums) {
                if (abs(q-x) < abs(mindiff)) {
                    mindiff = q-x;
                }
            }
            cout << "Closest sum to " << q << " is " << q-mindiff << "." << endl;
        }
    }

    return 0;
}