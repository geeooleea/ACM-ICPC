#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// vector<long long> v;
long long v[10001];
int main() {
    long long x;
    int n = 0;
    while (cin >> x) {
        v[n] = x;
        n++;
        if (n % 2 == 1) {
            nth_element(v, v + n/2, v+n);
            cout << v[n/2] << endl;
        } else {
            nth_element(v, v + n/2-1, v+n);
            long long sum = v[n/2-1];
            nth_element(v, v + n/2, v+n);
            sum += v[n/2];
            cout << sum/2 << endl;
        }
    }
    return 0;
}