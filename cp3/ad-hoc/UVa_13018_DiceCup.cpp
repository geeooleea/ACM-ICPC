// problem 7275

using namespace std;

#include <iostream>

int main() {
    int x,y;
    bool first = true;
    while (cin >> x >> y) {
        if (!first) cout << endl;
        first = false;
        if (x < y) {
            int m = x;
            x = y;
            y = m;
        }
        for (int i=y+1; i<=x+1; i++) {
            cout << i << endl;
        }
    }
}
/*
Die: 4 4: { 1, 5 }
Die: 4 5: { 2, 5, 6 }
Die: 4 6: { 3, 5, 6, 7 }
Die: 4 7: { 4, 5, 6, 7, 8 }
Die: 4 8: { 5, 5, 6, 7, 8, 9 }
Die: 4 9: { 6, 5, 6, 7, 8, 9, 10 }
Die: 4 10: { 7, 5, 6, 7, 8, 9, 10, 11 }
Die: 5 5: { 1, 6 }
Die: 5 6: { 2, 6, 7 }
Die: 5 7: { 3, 6, 7, 8 }
Die: 5 8: { 4, 6, 7, 8, 9 }
Die: 5 9: { 5, 6, 7, 8, 9, 10 }
Die: 5 10: { 6, 6, 7, 8, 9, 10, 11 }
Die: 6 6: { 1, 7 }
Die: 6 7: { 2, 7, 8 }
Die: 6 8: { 3, 7, 8, 9 }
Die: 6 9: { 4, 7, 8, 9, 10 }
Die: 6 10: { 5, 7, 8, 9, 10, 11 }
Die: 7 7: { 1, 8 }
Die: 7 8: { 2, 8, 9 }
Die: 7 9: { 3, 8, 9, 10 }
Die: 7 10: { 4, 8, 9, 10, 11 }
Die: 8 8: { 1, 9 }
Die: 8 9: { 2, 9, 10 }
Die: 8 10: { 3, 9, 10, 11 }
Die: 9 9: { 1, 10 }
Die: 9 10: { 2, 10, 11 }
Die: 10 10: { 1, 11 }
*/