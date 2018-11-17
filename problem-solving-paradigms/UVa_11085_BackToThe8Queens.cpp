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

int check(int pos[]) {
    int min_diff = 10, curr_diff;
    for (int i=1; i<=sol_n; i++) {
        curr_diff = 0;
        for (int j=1; j<=8; j++) {
            if (row[i][j] != pos[j]) {
                curr_diff++;
            }
        }
        min_diff = min(min_diff,curr_diff);
    }

    return min_diff;
}

int main() {
    compute_queens(1);
    
    int pos[9];
    int i=0;
    while (cin >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5] >> pos[6] >> pos[7] >> pos[8]) {
        cout << "Case " << ++i << ": " << check(pos) << endl;
    }
    
    return 0;
}