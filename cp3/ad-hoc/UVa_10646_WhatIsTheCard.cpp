#include <bits/stdc++.h>

using namespace std;

string cards[52];

int value(string card) {
    if (card[0] >= '2' && card[0] <= '9') return (card[0] - '0');
    else return 10;
}

int main() {

    int test;

    cin >> test;

    for (int t=1; t<=test; t++) {
        for (int i=0; i<52; i++) {
            cin >> cards[i];
        }

        int top = 51-25, y=0;
        int x;

        for (int i=0; i<3; i++) {
            x = value(cards[top]);
            //cout << "removing " << cards[top] << " and " << 10-x << " other cards" << endl;
            y += x;
            top -= (10-x+1);
        }
        //cout << "top = " << top << ", y = " << y << endl;
        cout << "Case " << t << ": ";
        if (y < top) cout << cards[y-1];
        else cout << cards[51-25+(y-top-1)];
        cout << endl;

    }


    return 0;
}