#include <bits/stdc++.h>
using namespace std;

int b,w;
int x,y;

typedef vector<vector<int> > vvi;

void turnLeft() {
    if (x == 1) {
        x = 0; y = -1;
    } else if (x == -1) {
        x = 0; y = 1;
    } else if (x == 0) {
        if (y == 1) {
            x=1; y=0;
        } else {
            x=-1; y=0;
        }
    }
}

void turnRight() {
    if (x == 1) {
        x = 0; y = +1;
    } else if (x == -1) {
        x = 0; y = -1;
    } else if (x == 0) {
        if (y == 1) {
            x=-1; y=0;
        } else {
            x=+1; y=0;
        }
    }
}

/*
bool offMaze(int i, int j) {
    if (i >= 0 && i < w && j >=0 && j < b) return false;
    cout << "Off maze!" << endl;
    return true;
}
*/

void solve(vector<vector<char> > &maze, vvi &count, int i, int j, bool first) {
    if (i==1 && j==b && !first) { // The robot is back at the entrance
        //cout << "returning" << endl;
        return;
    }
    count[j][i]++; 
    //cout << j << " " << i << endl;
    if (maze[j+x][i-y] != '1') turnRight(); // No wall on the right-hand side
    while (maze[j+y][i+x] == '1') turnLeft(); // Don't walk agaist walls
    solve(maze, count, i+x, j+y, false);
}

void print(vvi &count, vector<vector<char> > &maze) {
    int zero = 0, one = 0, two = 0, three = 0, four = 0;
    for (int i=0; i<=b+1; i++) {
        for (int j=0; j<=w+1; j++) {
            if (maze[i][j] == '0')
                switch (count[i][j]) {
                    case 0: zero++; break;
                    case 1: one++; break;
                    case 2: two++; break;
                    case 3: three++; break;
                    case 4: four++; break;
                }
        }
    }
    std::cout.width(3);
    std::cout << std::right << zero;
    std::cout.width(3);
    std::cout << std::right << one;
    std::cout.width(3);
    std::cout << std::right << two;
    std::cout.width(3);
    std::cout << std::right << three;
    std::cout.width(3);
    std::cout << std::right << four << endl;
}

int main() {
    while (cin >> b >> w) {
        if (b==0 && w==0) return 0;

        vector<vector<char> > maze(b+2,vector<char>(w+2,'1'));
        vvi count(b+2,vector<int>(w+2,0));
        for (int i=1; i<=b; i++) {
            for (int j=1; j<=w; j++) {
                cin >> maze[i][j];
            }
            getchar();
        }
        /*
        for (int i=0; i<=b+1; i++) {
            for (int j=0; j<=w+1; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }
        */
        x=1, y=0;

        solve(maze, count, 1, b, true);
        /*
        cout << endl;
        for (int i=0; i<b+2; i++) {
            for (int j=0; j<w+2; j++) {
                cout << count[i][j];
            }
            cout << endl;
        }
        */
        print(count, maze);
    }
    return 0;
}