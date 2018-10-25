using namespace std;

#include <iostream>
#include <cmath>

int main()
{
    double H,U,D,F;
    cin >> H >> U >> D >> F;
    while (H != 0) {
        double loss = U * F / 100;
        double curr_h = 0;
        int day_count = 0;
        bool won = false;
        while (curr_h <= H && curr_h >= 0) {
            day_count++;
            curr_h += U;
            if (curr_h > H) break;
            curr_h -= D;
            // U = min(0.0,U-loss);
            U -= loss;
            if (U < 0) { U = 0.0; }
        }
        if (curr_h >= H) {
            cout << "success on day " << day_count << endl;
        } else {
            cout << "failure on day " << day_count << endl;
        }

        cin >> H >> U >> D >> F;
    }
}