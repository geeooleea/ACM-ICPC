#include <bits/stdc++.h>

using namespace std;

bool wins(char c1,char c2) {
    if (c1 == 'R') return c2 == 'S';
    if (c1 == 'P') return c2 == 'R';
    if (c1 == 'S') return c2 == 'P';
}

char winner(char c1, char c2) {
    if (c1 == '0') return c2;
    if (c2 == '0') return c1;

    if (wins(c1,c2)) return c1; else return c2;
}

int main() {

    int test; cin >> test;

    for (int t=0; t<test; t++) {
        int r,c,n; cin >> r >> c >> n;

        vector<vector<char> > grid(r,vector<char>(c));

        for (int i=0; i<r; i++) for (int j=0; j<c; j++) cin >> grid[i][j];

        for (int day=0; day<n; day++) {
            vector<vector<char> > grid2(r,vector<char>(c,'0'));

            for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) {
                    if (i-1>=0) {
                        if (wins(grid[i][j],grid[i-1][j]))
                            grid2[i-1][j] = winner(grid[i][j],grid2[i-1][j]);
                        else grid2[i][j] = winner(grid[i-1][j],grid2[i][j]);
                    }
                    if (i+1 < r) {
                        if (wins(grid[i][j],grid[i+1][j]))
                            grid2[i+1][j] = winner(grid[i][j],grid2[i+1][j]);
                        else grid2[i][j] = winner(grid[i+1][j],grid2[i][j]);
                    }
                    if (j-1>=0) {
                        if (wins(grid[i][j],grid[i][j-1]))
                            grid2[i][j-1] = winner(grid[i][j],grid2[i][j-1]);
                        else grid2[i][j] = winner(grid[i][j-1],grid2[i][j]);
                    }
                    if (j+1 < c) {
                        if (wins(grid[i][j],grid[i][j+1]))
                            grid2[i][j+1] = winner(grid[i][j],grid2[i][j+1]);
                        else grid2[i][j] = winner(grid[i][j+1],grid2[i][j]);
                    }
                }
            }

            // SET NEW GRID
            for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) {
                    if (grid2[i][j] != '0') grid[i][j] = grid2[i][j];
                }
            }
        }

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        if (t<test-1) cout << endl;
    }

    return 0;
}