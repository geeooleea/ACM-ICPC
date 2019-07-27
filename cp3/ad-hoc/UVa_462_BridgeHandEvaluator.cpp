#include <bits/stdc++.h>

using namespace std;

vector<string> hand(13);

int countCard(char card) {
    int count = 0;
    for (string c : hand) {
        if (c[0] == card) count++;
    }
    return count;
}

int countSuit(char suit) {
    int count = 0;
    for (string c : hand) {
        if (c[1] == suit) count++;
    }
    return count;
}

int countLonelyCards(char card, int amount) {
    int count = 0;
    for (int i=0; i<13; i++) {
        if (hand[i][0] == card) {
            int currCount = 0;
            for (int j=0; j<13; j++) {
                if (i!=j && hand[i][1] == hand[j][1]) currCount++;
            }
            if (currCount <= amount) count++;
        }
    }
    return count;
}

bool isStopped(char suit) {
    int hasAce, hasKing, hasQueen, hasOneOther, hasTwoOther;
    hasAce = hasKing = hasQueen = hasOneOther = hasTwoOther = false;
    for (string c : hand) {
        if (c[1] == suit) {
            switch (c[0]) {
                case 'A': hasAce = true; break;
                case 'K': hasKing = true; break;
                case 'Q': hasQueen = true; break;
            }
        }
    }
    return (hasAce || (hasKing && countSuit(suit) > 1) || (hasQueen && countSuit(suit) > 2));
}

int main() {
    while (cin >> hand[0]) {
        for (int i=1; i<13; i++) {
            cin >> hand[i];
        }

        int score = countCard('A')*4 + countCard('K')*3 + countCard('Q')*2 + countCard('J') ;
        score -= (countLonelyCards('K',0) + countLonelyCards('Q',1) + countLonelyCards('J',2));

        if (score >= 16 && isStopped('S') && isStopped('H') && isStopped('D') && isStopped('C')) cout << "BID NO-TRUMP" << endl;
        else {
            score += (countSuit('S') == 2 ? 1 : 0) + (countSuit('H') == 2 ? 1 : 0) + (countSuit('D') == 2 ? 1 : 0) + (countSuit('C') == 2 ? 1 : 0);
            score += (countSuit('S') == 1 ? 2 : 0) + (countSuit('H') == 1 ? 2 : 0) + (countSuit('D') == 1 ? 2 : 0) + (countSuit('C') == 1 ? 2 : 0);
            score += (countSuit('S') == 0 ? 2 : 0) + (countSuit('H') == 0 ? 2 : 0) + (countSuit('D') == 0 ? 2 : 0) + (countSuit('C') == 0 ? 2 : 0);
            if (score >= 14) {
                if (countSuit('S') >= countSuit('H') && countSuit('S') >= countSuit('D') && countSuit('S') >= countSuit('C')) cout << "BID S\n";
                else if (countSuit('H') >= countSuit('S') && countSuit('H') >= countSuit('D') && countSuit('H') >= countSuit('C')) cout << "BID H\n";
                else if (countSuit('D') >= countSuit('S') && countSuit('D') >= countSuit('H') && countSuit('D') >= countSuit('C')) cout << "BID D\n";
                else if (countSuit('C') >= countSuit('S') && countSuit('C') >= countSuit('D') && countSuit('C') >= countSuit('H')) cout << "BID C\n";           
            } else {
                cout << "PASS" << endl;
            }
        }
         
    }
    
    
    return 0;
}