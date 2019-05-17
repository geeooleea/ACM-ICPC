#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int hh,mm;
    char colon;
    while (cin >> hh >> colon >> mm) {
        if (hh==0 && mm==0) break;
        double deg_hh = 360.0*(hh/12.0) + 30.0*mm/60.0;
        double deg_mm = 360.0*(mm/60.0);
        // cout << "-------------------------------\n" << deg_hh << " " << deg_mm << endl;
        double diff;
        if (deg_hh > deg_mm) {
            diff = deg_hh - deg_mm;
        } else {
            diff = deg_mm - deg_hh;
        }
        // cout << diff << endl;
        cout << fixed << setprecision(3) << min(360.0-diff, diff) << endl;
    }
    return 0;
}