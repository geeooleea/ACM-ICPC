#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n==0) break;
        int x;
        int maxhere = 0, maxsofar = 0;
        for (int i=0; i<n; i++) {
            cin >> x;
            maxhere = max(0,maxhere+x);
            maxsofar = max(maxsofar,maxhere);
        }

        if (maxsofar > 0) {
            cout << "The maximum winning streak is " << maxsofar << "." << endl;
        } else {
            cout << "Losing streak." << endl;
        }
    }
}