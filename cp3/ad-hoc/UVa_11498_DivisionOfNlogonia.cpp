#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long a,b,n,x,y;
    while (cin >> n) {
        cin >> x >> y;
        for (int i=0; i<n; i++) {
            cin >> a >> b;
            if ((a-x) > 0 && (b-y) > 0) {
                cout << "NE" << endl;
            } else if ((a-x) > 0 && (b-y) < 0) {
                cout << "SE" << endl;
            }else if ((a-x) < 0 && (b-y) < 0) {
                cout << "SO" << endl;
            } else if ((a-x) < 0 && (b-y) > 0) {
                cout << "NO" << endl;
            } else {
                cout << "divisa" << endl;
            }
        }
    }
    return 0;
}