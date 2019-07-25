#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "PERFECTION OUTPUT" << endl;
    while (cin >> n) {
        if (n==0) break;
        int sum = 0;
        for (int i=1; i<n; i++) {
            if (n%i == 0) {
                sum += i;
            }
        }
        // Right-justify n
        int blank=1;
        for (int i=1; i<=n; i*=10) blank++;
        for (int i=blank; i<=5; i++) cout << " ";
        cout << n << "  ";
        if (sum == n) cout << "PERFECT" << endl;
        else if (sum < n) cout << "DEFICIENT" << endl;
        else cout << "ABUNDANT" << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}