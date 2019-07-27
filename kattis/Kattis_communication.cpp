#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int x;
    cin >> n;
    while (n--) {
        cin >> x;
        int last = 0;
        int res = 0;
        for (int i=1; i<=8; i++) {
            if (last == 0 && x % (int)pow(2,i) == 0 || last == 1 && x % (int)pow(2,i) != 0) {
                last = 0;
            } else {
                last = 1;
            }
            res += last * pow(2,i-1);
            x -= x % (int)pow(2,i);
        }
        cout << res << " ";
    }

    return 0;
}