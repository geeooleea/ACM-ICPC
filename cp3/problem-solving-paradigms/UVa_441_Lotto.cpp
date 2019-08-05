#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int k;
    bool first = true;

    while (cin >> k) {
        if (k==0) break;
        if (!first) { cout << endl; } first = false;
        vector<int> num(k);

        sort(num.begin(),num.end());
        for (int i=0; i<k; i++) cin >> num[i];

        for (int i=0; i<k; i++) {
            for (int j=i+1; j<k; j++) {
                for (int l=j+1; l<k; l++) {
                    for (int m=l+1; m<k; m++) {
                        for (int n=m+1; n<k; n++) {
                            for (int o=n+1; o<k; o++) {
                                cout << num[i] << " " << num[j] << " "  << num[l] << " " << num[m] << " " << num[n] << " " << num[o] << endl;
                            }
                        }
                    }
                }
            }
        }
    }


    return 0;
}