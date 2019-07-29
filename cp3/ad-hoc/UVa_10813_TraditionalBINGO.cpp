#include <bits/stdc++.h>

using namespace std;

int card[5][5];

bool checkCard() {
    bool bingo;
    // Check rows
    for (int i=0; i<5; i++) {
        bingo = true;
        for (int j=0; j<5 && bingo; j++) {
            if (card[i][j] != -1) bingo = false;
        }
        if (bingo) { return true; }
    }

    // Check columns
    for (int i=0; i<5; i++) {
        bingo = true;
        for (int j=0; j<5 && bingo; j++) {
            if (card[j][i] != -1) bingo = false;
        }
        if (bingo) { return true; }
    }

    // Check diagonals
    bingo = true;
    for (int i=0; i<5 && bingo; i++) {
        if (card[i][4-i] != -1) bingo = false; 
    }
    if (bingo) { return true; }

    bingo = true;
    for (int i=0; i<5 && bingo; i++) {
        if (card[i][i] != -1) bingo = false; 
    }
    if (bingo) { return true; }

    return false;
}

bool mark(int n) { // If returns true, check card, otherwise useless
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (card[i][j] == n) {
                card[i][j] = -1;
                return true;
            }
        }
    }
    return false;
}

int main() {

    int test; cin >> test;

    for (int t=0; t<test; t++) {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (i == 2 && j == 2) card[i][j] = -1;
                else cin >> card[i][j];
            }
        }

        int n; bool bingo = false;
        for (int i=0; i<75; i++) {
            cin >> n;
            // cout << n << endl;
            if (!bingo && mark(n)) // Consume all input
                if (checkCard()) {
                    bingo = true;
                    cout << "BINGO after " << i+1 << " numbers announced" << endl;
                }
        }
    }

    return 0;
}