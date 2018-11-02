#include <iostream>

using namespace std;

char mirror[26] = { 'A', 0, 0, 0, '3', 0, 0, 'H', 'I', 'L', 0, 'J', 'M', 0, 'O',
     0, 0, 0, '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5' };

char mirror_number[10] = { 0, '1', 'S', 'E', 0, 'Z', 0, 0, '8', 0 };

bool isPalindrome(string s) {
    int n = s.length();
    for (int i=0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) {
            return false;
        }
    }

    return true;
}

bool isMirrored(string s) {
    int n = s.length(); // n odd -> I don't need to check the middle char
    for (int i=0; i < n/2; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (s[n-i-1] != mirror[s[i] - 'A']) {
                // cout << i << " not matching" << endl;
                return false;
            }
        } else {
            if (s[n-i-1] != mirror_number[s[i] - '0']) {
                // cout << i << " not matching" << endl;
                return false;
            }
        }
    }

    if (n%2 != 0 && s[n/2] >= 'A' && s[n/2] <= 'Z' && s[n/2] != mirror[s[n/2]-'A']) {
        // cout << n/2 << " not matching" << endl;
        return false;
    } else if  (n%2 != 0 && s[n/2] >= '0' && s[n/2] <= '9' && s[n/2] != mirror_number[s[n/2]-'0']) {
        //cout << n/2 << " not matching: " << s[n/2]  << " " << mirror[s[n/2]-'0'] << endl;
        return false;
    }
    return true;
}

int main() {
    string word;
    bool mirr,pal;
    while (cin >> word) {
        pal = isPalindrome(word);
        mirr = isMirrored(word);

        if (!pal && !mirr) {
            cout << word << " -- is not a palindrome.\n\n";
        } else if (pal && !mirr) {
            cout << word << " -- is a regular palindrome.\n\n";
        } else if (!pal && mirr) {
            cout << word << " -- is a mirrored string.\n\n";
        } else {
            cout << word << " -- is a mirrored palindrome.\n\n";
        }
    }

    return 0;
}