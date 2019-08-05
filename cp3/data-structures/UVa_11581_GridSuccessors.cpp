using namespace std;

#include <bits/stdc++.h>

int g[5][5];

bool goal = false;

void f() {
    int h[5][5];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            h[i][j] = ( (i-1>=0 ? g[i-1][j] : 0) +
                        (i+1<3 ? g[i+1][j] : 0) +
                        (j-1>=0 ? g[i][j-1] : 0) +
                        (j+1<3 ? g[i][j+1] : 0) ) % 2;
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            g[i][j] = h[i][j];
        }
    }
}

bool isZero() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (g[i][j] > 0) return false;
        }
    }
    return true;
}

int main() {
    int test; cin >> test;
    for (int t=1; t<=test; t++) {
        for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%1d", &g[i][j]);
			}
		}

        int step = -1;

        while (!isZero()) {
            f();
            step++;
        }
        
        cout << step << endl;
    } 

    return 0;
}