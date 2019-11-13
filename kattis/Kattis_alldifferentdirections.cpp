#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;

int main() {
    int n,m;
    cin >> n;
    while (n != 0) {
        vector<double> x(n),y(n);
        cin >> x[0];
        for (int i=0; i<n; i++) {
            cin >> y[i];
            string s;
            double dir;
            cin >> s >> dir; // Read start
            bool curr = true;
            while (curr) {
                cin >> s;
                if (s.compare("turn") == 0) {
                    double dirD; cin >> dirD;
                    dir += dirD;
                } else if (s.compare("walk") == 0) {
                    double ds; cin >> ds;
                    x[i] += ds*cos(dir*PI/180);
                    y[i] += ds*sin(dir*PI/180);
                } else {
                    curr = false;
                    //cout << s << endl;
                    if (i == n-1) m = stoi(s);
                    else x[i+1] = stod(s);
                }
            }
        }
        double xavg = 0.0, yavg = 0.0;
        for (int i=0; i<n; i++) {
            xavg += x[i];
            yavg += y[i];
        }
        xavg /= n; yavg /= n;
        double maxd = 0;
        for (int i=0; i<n; i++) {
            if (maxd*maxd <= pow(xavg-x[i],2)+pow(yavg-y[i],2)) {
                maxd = sqrt(pow(xavg-x[i],2)+pow(yavg-y[i],2));
            }
        }

        cout << fixed << setprecision(3) << xavg << " " << yavg << " " << maxd << endl;

        n=m;
    }
    return 0;
}