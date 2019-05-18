#include <iostream>
#include <vector>

using namespace std;

int L;

vector<double> costs;
vector<string> proposal;
vector<int> requirements_met;

int main() {
    int test_case = 1;
    while (cin >> L) {
        if (L==0) {
            break;
        }
        
        char direction = '+',axis = 'x';
        char dir,ax;
        for (int i=0; i<L-1; i++) {
            cin >> dir >> ax;
            // cout << "reading " << dir << ax <<"\n";
            if (ax == 'y') {
                if (dir == '+') {
                    switch (axis) {
                        case 'x': axis = 'y'; break;
                        case 'y': axis = 'x'; direction = (direction == '+' ? '-' : '+'); break;
                        default: break; // z orientation does not change
                    }
                } else {    // dir = '-'
                    switch (axis) {
                        case 'x': axis = 'y'; direction = (direction == '+' ? '-' : '+'); break;
                        case 'y': axis = 'x'; break;
                        default: break; // z orientation does not change
                    }
                }
            } else if (ax == 'z') {
                if (dir == '+') {
                    switch (axis) {
                        case 'x': axis = 'z'; break;
                        case 'z': axis = 'x'; direction = (direction == '+' ? '-' : '+'); break;
                        default: break; // z orientation does not change
                    }
                } else {    // dir = '-'
                    switch (axis) {
                        case 'x': axis = 'z'; direction = (direction == '+' ? '-' : '+'); break;
                        case 'z': axis = 'x'; break;
                        default: break; // z orientation does not change
                    }
                }
            } else { /* Do nothing if ax is 'o' and dir is 'N' */ }
            // cout << "Round " << i << " " << direction << axis << endl;
        }
        cout << direction << axis << endl;
    }
}