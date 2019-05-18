#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b,n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        cout << (a/3) * (b/3) << endl;
    }
    return 0;
}