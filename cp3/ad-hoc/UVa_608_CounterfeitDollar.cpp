#include <bits/stdc++.h>

using namespace std;

struct weight {
    string heavy,light,real;
};

enum COIN_T { TRUE, HEAVY, LIGHT };

COIN_T type(char c, vector<weight> &w) {
    // WEIGHING CONSISTENCY
    int evenCount = 0, heavyCount = 0, lightCount = 0;

    int n = 0;

    for (weight wi : w) {
        if (wi.real.length() > 0) n++;
        for (char d : wi.real)
            if (d == c) evenCount++;
        for (char d : wi.heavy)
            if (d == c) heavyCount++;
        for (char d : wi.light)
            if (d == c) lightCount++;
    }

    if (heavyCount == 3-n && evenCount == 0) return HEAVY;
    else if (lightCount == 3-n && evenCount == 0) return LIGHT;
    else return TRUE;
}

int main() {

    int test; cin >> test;

    for (int t=0; t<test; t++) {
        vector<weight> w;

        string empty = "";
        
        string left, right, res;
        for (int i=0; i<3; i++) {
            cin >> left >> right >> res;
            if (res.compare("even") == 0) {
                w.push_back({"","",left+right});
                //for (char c : left+right) fake[c-'A'] = false;
            } else if (res.compare("up") == 0) {
                w.push_back({left,right,empty});
            } else if (res.compare("down") == 0) {
                w.push_back({right,left,empty});
            }
        }

        for (int i=0; i<12; i++) {
            switch (type('A'+i,w)) {
                case LIGHT: cout << (char)('A'+i) << " is the counterfeit coin and it is light." << endl; break;
                case HEAVY: cout << (char)('A'+i) << " is the counterfeit coin and it is heavy." << endl; break;
            }
        }
    }

    return 0;
}