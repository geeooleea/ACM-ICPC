#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    int n = s.length();
    for (int i=0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) {
            return false;
        }
    }

    return true;
}

string fix(string s) {
    string ret;
    int n = s.length();
    for (int i=0; i<n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ret += s[i] + 'a' - 'A'; // lower case
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            ret += s[i];
        }
    }
    return ret;
}

int main() {
    string tmp;
    getline(cin,tmp);
    while (tmp.compare("DONE") != 0) {
        
        if (isPalindrome(fix(tmp))) {
            cout << "You won't be eaten!\n";
        } else {
            cout << "Uh oh..\n";
        }
        getline(cin,tmp);
    } 

    return 0;
}