#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char> > vvc;
typedef vector<char> vc;

enum CMD_T { P, L, R, C };

string letters[26][5] = {
    { ".***..", "*...*.", "*****.", "*...*.", "*...*." }, // A
    { "****..", "*...*.", "****..", "*...*.", "****.." }, // B
    { ".****.", "*...*.", "*.....", "*.....", ".****." }, // c
    { "****..", "*...*.", "*...*.", "*...*.", "****.." }, // D
    { "*****.", "*.....", "***...", "*.....", "*****." }, // E
    { "*****.", "*.....", "***...", "*.....", "*....." }, // F
    { ".****.", "*.....", "*..**.", "*...*.", ".***.." }, // G
    { "*...*.", "*...*.", "*****.", "*...*.", "*...*." }, // H
    { "*****.", "..*...", "..*...", "..*...", "*****." }, // I
    { "..***.", "...*..", "...*..", "*..*..", ".**..." }, // J
    { "*...*.", "*..*..", "***...", "*..*..", "*...*." }, // K
    { "*.....", "*.....", "*.....", "*.....", "*****." }, // L
    { "*...*.", "**.**.", "*.*.*.", "*...*.", "*...*." }, // M
    { "*...*.", "**..*.", "*.*.*.", "*..**.", "*...*." }, // N
    { ".***..", "*...*.", "*...*.", "*...*.", ".***.." }, // O
    { "****..", "*...*.", "****..", "*.....", "*....." }, // P
    { ".***..", "*...*.", "*...*.", "*..**.", ".****." }, // Q
    { "****..", "*...*.", "****..", "*..*..", "*...*." }, // R
    { ".****.", "*.....", ".***..", "....*.", "****.." }, // S
    { "*****.", "*.*.*.", "..*...", "..*...", ".***.." }, // T
    { "*...*.", "*...*.", "*...*.", "*...*.", ".***.." }, // U
    { "*...*.", "*...*.", ".*.*..", ".*.*..", "..*..." }, // V
    { "*...*.", "*...*.", "*.*.*.", "**.**.", "*...*." }, // W
    { "*...*.", ".*.*..", "..*...", ".*.*..", "*...*." }, // X
    { "*...*.", ".*.*..", "..*...", "..*...", "..*..." }, // Y
    { "*****.", "...*..", "..*...", ".*....", "*****." }, // Z
};

// HERE r AND c ARE ZERO BASED!!
void printC1Util(vvc &sheet, string s, int r, int c) {
    for (int i=0; i<s.length() && i+c<60; i++) {
        if (s[i] != ' ') sheet[r][i+c] = s[i];
    }
}

void printC1(vvc &sheet, string s, CMD_T format, int r, int c) {
    r--;
    switch (format) {
        case P: c--; break;
        case L: c = 0; break;
        case R: c = max((int)0,(int)(60-s.length())); break;
        case C: {
            while (s.length() > 60) {
                s.erase(0,0);
                if (s.length() > 60) s.erase(s.length(),s.length());
            }
            c = max((int)0,(int)(30-s.length()/2)); break;
        }

    }
    printC1Util(sheet,s,r,c);
}

// HERE r AND c ARE ZERO BASED!!
void printC5Util(vvc &sheet, int lett, int r, int c) {
    for (int i=0; i<5 && r+i < sheet.size(); i++) {
        for (int j=0; j<6 && c+j < sheet[0].size(); j++) {
            if (letters[lett][i][j] == '*') {
                sheet[r+i][c+j] = '*';
            }
        }
    }
}

void printC5(vvc &sheet, string s, CMD_T format, int r, int c) {
    r--;
    switch (format) {
        case P:
            c--;
            for (int i=0; i<s.length() && c+6*i < 60; i++) {
                if (s[i] != ' ') {
                    printC5Util(sheet,s[i]-'A',r,c+6*i);
                }
            }
            break;
        case L:
            c = 0;
            for (int i=0; i<s.length() && c+6*i < 60; i++) {
                if (s[i] != ' ') {
                    printC5Util(sheet,s[i]-'A',r,c+6*i);
                }
            }
            break;
        case R:
            c = 60;
            for (int i=s.length()-1; i>=0 && s.length()-i >= 0; i--) {
                if (s[i] != ' ') {
                    printC5Util(sheet,s[i]-'A',r,c-6*(s.length()-i));
                }
            } // No leftover characters, exactly 10 fit in 1 page
            break;
        case C: {
            vvc line (5,vc(6*s.length(),'.'));
            for (int i=0; i<s.length(); i++) {
                if (s[i] != ' ') {
                    printC5Util(line,s[i]-'A',0,6*i);
                }
            }

            while (line[0].size() > 60) {
                for (int i=0; i<5; i++) { 
                    line[i].erase(line[i].begin());
                    if (line[i].size() > 60)
                        line[i].erase(line[i].end()-1); 
                }
            }

            c = max(0,(int)(30-line[0].size()/2));
            for (int i=0; i<5 && r+i < 60; i++) {
                for (int j=0; j<line[i].size() && j+c < 60; j++) {
                    if (line[i][j] == '*')
                        sheet[r+i][j+c] = '*';
                }
            }

            break;
        }
    }
}

int main() {

    string cmd = "BUH";

    while (cmd[0] != EOF && cin >> cmd) {
        vvc sheet(60,vc(60,'.'));
        
        while (cmd.compare(".EOP") != 0 && cmd[0] != EOF) {
            string font,s;
            int r,c=0;
            CMD_T type;
            cin >> font >> r;
            switch (cmd[1]) {
                case 'P':
                    cin >> c;
                    type = P;
                    break;
                case 'L':
                    type = L;
                    break;
                case 'R':
                    type = R;
                    break;
                case 'C':
                    type = C;
                    break;
            }

            // READ TEXT STRING
            while (getchar() != '|') ; // Read space and first |
            char let;
            while ((let = getchar()) != '|') {
                s.push_back(let);
            }

            if (font.compare("C1") == 0) {
                printC1(sheet,s,type,r,c);
            } else {
                printC5(sheet,s,type,r,c);
            }
            cin >> cmd;
        }

        // PRINT SHEET
        for (int i=0; i<60; i++) {
            for (int j=0; j<60; j++) {
                cout << sheet[i][j];
            }
            cout << endl;
        }

        // PAGE SEPARATION
        cout << endl;
        for (int i=0; i<60; i++) cout << "-";
        cout << endl << endl;
    }

    return 0;
}