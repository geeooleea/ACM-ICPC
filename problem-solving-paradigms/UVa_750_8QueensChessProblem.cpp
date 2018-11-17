// Precalculate all the 8 queen positions (72?) then work by difference
#include <iostream>
#include <cmath>

using namespace std;

int sol_n = 0;

int row[1000][9];

int curr_sol[9];

bool check_pos(int i) {
    for (int j=1; j<i; j++) {
        // Same row
        if (curr_sol[j] == curr_sol[i]) {
            return false;
        }
        // Same diagonal
        if (i-j == fabs(curr_sol[j] - curr_sol[i])) {
            return false;
        }
    }
    return true;
}

void compute_queens(int curr_col) {
    if (curr_col > 8) {
        sol_n++;
        // cout << "Found solution ";
        for (int i=1; i<=8; i++) {
            row[sol_n][i] = curr_sol[i];
            // cout << row[sol_n][i] << " ";
        }
        // cout << endl;
    } else {
        for (int i=1; i<=8; i++) {
            curr_sol[curr_col] = i;
            if (check_pos(curr_col)) {
                compute_queens(curr_col+1);
            }
        }
    }
}

int main() {
    compute_queens(1);
    
    int n,x,y;
    cin >> n;
    int soln;
    for (int i=0; i<n; i++) {
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        cin >> x >> y;
        soln = 0;
        for (int j=1; j <= sol_n; j++) {
            if (row[j][y] == x) {
                soln++;
                cout << (soln < 10 ? " " : "") << soln << "      ";
                for (int k=1; k<=8; k++) {
                    cout << row[j][k] << (k < 8 ? " " : "");
                }
                cout << endl;
            }
        }
        if (i < n-1) cout << endl;
    }
    return 0;
}