using namespace std;

#include <iostream>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stdio.h>  

int value[128];

int main()
{
    int n,k,m;
    char tmp;
    cin >> n;
    for (int test = 0; test < n; test++) {
        for (int i=0; i<128; i++) {
            value[i] = 0;
        }
        cin >> k;
        for (int i=0; i<k; i++) {
            cin >> tmp;
            cin >> value[tmp];
        }
        /*
        for (int i=0; i<128; i++) {
            cout << (char)i << " " << value[i] << endl;
        }
        cout << endl;
        */
        cin >> m;
        int lines = 0;
        long long money = 0;
        while (lines <= m && tmp != EOF) {
            tmp = getchar();
            if (0 <= tmp && tmp <= 127) {
                if (tmp == '\n') lines++;
                money += value[tmp];
            }
        }
        cout << fixed << setprecision(2) << (double)money/100 << "$" << endl;
    }

    return 0;
}