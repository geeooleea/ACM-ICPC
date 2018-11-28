#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int n,m;

char crypt[102];
char text[102];
char key[132];
char read[32];

int main()
{
    cin >> n >> m;
    cin >> read >> crypt;
    // cout << read << " " <<  crypt << endl;
    text[m] = '\0';
    for (int i=0; i < n; i++) {
        text[m+i-n] = read[i];
    }
    
    for (int i=m-1; i>=n; i--) {
        text[i-n] = 'a' + ((crypt[i] + 26 - text[i]) % 26);
        /*
        if (text[i-n] > 'z') {
            cout << text[i-n] << endl;
            text[i-n] -= 26;
            cout << text[i-n] << endl;
        }
        */
        // cout << crypt[i] << " " << text[i] << " "  << text[i-n] <<  endl;
    }
    cout << text << endl;
    return 0;
}