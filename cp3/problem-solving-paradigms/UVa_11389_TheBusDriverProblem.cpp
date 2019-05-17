#include <iostream>
#include <algorithm>

using namespace std;

int morning[101];
int evening[101];

int main() {
    int n,d,r;
    cin >> n >> d >> r;
    while (n != 0 || d != 0 || r != 0) {

        for (int i=0; i<n; i++) {
            cin >> morning[i];
        }
        for (int i=0; i<n; i++) {
            cin >> evening[i];
        }
        sort(morning,morning+n);
        sort(evening,evening+n);
        long long wage = 0;
        int curr;
        for (int i=0; i<n; i++) {
            curr = (morning[i]+evening[n-i-1])-d;
            wage += ( curr > 0 ? curr : 0 );
        }
        cout << wage*r << endl;
        cin >> n >> d >> r;
    }
    
    return 0;
}