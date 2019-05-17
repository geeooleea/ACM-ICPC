#include <iostream>

using namespace std;

int n,k,m;

long long sols[51][51];

long long solve(int units, int bars) {
    if (units == n && bars == k) {
        return 1;
    }
    if (units > n || bars > n) {
        return 0;
    }
    if (sols[units][bars] == -1) {
        sols[units][bars] = 0;
        for(int i = 1; i<=m; i++) {
            if (units + i <= n) {
                sols[units][bars] += solve(units+i,bars+1);
            }
        }
    }
    return sols[units][bars];
}

int main() {
    while (cin >> n >> k >> m) {
        for(int i=0; i<51; i++) {
            for (int j=0; j<51; j++) {
                sols[i][j] = -1;
            }
        }
        sols[n][k] = 1;
        cout << solve(0,0) << endl;
    }

    return 0;
}