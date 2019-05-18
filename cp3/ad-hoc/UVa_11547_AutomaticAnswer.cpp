#include <bits/stdc++.h>

using namespace std;

int main() {
    int test, n;
    cin >> test;
    for (int t=0; t<test; t++) {
        cin >> n;
        long long res = ((567*n)/9+7492)*235/47-498;
        cout << ((res%100)/10 < 0 ? -(res%100)/10 : (res%100)/10)  << endl;
    }
    return 0;
}