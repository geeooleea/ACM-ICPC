#include <iostream>
#include <cmath>
using namespace std;

int diff(int a,int b) {
    return (a < b ? (40 - b + a) : (a-b));
}

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    while (!(a == 0 && b == 0 && c == 0 && d == 0)) {
        cout << 720 + diff(a,b) * 9 + 360 + 
                    diff(c,b) * 9
                     + diff(c,d) * 9 << endl;
        cin >> a >> b >> c >> d;
    }
    return 0;
}