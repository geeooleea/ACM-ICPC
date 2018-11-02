#include <iostream>

using namespace std;
double depreciation[101] = { 0 };
int main() {
    int months, n_depreciation;
    double payment, loan;
    int i=0;
    while (cin >> months >> payment >> loan >> n_depreciation) {
        if (months <= 0) { break; }

        int tmp;
        double worth = loan + payment;
        double owe = loan;
        for (int i = 0; i < n_depreciation; i++) {
            cin >> tmp;
            cin >> depreciation[tmp];
            // filling not specified months
            for (int j=tmp+1; j<months+1; j++) {
                depreciation[j] = depreciation[tmp];
            }
        }

        /*
        for (int i=0; i<101; i++) {
            cout << depreciation[i] << " ";
        }
        cout << endl;
        */
        // worth lost after driving off the lot
        worth -= (worth * depreciation[0]);
        
        bool done = false;
        if (worth > loan) {
            cout << "0 months" << endl;
            done = true;
        }
        
        int i=1;
        while (!done && i<=months) {
            owe -= loan / (double)months;
            worth *= (1.0 - depreciation[i]);
            // cout << "month: " << i << " : " << worth << " " << owe << endl;
            if (owe < worth) {
                // cout << owe << " " << loan << endl;
                cout << i << " month" << (i == 1 ? "" : "s") << endl;
                done = true;
            }
            i++;
        }
    }
    return 0;
}