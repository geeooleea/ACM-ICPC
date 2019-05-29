#include <bits/stdc++.h>

using namespace std;

int main() {
    int king, queen, rooks, bish, kni, pawn;
    cin >> king >> queen >> rooks >> bish >> kni >> pawn;
    cout << 1-king << " " << 1-queen << " " << 2-rooks << " " << 2-bish << " " << 2-kni << " " << 8-pawn << endl;

    return 0;
}