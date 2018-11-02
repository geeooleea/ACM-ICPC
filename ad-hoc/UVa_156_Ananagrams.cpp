#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
string word[1001];
string lowered[1001];
bool found[1001];

string to_lowercase(string s) {
    string ret;
    for (int i=0; i<s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ret += s[i] + 'a' - 'A';
        } else {
            ret += s[i];
        }
    }

    // cout << ret << endl;

    return ret;
}

int main() {
    int n=0;
    while (cin >> word[n]) {
        n++;
        if (word[n].length() == 1) {
            found[n] = true;
        } else {
            found[n] = false;
        }
    }
    n--; // remove #

    sort(word, word + n);
    
    for (int i=0; i<n; i++) {
        lowered[i] = to_lowercase(word[i]);
        sort(lowered[i].begin(), lowered[i].end());
    }

    for (int i=0; i<n; i++) {
        if (!found[i]) {
            for (int j=i+1; j < n; j++) {
                if (word[i].length() == word[j].length()) {
                    // cout << "considering " << lowered[i] << " and " << lowered[j] << endl;
                    if (lowered[i].compare(lowered[j]) == 0) {
                        // cout << word[i] << " and " << word[j] << " are anagrams\n";
                        found[i] = true;
                        found[j] = true;
                    }
                }
            }
        }
        if (!found[i]) {
            cout << word[i] << endl;
        }
    }
    return 0;
}