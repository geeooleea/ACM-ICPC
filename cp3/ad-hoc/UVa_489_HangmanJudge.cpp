#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<char> tried; // avoid duplicate wrong guesses

int main() {
    int round_n;
    string word;
    string guess;
    int lives;
    cin >> round_n;
    while (round_n != -1) {
        cout << "Round " << round_n << endl;
        cin >> word >> guess;
        lives = 7;
        // cout << guess << endl;
        for (int i=0; i<guess.length() && lives > 0 && !word.empty(); i++) {
            if (!tried.count(guess[i])) {
                if (lives > 0) {
                    tried.emplace(guess[i]);
                    int len_i = word.length();
                    for (int j=0; j<word.length(); j++) {
                        if (word[j] == guess[i]) {
                            word.erase(word.begin()+j);
                            j--;
                        }
                    }
                    if (word.length() == len_i) { // guess is not present in string
                        lives--;
                    }
                }
            }
        }

        if (lives > 0) {
            // cout << word.empty() << endl;
            if (word.empty()) {
                cout << "You win.\n";
            } else {
                cout << "You chickened out.\n";
            }
        } else {
            cout << "You lose.\n";
        }
        cin >> round_n;
        tried.clear();
    }

    return 0;
}