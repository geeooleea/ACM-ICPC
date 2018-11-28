#include <iostream>

using namespace std;

bool broken[1000001] = { false };
// int disk[1000001] = { 0};
int main() {
    int n,c,b;
    cin >> n >> c >> b;
    int x;
    for (int i=0; i<b; i++) {
        cin >> x;
        broken[x] = true;
    }
    // for (int i=0; i<=n; i++) cout << broken[i] << " ";
    // cout << endl;
    int switches = 0;
    int i;
    if (c % 2 == 0) {   // Pari disk[1] off
        cout << 0;
        i=2;
        
    } else {    // dispari Disk[1] o
        cout << 1;
        switches++;
        cout << 0;
        i=3;
    }

    for (; i<=n && switches < c-1; i++) {
        if (!broken[i]) {
            cout << 1;
            switches+=2;
            i++;
        }
        cout << 0;
    }
    for (; i<=n; i++) {
        cout << 0;
    }
    cout << endl;
    return 0;
}