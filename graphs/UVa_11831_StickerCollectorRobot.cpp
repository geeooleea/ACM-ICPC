#include <iostream>

using namespace std;

char grid[102][102];

enum geo { NORTH, EAST, SOUTH, WEST };
int dir;
int px,py;

int main() {
    int n,m,s;
    while (cin >> n >> m >> s) {
        if (!n && !m && !s) break;
        for (int i=0; i<102; i++) for (int j=0; j<102; j++) grid[i][j] = '\0';
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                cin >> grid[i][j];
                switch (grid[i][j]) {
                    case 'N': dir = NORTH; px = i; py = j; grid[i][j] = '.'; break;
                    case 'L': dir = EAST; px = i; py = j; grid[i][j] = '.'; break;
                    case 'O': dir = WEST; px = i; py = j; grid[i][j] = '.'; break;
                    case 'S': dir = SOUTH; px = i; py = j; grid[i][j] = '.'; break;
                }
            }
        }

        char move;
        int count = 0;
        for (int i=0; i<s; i++) {
            cin >> move;
            if (move == 'D') dir = (dir + 1) % 4;
            if (move == 'E') dir = (dir-1 < 0 ? WEST : dir - 1);
            if (move == 'F') {
                switch (dir) {
                    case NORTH:
                        // cout << "found " << grid[px-1][py] << " ";
                        switch (grid[px-1][py]) {
                            case '#': break;
                            case '*': px--; count++; grid[px][py] = '.'; break;
                            case '.': px--; break;
                        }
                        break;
                    case EAST:                       
                        switch (grid[px][py+1]) {
                            case '#': break;
                            case '*': py++; count++; grid[px][py] = '.'; break;
                            case '.': py++; break;
                        }
                        break;
                    case SOUTH:
                        switch (grid[px+1][py]) {
                            case '#': break;
                            case '*': px++; count++; grid[px][py] = '.'; break;
                            case '.': px++; break;
                        }
                        break;
                    case WEST:
                        switch (grid[px][py-1]) {
                            case '#': break;
                            case '*': py--; count++; grid[px][py] = '.'; break;
                            case '.': py--; break;
                        }
                        break;
                }
            }
        }
        cout << count << endl;
    }


    return 0;
}