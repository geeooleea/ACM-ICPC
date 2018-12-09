#include <iostream>
#include <algorithm>

using namespace std;

pair<string,string> lines[101];
string sorted[101];
int main () {
    int t;
    bool first = true;
    cin >> t;
    getline(cin,lines[0].first); // read last \n char
    getline(cin,lines[0].first); // read empty line after t
    for (int test = 0; test < t; test++) {
        int n=0;    // number of lines read
        getline(cin,lines[n].first); // read first line of input
        lines[0].second="";
        lines[0].second.append(lines[0].first);
        sort(lines[0].second.begin(),lines[0].second.end());
        lines[n].second.erase(
            remove(lines[n].second.begin(), lines[n].second.end(), ' '), lines[n].second.end());
        n++;
        while (lines[n-1].first.size() > 0) {
            getline(cin,lines[n].first);
            lines[n].second = "";
            lines[n].second.append(lines[n].first);
            sort(lines[n].second.begin(), lines[n].second.end());
            lines[n].second.erase(
                remove(lines[n].second.begin(), lines[n].second.end(), ' '), lines[n].second.end());
            n++;
        }
        n--;

        sort(lines,lines+n);
        /*
        for (int i=0; i<n; i++) {
            cerr << lines[i].first << " -- " << lines[i].second << endl;
        }
        */
        if (!first) {
            cout << endl;
        }
        first = false;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                // cout << sorted[i] << " ---- " << sorted[j] << endl;
                if (lines[i].second.compare(lines[j].second) == 0) {
                    cout << lines[i].first << " = " << lines[j].first << endl;
                }
            }
        }
    }

    return 0;
}