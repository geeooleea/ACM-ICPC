#include <iostream>
#include <algorithm>
using namespace std;
// OCIO: black e white sono invertiti
// fino a 10^7 va bene array globale statico
int arr[100001];

int main() {
    long long t;
    cin >> t;
    long long n,k;
    char c;
    for (long long p=0; p<t; p++) {
        cin >> n;
        long long black = 0, white = 0;
        for (long long i=0; i<n; i++) {
            cin >> k >> c;
            if (c == 'B') {
                black += k;
                arr[i] = k;
            } else {
                white += k;
                arr[i] = -k;
            }
        }
        if (black == 0 || white == 0) {
            cout << black + white << endl;
        } else {
            long long mcd = __gcd(black, white);
            black /= mcd;
            white /= mcd;
            long long count = arr[0] * ((arr[0] > 0) ? white : black);
            long long blocks = 0;
            long long tmp;
            for (long long i=1; i<n; i++) {
                tmp = count + arr[i] * ((arr[i] > 0) ? white : black);
                // cout << count << " " <<  tmp << endl;
                if (tmp * count <= 0 && count != 0 && 
                        tmp % ((arr[i] > 0) ? white : black) == 0) { // solo tmp può essere 0
                    // cout << "splitted" << endl;
                    blocks++;
                }
                count = tmp;
            }
            cout << blocks << endl;
        }
    }

    
    return 0;
}