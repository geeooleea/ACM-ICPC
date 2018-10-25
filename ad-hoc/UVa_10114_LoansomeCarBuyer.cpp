#include <iostream>

using namespace std;
double deprecation[101] = {0};
int main() {
    int months, n_deprecation;
    double payment, worth;
    int i=0;
    while (cin >> months >> payment >> worth >> n_deprecation) {
        // cout << "case " << i++ << endl;
        int tmp;
        double owe = worth;
        for (int i = 0; i < n_deprecation; i++) {
            cin >> tmp;
            cin >> deprecation[tmp];
            // filling not specified months
            for (int j=tmp+1; j<101; j++) {
                deprecation[j] = deprecation[tmp];
            }
        }
        /*
        for (int i=0; i<101; i++) {
            cout << deprecation[i] << " ";
        }
        cout << endl;
        */
        // worth lost after driving off the lot
        worth = worth - (worth * deprecation[0]);
        for (int i = 1; i <= months; i++) {
            owe -= payment;
            cout << worth << " " << owe << endl;
            if (owe < worth) {
                // cout << owe << " " << worth << endl;
                cout << i << " month" << (i > 1 ? "s" : "") << endl;
                break;
            }
            worth -= (worth * deprecation[i]);
        }
    }
    return 0;
}