#include<iostream>
#include <cmath>

using namespace std;

int main() {
    int test;
    cin >> test;
    char piece;
    int a,b;
    for (int t=0; t<test; t++) {
        cin >> piece >> a >> b;
        switch (piece) {
            case 'r':
                cout << min(a,b) << endl;
                break;
            case 'K':
                cout << ceil(a/2.0)*ceil(b/2.0) << endl;
                break;
            case 'Q':
                cout << min(a,b) << endl;
                break;
            case 'k':
                cout << ceil((a*b)/2.0) << endl;
                break;
        }
    }

    return 0;
}