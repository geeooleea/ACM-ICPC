#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, r;

    while (cin >> f >> r) {
        vector<int> front(f),rear(r);
        for (int i=0; i<f; i++) cin >> front[i];
        for (int i=0; i<r; i++) cin >> rear[i];

        vector<double> ratio;
        for (int f : front) {
            for (int r : rear) {
                ratio.push_back((double)r/f);
            }
        }

        sort(ratio.begin(),ratio.end());
        double maxspread = ratio[1]/ratio[0];
        for (int i=1; i<f*r; i++) maxspread = max(maxspread,ratio[i]/ratio[i-1]);

        cout << setprecision(2) << fixed << maxspread << endl;
    }

    return 0;
}