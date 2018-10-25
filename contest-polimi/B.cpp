#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> not_in_CS, not_in_CE;
unordered_set<string> CS, CE, CS_ext, CE_ext;
unordered_set<string> found_in_CS, found_in_CE;


int main() {
    int n;
    cin >> n;
    string tmp;
    char c = getchar();
    c = 'a';
    while (c != '\n') {
        c = getchar();
        while (c != ' ' && c != '\n') {
            tmp += c;
            c = getchar();
        }
        CS.emplace(tmp);
        // cout << " CS = " << tmp << endl;
        tmp = "";
    }
    c = 'a';
    while (c != '\n' && c != EOF) {
        c = getchar();
        while (c != ' ' && c != '\n' && c != EOF) {
            tmp += c;
            c = getchar();
        }
        CE.emplace(tmp);
        // cout << "CE = " << tmp << endl;
        tmp = "";
    }

    for (int i = 2; i < n; i++) {
        int CS_counter = 0, CE_counter = 0;
        c = 'a';
        while (c != '\n' && c != EOF) {
            c = getchar();
            while (c != ' ' && c != '\n' && c != EOF) {
                tmp += c;
                c = getchar();
            }
            if (tmp != "") {
                if (CS.count(tmp) && !found_in_CS.count(tmp)) {
                    CS_counter++;
                    found_in_CS.emplace(tmp);
                } else {
                    not_in_CS.emplace(tmp);
                }
                if (CE.count(tmp) && !found_in_CE.count(tmp)) {
                    CE_counter++;
                    found_in_CE.emplace(tmp);
                } else {
                    not_in_CE.emplace(tmp);
                }
            }
            // cout << "#" << tmp << "#" << endl;
            tmp = "";
        }
        // cout << CS_counter << " " << CE_counter << endl;
        // cout << not_in_CE.size() << endl;
        if (CS_counter >= CE_counter && CS_counter > 0) {
            for (string s : not_in_CS)
            {
                CS_ext.emplace(s);
            }
        }
        else if (CS_counter <= CE_counter && CE_counter > 0) {
            for (string s : not_in_CE)
            {
                CE_ext.emplace(s);
            }
        }
        /*
        std::cout << "CS_ext contains:";
        for (unordered_set<string>::iterator it = CS_ext.begin(); it != CS_ext.end(); ++it)
            cout << ' ' << *it;

        std::cout << '\n';

        std::cout << "CE_ext contains:";
        for (unordered_set<string>::iterator it = CE_ext.begin(); it != CE_ext.end(); ++it)
            cout << ' ' << *it;

        std::cout << '\n';
        */
        not_in_CE.clear();
        not_in_CS.clear();
        found_in_CE.clear();
        found_in_CS.clear();
    }

    for (string s : CS) {
        CS_ext.emplace(s);
    }
    for (string s : CE) {
        CE_ext.emplace(s);
    }
    int counter_final = 0;
    for (string s : CS_ext) {
        if (CE_ext.count(s)) {
            counter_final++;
        }
    }

    cout << counter_final << endl;
    return 0;
}