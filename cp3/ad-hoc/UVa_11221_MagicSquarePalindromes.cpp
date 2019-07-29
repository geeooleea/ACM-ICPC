#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char> > vvc;

int isSquare(int n) {
    for (int i=1; i<=ceil(sqrt(n)); i++) {
        if (i*i == n) return i;
    }
    return 0;
}

bool isMagic(vvc &square, int k) {
    // Check symmetry for top-left bottom-right diagonal
    for (int i=0; i<k; i++) {
        for (int j=i; j<k; j++) {
            if (square[i][j] != square[k-i-1][k-j-1]) return false;
        }
    }
    
    // Check symmetry for top-rigth bottom-left diagonal
    for (int i=0; i<k; i++) {
        for (int j=0; j<=i; j++) {
            if (square[i][j] != square[k-i-1][k-j-1]) return false;
        }
    }
    
    return true;
}

int main() {

    int test; cin >> test;
    getchar(); // Consume \n after test case number for getline()

    for (int t=0; t<test; t++) {
        string line; getline(cin,line);
        string palindrome;
        for (char c : line) {
            if (c >= 'a' && c <='z') palindrome.push_back(c);
        }
        
        cout << "Case #" << t+1 << ":\n";
        int k;
        if (palindrome.length() == 0) cout << 0 << endl;
        else if (k = isSquare(palindrome.length())) {
            // BUILD POSSIBLE MAGIC SQUARE
            vvc square(k, vector<char>(k));
            for (int i=0; i<k; i++) {
                for (int j=0; j<k; j++) {
                    square[i][j] = palindrome[i*k+j];
                }
            }
            if (isMagic(square,k)) cout << k << endl;
            else cout << "No magic :(" << endl;
        } else {
            cout << "No magic :(" << endl;
        }
    }

    return 0;
}