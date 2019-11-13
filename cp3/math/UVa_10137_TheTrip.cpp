#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n && n > 0) {
        double avg = 0.0;
        vector<double> cost(n, 0.0);
        for (int i=0; i<n; i++) {
            cin >> cost[i]; avg += cost[i];
        }

        avg /= n;
        cout << avg << endl;
        double diff = 0.0;
        for (int i=0; i<n; i++) {
            diff += (cost[i]-avg > 0 ? cost[i]-avg : 0);
            cout << diff << endl;
        }
        cout /* << setprecision(2) << fixed */ << "$" << diff << endl;
    }

    return 0;
}