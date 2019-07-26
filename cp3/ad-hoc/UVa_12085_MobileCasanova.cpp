#include <bits/stdc++.h>

using namespace std;

void printHyphen(string first, string prev) {
    int j;
    for (j=0; j<first.length(); j++) {
        if (first[j] != prev[j]) break; // Where difference starts
    }
    cout << "-" << prev.substr(j,prev.length()) << endl;
}

bool isNext(string s1, string s2) {
    return (stoi(s1,nullptr,10)+1 == stoi(s2,nullptr,10));
}

int main() {
    int n,t=0;

    while (cin >> n && n != 0) {
        string curr,prev="-1",first="-1";
        cout << "Case " << ++t << ":\n";
        for (int i=0; i<n; i++) {
            cin >> curr;
            //cout << prev << " " << curr << endl;
            if (isNext(prev,curr)) {
                //cout << "Continues sequence" << endl;
                prev = curr;
                if (i == n-1) {
                    printHyphen(first,prev);
                    cout << endl;
                }
            } else {
                //cout << "Breaks sequence" << endl;
                if (prev.compare(first) != 0) { // Need to print with hyphen
                    printHyphen(first,prev);
                } else if (first.compare("-1") != 0) { // Single number line
                    cout << endl;
                }
                first = curr;
                prev = curr;
                cout << curr;
                if (i == n-1) cout << "\n\n";
            }
        }
    }

    return 0;
}