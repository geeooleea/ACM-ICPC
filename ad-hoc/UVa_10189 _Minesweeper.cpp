#include <iostream>

using namespace std;

char field[102][102];

int main() {
    int n,m;
    int i=1;
    while (cin >> n >> m) {
        if (n==0 && m == 0) break;
        cout << (i > 1 ? "\n" : "") << "Field #" << i++ << ":\n";
        for (int i=0; i<=n+1; i++) {
            for (int j=0; j<=m+1; j++) {
                if (i==0 || i==n+1 || j == 0 || j == m+1) {
                    field[i][j] = '.';
                } else {
                    cin >> field[i][j];
                }
            }
        }

        int count;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) { 
                    count = 0;
                    if (field[i][j] == '.') {
                        if (field[i-1][j-1] == '*') count++;
                        if (field[i][j-1] == '*') count++;
                        if (field[i+1][j-1] == '*') count++;
                        if (field[i+1][j] == '*') count++;
                        if (field[i+1][j+1] == '*') count++;
                        if (field[i][j+1] == '*') count++;
                        if (field[i-1][j+1] == '*') count++;
                        if (field[i-1][j] == '*') count++;
                        cout << count;
                } else {
                    cout << "*";
                }
            }
            cout << endl;
        }
    }
    return 0;
}