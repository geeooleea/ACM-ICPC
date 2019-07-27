#include <bits/stdc++.h>

using namespace std;

void setRowCol(int i, int j, vector<vector<bool> > &attack,  vector<vector<char> > &board) {
    int k = j+1;
    while (j < 8 && board[i][k] == '0') { // right horizontal
        attack[i][k] = true;
        k++;
    }

    k = j-1;
    while (j > 0 && board[i][k] == '0') { // left horizontal
        attack[i][k] = true;
        k--;
    }

    k = i+1;
    while (i < 8 && board[i][k] == '0') { // lower vertical
        attack[k][j] = true;
        k++;
    }

    k = i-1;
    while (i > 0 && board[i][k] == '0') { // upper vertical
        attack[k][j] = true;
        k--;
    }
} 

void setDiag(int i, int j, vector<vector<bool> > &attack, vector<vector<char> > &board) {
    int di = i, dj = j;
    while (di < 7 && dj < 7 && board[di][dj] == '0') attack[++di][++dj] = true; // from (i,j) to bottom right
    di = i, dj = j;
    while (di < 7 && dj > 0 && board[di][dj] == '0') attack[++di][--dj] = true; // from (i,j) to bottom left
    di = i, dj = j;
    while (di > 0 && dj > 0 && board[di][dj] == '0') attack[--di][--dj] = true; // from (i,j) to top left
    di = i, dj = j;
    while (di > 0 && dj < 7 && board[di][dj] == '0') attack[--di][++dj] = true; // from (i,j) to top right
}

int main() {

    char c = getchar();

    while (cin >> c) {
        cout << "START READING INPUT " << endl;
        // READ FEN DESCRIPTION
        vector<vector<char> > board(8,vector<char>(8,'0'));
        int i=0, j=0;
        if (c >= '0' && c <='8') j += (c-'0'); // Handle first character
        else board[i][j] = c;

        while (c != '\n' && c != EOF) {
            c = getchar();
            while (c != '/' && c != '\n' && c != EOF) {
                if (c >= '0' && c <='8') j += (c-'0'); // Handle first character
                else board[i][j] = c;
                c = getchar();
            }
            i++;
        }
        cout << "READ INPUT" << endl;
        // COMPUTE ATTACKS
        vector<vector<bool> > attack(8,vector<bool>(8,false));
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                switch (board[i][j]) {
                    case 'k': case 'K': 
                        attack[i][j] = true;
                        if (i-1 > 0 && j-1 > 0) attack[i-1][j-1] = true;
                        if (i-1 > 0) attack[i-1][j] = true;
                        if (j-1 > 0) attack[i][j-1] = true;
                        if (i+1 < 8 && j+1 < 8) attack[i+1][j+1] = true;
                        if (i+1 < 8) attack[i+1][j] = true;
                        if (j+1 < 8) attack[i][j+1] = true;
                        if (i-1 > 0 && j+1 < 8) attack[i-1][j+1] = true;
                        if (i+1 < 8 && j-1 > 0) attack[i+1][j-1] = true;
                        break;
                    case 'q': case 'Q':
                        attack[i][j] = true;
                        setRowCol(i,j,attack,board);
                        setDiag(i,j,attack,board);
                        break;
                    case 'r': case 'R':
                        attack[i][j] = true;
                        setRowCol(i,j,attack,board);
                        break;
                    case 'b': case 'B':
                        attack[i][j] = true;
                        setDiag(i,j,attack,board);
                        break;
                    case 'n': case 'N':
                        attack[i][j] = true;
                        if (i-2 > 0 && j-1 > 0) attack[i-2][j-1] = true;
                        if (i-2 > 0 && j+1 < 8) attack[i-2][j+1] = true;
                        if (i+2 < 8 && j-1 > 0) attack[i+2][j-1] = true;
                        if (i+2 < 8 && j+1 < 8) attack[i+2][j+1] = true;
                        if (i+1 < 8 && j+2 < 8) attack[i+1][j+2] = true;
                        if (i+1 < 8 && j-2 > 0) attack[i+1][j-2] = true;
                        if (i-1 > 0 && j+2 < 8) attack[i-1][j+2] = true;
                        if (i-1 > 0 && j-2 > 0) attack[i-1][j-2] = true;
                        break;
                    case 'P':
                        attack[i][j] = true;
                        if (i+1 < 8) {
                            if (j-1 > 0) attack[i+1][j-1] = true;
                            if (j+1 < 8) attack[i+1][j+1] = true;
                        }
                        break;
                    case 'p':
                        attack[i][j] = true;
                        if (i-1 > 0) {
                            if (j-1 > 0) attack[i+1][j-1] = true;
                            if (j+1 < 8) attack[i+1][j+1] = true;
                        }
                        break;
                }
            }
        }
        // COUNT ATTACKS
        int count = 0;
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (!attack[i][j]) count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}