#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

int x[1001];
int y[1001];
int r[1001];

// raggio del padre della ruota i
// se p[i] == -1 non abbiamo ancora considerato i
int p_num[1001];
int p_den[1001];

// se false scrivo counterclockwise
bool clockwise[1001];

const double eps = 0.000000000001;

double dist(int a, int b) {
    return (sqrt ( pow(x[a]-x[b],2) + pow(y[a]-y[b],2) ));
}

int main() {
    int t;
    cin >> t;
    int n;
    for (int asd=0; asd<t; asd++) {
        cin >> n;
        for (int i=0; i<n; i++) {
            p_num[i] = -1;
            clockwise[i] = false;
        }
        for (int i=0; i<n; i++) {
            cin >> x[i] >> y[i] >> r[i];
        }

        cout << "1 clockwise" << endl;
        clockwise[0] = true;
        p_num[0] = 1;
        p_den[0] = 1;

        stack<int> s;
        s.push(0);
        while (!s.empty()) {
            int wheel = s.top();
            s.pop();
            for (int i=1; i<n; i++) {
                if (i != wheel && p_num[i] == -1 
                        && fabs(dist(wheel,i) - (r[wheel] + r[i])) < eps ) {
                    s.push(i);
                    // p_r[i] = r[wheel];
                    p_num[i] = p_num[wheel] * r[wheel];
                    p_den[i] = p_den[wheel] * r[i]; 
                    clockwise[i] = !clockwise[wheel];
                }
            }
        }
        int mcd;
        for (int i=1; i<n; i++) {
            if (p_num[i] == -1) {
                cout << "not moving" << endl;
            } else {
                mcd = __gcd(p_num[i],p_den[i]);
                if (p_den[i]/mcd == 1) {
                    cout << p_num[i] / mcd << " " << (clockwise[i] ? "clockwise" : "counterclockwise") << endl;
                } else {
                    cout << p_num[i] / mcd << "/" << p_den[i] / mcd << " " << (clockwise[i] ? "clockwise" : "counterclockwise") << endl;
                }
            }
        }
    }
    return 0;
}