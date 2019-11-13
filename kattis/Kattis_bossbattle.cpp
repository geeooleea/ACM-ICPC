#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int b = 1; n--;

    while (n >= 3) { b++; n--; }
    cout << b;
    return 0;
}