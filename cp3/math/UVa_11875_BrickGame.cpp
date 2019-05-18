#include <iostream>

using namespace std;

int a[11];

int main() {
    int test,n;
    cin >> test;
    for (int t=1; t<=test; t++) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        cout << "Case " << t << ": " << a[n/2] << endl;
    }
    return 0;
}