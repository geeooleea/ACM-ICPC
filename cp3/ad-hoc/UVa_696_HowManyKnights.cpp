#include<iostream>
#include <cmath>

using namespace std;

int a,b;
int ans[500][500] = { 0 };

int setGrid();
int setColumns();
int setRows();
void setAttack(int i, int j);
int countZeroes();

int main() {
    while (cin >> a >> b) {
        if (a==0 && b==0) { break; }
        if (a==2 && b == 2) {
            cout << 4 << " knights may be placed on a " << a << " row " <<
                b << " column board." << endl;
        } else if (a == 1 && b != 0 || b == 1 && a != 0) {
            cout << max(a,b) << " knights may be placed on a " << a << " row " <<
            b << " column board." << endl;
        } else {
        int grid = ceil((a*b)/2.0) 
            + ((a==2 && b%2 == 1) ? 1 : 0)
            + ((b==2 && a%2 == 1) ? 1 : 0)
            + ((a==2 && b%2 == 0 && b%4 != 0) ? 2 : 0)
            + ((b==2 && a%2 == 0 && a%4 != 0) ? 2 : 0);
            cout << grid << " knights may be placed on a " << a << " row " <<
                b << " column board." << endl;
        }
    }

    return 0;
}