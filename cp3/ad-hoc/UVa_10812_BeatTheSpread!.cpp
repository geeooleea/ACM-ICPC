#include <iostream>

using namespace std;

int main() {
    int n,x,y,a,b;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        b = ((x-y) % 2 == 0 ? (x-y)/2 : -1);
        if (b < 0) {
            cout << "impossible\n";
        } else {
            a = b+y;
            cout << a << " " << b << endl;
        }
    }
    return 0;
}