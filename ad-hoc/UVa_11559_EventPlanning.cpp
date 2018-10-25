#include <iostream>

using namespace std;

int available[18][13];
int price[18];
int main() {
    int participants,budget, H, W;
    while (cin >> participants >> budget >> H >> W) {
        for (int i=0; i < H; i++) {
            cin >> price[i];
            for (int j=0; j<W; j++) {
                cin >> available[i][j];
            }
        }

        int min = budget + 1;
        for (int i=0; i<H; i++) {
            if (price[i] * participants <= budget) {
                for (int j=0; j<W; j++) {
                    if (available[i][j] >= participants && price[i] * participants < min) {
                        min = price[i] * participants;
                    }
                }
            }
        }
        if (min == budget+1) {
            cout << "stay home" << endl;
        } else {
            cout << min << endl;
        }
    }
    return 0;
}