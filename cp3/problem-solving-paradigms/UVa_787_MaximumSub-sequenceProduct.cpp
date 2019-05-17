// Find longest subsequence with even number of negative numbers
#include <bits/stdc++.h>

using namespace std;

int n=1;

int main() {
    int arr[101];
    while (cin >> arr[0]) {
        n=1;
        while (arr[n-1] != -999999) cin >> arr[n++];
        n--;
        
        int prod = 1, maxv = -999999;
        for (int l=1; l<=n; l++) { // Iterate over all possible lengths of subsequence 
            for (int i=0; i+l<n; i++) { // Starting position of the sequence
                prod = 1;
                for (int j=0; j<l; j++) {
                    prod *= arr[i+j];
                }
                cout << maxv << " " << prod << endl;
                maxv = max(maxv,prod);
            }
        }
        cout << maxv << endl;
    }
    
    return 0;
}