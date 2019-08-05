#include <bits/stdc++.h>

using namespace std;

int main() {

    int c; cin >> c;
    for (int t=0; t<c; t++) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];

        int sum = 0;
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (v[j] <= v[i]) sum++;
            }
        }

        cout << sum << endl;
    }

    return 0;
}