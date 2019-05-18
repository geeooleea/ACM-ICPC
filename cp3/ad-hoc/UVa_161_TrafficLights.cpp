#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int cycle[1000];

int main() {
    int n = 0;
    while (cin >> cycle[n]) {
        if (cycle[n] == 0) { break; }
        int min_c = cycle[n];
        while (cycle[n] != 0) {
            n++;
            cin >> cycle[n];
            if (cycle[n] != 0) min_c = min(min_c,cycle[n]);
        }
        // for (int i=0; i<n; i++) { cout << cycle[i] << " "; } cout << endl;
        bool found = false;
        bool red = false;
        // cout << min_c << endl;
        for (int t=min_c+1; t<5*60*60+1 && !found; t++) {
            red = false;
            for (int i=0; i<n && !red; i++) {
                if (t % (2*cycle[i]) >= cycle[i] - 5) {
                    //cout << i << " red at time " << t << endl;
                    red = true;
                }
            }
            if (!red) {
                //cout << t << endl;
                int seconds = t % 60;
                int minutes = (t % 3600) / 60;
                int hours = t/3600;
                cout << setfill('0') << setw(2) << hours << ":" <<
                        setfill('0') << setw(2) << minutes << ":" <<
                        setfill('0') << setw(2) << seconds << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Signals fail to synchronise in 5 hours" << endl;
        }

        n = 0;
    }
    return 0;
}