#include <bits/stdc++.h>

using namespace std;

int main() {
    int c; cin >> c;

    for (int t=0; t<c; t++) {
        int deg; cin >> deg;
        vector<int> coeff(deg+1); // n^0 also has a coefficient
        for (int i=0; i<=deg; i++) cin >> coeff[i];
        int d,k; cin >> d >> k;
        int n = 1;
        long long b_i = 0;
        for (int i=0; i<k; i+=n*d, n++) {
            b_i = 0;
            for (int j=0; j<=deg; j++) {
                b_i += coeff[j]*pow(n,j);
            }
        }
        cout << b_i << endl;
    }


    return 0;
}