#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int n;
int a[200002];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    double f;
    double min_f = 2;
    for (int i = 1; i <= n; i++)
    {
        f = (double) a[i] / i;
        if (f > 1) {
            min_f = 2;
            break;
        }
        // cout << a[i] << " " << i << endl;
        min_f = min(min_f, f);
        // cout << min_f << endl;
    }

    if (min_f > 1) {
        cout << "impossible" << endl;
    } else {
        cout << fixed << setprecision(7) << min_f << endl;
    }
}