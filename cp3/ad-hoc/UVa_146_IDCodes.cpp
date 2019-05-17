#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char code[51];

int main() {
    cin >> code;
    while (strcmp(code,"#") != 0) {
        if (next_permutation(code,code+strlen(code))) {
            cout << code << endl;
        } else {
            cout << "No Successor\n";
        }
        cin >> code;
    }

    return 0;
}