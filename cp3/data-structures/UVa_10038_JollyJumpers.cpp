using namespace std;

#include <iostream>
#include <bitset>
#include <cmath>

bitset<3000> set;

int main()
{
    int n,a,b;
    while (cin >> n) {
        cin >> b;
        bool jolly = true;
        set[0] = 1;
        for (int i=1; i<n; i++) {
            cin >> a;
            if ((set[fabs(a-b)] || fabs(a-b) >= n) && jolly) {
                cout << "Not jolly" << endl;
                jolly = false;
            }
            set[fabs(a-b)] = 1;
            b=a;
        }
        if (jolly) {
            cout << "Jolly" << endl;
        }
        set.reset();
    }
}