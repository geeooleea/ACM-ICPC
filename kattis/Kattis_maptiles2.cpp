#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    cout << s.length() << " ";

    int l = pow(2,s.length());
    int x = 0, y = 0;
    for (char c : s) {
        l/=2;
        switch (c) {
            case '0': break;
            case '1': x += l; break;
            case '2': y += l; break;
            case '3': x+=l; y+=l; break;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}