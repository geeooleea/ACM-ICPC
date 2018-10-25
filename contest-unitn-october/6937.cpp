#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> gain;

int main() {
    int t;
    cin >> t;
    int a,b,n,k;
    for (int p=0; p<t; p++) {
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            cin >> a >> b;
            gain.push_back(a-b);
        }
        sort(gain.begin(),gain.end());
        cout << ((k >= gain.size()) ? 0 : (gain[gain.size()-k-1])) << endl;
        gain.clear();
    }

    
    return 0;
}