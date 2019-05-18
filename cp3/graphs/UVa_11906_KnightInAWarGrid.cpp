#include <iostream>
#include <set>
#include <utility>

using namespace std;

char field[101][101];

bool visited[101][101];

int test,r,c,m,n;

// Set ensures no duplicates in moves (when n==m || n==0 || m==0)
set<pair<int,int> > getMoves(int x, int y) {
    set<pair<int,int>> res;
    if (x-m >= 0 && y-n >= 0 && field[x-m][y-n] != 'w') {
        res.emplace(make_pair(x-m,y-n));
    }
    if (x+m < r && y-n >= 0 && field[x+m][y-n] != 'w') {
        res.emplace(make_pair(x+m,y-n));
    }
    if (x+m < r && y+n < c && field[x+m][y+n] != 'w') {
        res.emplace(make_pair(x+m,y+n));
    }
    if (x-n >= 0 && y+m < c && field[x-n][y+m] != 'w') {
        res.emplace(make_pair(x-n,y+m));
    }
    if (x-n >= 0 && y-m >= 0 && field[x-n][y-m] != 'w') {
        res.emplace(make_pair(x-n,y-m));
    }
    if (x+n < r && y+m < c && field[x+n][y+m] != 'w') {
        res.emplace(make_pair(x+n,y+m));
    }
    if (x+n < r && y-m >= 0 && field[x+n][y-m] != 'w') {
        res.emplace(make_pair(x+n,y-m));
    }
    if (x-m >= 0 && y+n < c && field[x-m][y+n] != 'w') {
        res.emplace(make_pair(x-m,y+n));
    }
    return res;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    int count = 0;
    set<pair<int,int> > moves = getMoves(x,y);
    for (pair<int,int> coord : moves) {
        count++;
        if (!visited[coord.first][coord.second]) dfs(coord.first, coord.second);
    }

    if (count % 2 == 0) field[x][y] = 'e';
    else field[x][y] = 'o';
}

int main() {
    cin >> test;
    for (int t=0; t<test; t++) {
        cin >> r >> c >> m >> n;
        // Initialize field
        for (int i=0; i<r; i++) 
            for (int j=0; j<c; j++) {
                field[i][j] = '\0';
                visited[i][j] = false;
        }

        int w,x,y;
        cin >> w;
        for (int i=0; i<w; i++) {
            cin >> x >> y;
            field[x][y] = 'w';
        }

        dfs(0,0);

        int even = 0, odd = 0;

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (field[i][j] == 'o') odd++;
                else if (field[i][j] == 'e') even++;
            } 
        }

        cout << "Case " << t+1 << ": " << even << " " << odd << endl;
    }

    return 0;
}