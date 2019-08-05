#include <bits/stdc++.h>

using namespace std;

int main() {
    int c; cin >> c;
    for (int t=0; t<c; t++) {
        int n; cin >> n;
        vector<string> makers(n);
        vector<int> l(n),h(n);

        for (int i=0; i<n; i++) cin >> makers[i] >> l[i] >> h[i];

        int q,qi; cin >> q;
        for (int i=0; i<q; i++) {
            cin >> qi;
            int res, count = 0;
            for (int j=0; j<n && count < 2; j++) {
                if (l[j] <= qi && qi <= h[j]) {
                    res = j;
                    count++;
                }
            }
            if (count == 1) cout << makers[res] << endl;
            else cout << "UNDETERMINED" << endl;
        }
        if (t < c-1) cout << endl;
    }


    return 0;
}