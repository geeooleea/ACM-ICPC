#include <bits/stdc++.h>

using namespace std;

int a,b,c,x,y,z;

bool used[53];

int second() {
    if (a < b && a > c || a > b && a < c) return a;
    if (b < a && b > c || b > a && b < c) return b;
    if (c < b && c > a || c > b && c < a) return c;
}

int next(int n) {
    while (used[n] && n < 54) n++;
    return (n > 52 ? -1 : n);
}

int main() {

    while (cin >> a >> b >> c >> x >> y) {
        for (int i=0; i<53; i++) used[i]=false;
        if (a==0 && x==0) break;
        used[a] = used[b] = used[c] = used[x] = used[y] = true;
        int winX = 0, winY = 0;

        if (x > a) winX++; if (x > b) winX++; if (x > c) winX++;
        if (y > a) winY++; if (y > b) winY++; if (y > c) winY++;

        if (winX == 3 && winY == 3) cout << next(1) << endl; // OK
        else if (winX == 2 && winY == 3 || winX == 3 && winY == 2) cout << next(second()+1) << endl;
        else if (winX == 2 && winY == 2) cout << next(second()+1) << endl; // OK
        else if (winX == 1 && winY == 3 || winX == 3 && winY == 1) cout << next(max(a,max(b,c))+1) << endl;
        else if (winX == 0 && winY == 3 || winX == 3 && winY == 0) cout << next(max(a,max(b,c))+1) << endl;
        else cout << -1 << endl;
    }

    return 0;
}