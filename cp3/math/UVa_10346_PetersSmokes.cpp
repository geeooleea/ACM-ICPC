#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;

    while (cin >> n >> k) {
        int res = n;

        while (n >= k) {
            res += (n/k);
            n = (n%k + n/k);
        }
        cout << res << endl;
    }

    return 0;
}