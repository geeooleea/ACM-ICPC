#include <iostream>

using namespace std;

int main() {
    int n, t=0;
    while (cin >> n) {
        if (n==0) break;
        cout << "Printing order for " << n << " pages:\n";
        int sheet_n = 1;
        int start = 1, end = n;

        int first_sheet = n%4; // number of pages on first sheet
        switch (first_sheet) {
            case 1: {
                cout << "Sheet " << sheet_n << ", front: Blank, " << start++ << endl;
                if (n > 1) {
                    cout << "Sheet " << sheet_n++ << ", back : " << start++ << ", Blank\n";
                    cout << "Sheet " << sheet_n << ", front: Blank, " << start++ << endl;
                    cout << "Sheet " << sheet_n++ << ", back : " << start++ << ", " << end-- << endl;
                }
                break;
            }
            case 2: {
                cout << "Sheet " << sheet_n << ", front: Blank, " << start++ << endl;
                cout << "Sheet " << sheet_n++ << ", back : " << start++ << ", Blank" << endl;
                break;
            }
            case 3: {
                cout << "Sheet " << sheet_n << ", front: Blank, " << start++ << endl;
                cout << "Sheet " << sheet_n++ << ", back : " << start++ << ", " << end-- << endl;
                break;
            }
        }
        // All blanks are now handled, pages to print are now a multiple of 4
        while (start < end) {
            cout << "Sheet " << sheet_n << ", front: " << end-- << ", " << start++ << endl;
            cout << "Sheet " << sheet_n++ << ", back : " << start++ << ", " << end-- << endl;
        }
    }
}