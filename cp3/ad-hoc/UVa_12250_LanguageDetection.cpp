#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int i=0;
    while (cin >> s) {
        if (s.compare("#") == 0) break;
        cout << "Case " << ++i << ": ";
        if (s.compare("HELLO") == 0) cout << "ENGLISH" << endl;
        else if (s.compare("HOLA") == 0) cout << "SPANISH" << endl;
        else if (s.compare("HALLO") == 0) cout << "GERMAN" << endl;
        else if (s.compare("BONJOUR") == 0) cout << "FRENCH" << endl;
        else if (s.compare("CIAO") == 0) cout << "ITALIAN" << endl;
        else if (s.compare("ZDRAVSTVUJTE") == 0) cout << "RUSSIAN" << endl;
        else cout << "UNKNOWN" << endl;
    }
    return 0;
}