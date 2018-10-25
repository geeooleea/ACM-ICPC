#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    while (!(a == 0 && b == 0 && c == 0 && d == 0)) {
        cout << 720 + (a > b ? (40 - b + a) : (a-b)) * 9 + 720 + fabs(c+40-b) * 9 + fabs(40-d+c) * 9 << endl;
        cin >> a >> b >> c >> d;
    }
    return 0;
}