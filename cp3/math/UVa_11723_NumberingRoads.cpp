#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double r,n;
    int c = 1;
    while (cin >> r >> n) {
        if (n == 0 && r == 0) break;
        if (r > 27*n) {
            cout << "Case " << c++ << ": impossible" << endl;
        } else {
            cout << "Case " << c++ << ": " << ceil(r/n) - 1 << endl;
        }
    }

    return 0;
}