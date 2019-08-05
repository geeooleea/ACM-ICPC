#include <bits/stdc++.h>

using namespace std;

int prices[10001];

bool find(int x, int n) {
    int left=0, right=n-1, mid;

    while (left <= right) {
        mid = (left + right)/2;
        if (prices[mid] == x) return true;
        else if (prices[mid] > x) right = mid-1;
        else left = mid+1;
    }
    return false;       
}

int main() {

    int n,m;

    while (cin >> n) {
        for (int i=0; i<n; i++) cin >> prices[i];
        cin >> m;

        sort(prices,prices+n);

        int mindiff = INT32_MAX, price;

        for (int i=0; i<n; i++) {
            if (abs(m-2*prices[i]) < mindiff && find(m-prices[i],n)) {
                mindiff = abs(m-2*prices[i]); price = prices[i];
            }
        }

        cout << "Peter should buy books whose prices are " << price << " and " << m-price << "." << endl << endl;
    }

    return 0;
}