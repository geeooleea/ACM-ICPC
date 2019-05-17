#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double u,v,d;
    int test;
    cin >> test;

    for (int t = 1; t<=test; t++) {
        cin >> d >> v >> u;

        double t1 = d/u;
        if (u > v && v != 0) {
            double t2 = d/(u*sin(acos(v/u)));
            cout << setprecision(3) << fixed << "Case " << t << ": " << fabs(t1-t2) << endl;
        } else {
            cout << "Case " << t << ": can't determine" << endl;
        }
    }

    return 0;
}