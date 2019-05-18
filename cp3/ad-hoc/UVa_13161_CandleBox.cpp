// PROBLEMA 7646

using namespace std;

#include <iostream>

int remove_candles(int d, int r, int t);

int main() {
    int d,r,t;
    while (cin >> d >> r >> t) {
        cout << remove_candles(d,r,t) << endl;
    }
    return 0;
}

int remove_candles(int d, int r, int t) {
    int tot = r + t;
    int r_ex = 0;
    int t_ex = 0;
    int ir = 4;
    int it = 3;
    while (r_ex + t_ex < tot) {
        if(ir >= 4+d-1) {
            t_ex += it;
            it++;
        }
        r_ex += ir;
        ir++;
    }
    return r-r_ex;
}