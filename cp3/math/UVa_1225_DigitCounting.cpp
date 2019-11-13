#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> digits(10,0);

        for (int i=1; i<=n; i++) {
            string num = to_string(i);
            for (int j=0; j<num.length(); j++) {
                digits[num[j]-'0']++;
            }
        }    

        for (int i=0; i<10; i++) {
            cout << digits[i] << (i < 9 ? " " : "\n");
        }
            
    }

    return 0;
}