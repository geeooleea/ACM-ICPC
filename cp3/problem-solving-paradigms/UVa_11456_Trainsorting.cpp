#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int test,n;
long long car[2001];
long long lisDP[2001];
long long ldsDP[2001];

int longest_increasing(int i, int length, int max_w, int min_w) {
    if (i == n) {
        return length;
    } else {
        if (car[i] > max_w) {
            return max(longest_increasing(i+1,length,max_w,min_w),
                        longest_increasing(i+1,length+1,car[i],min_w));
        } else if (car[i] < min_w) {
            return max(longest_increasing(i+1,length,max_w,min_w),
                        longest_increasing(i+1,length+1,max_w,car[i]));
        }
    }
}

void lis() {
    lisDP[0] = 1;
    for (int i=1; i<n; i++) {
        lisDP[i] = 1;
        for (int j=0; j<i; j++) {
            if (car[i] > car[j] && lisDP[i] < lisDP[j] + 1) {
                lisDP[i] = lisDP[j] +1;
            }
        }
    }
}

void lds() {
    ldsDP[0] = 1;
    for (int i=1; i<n; i++) {
        ldsDP[i] = 1;
        for (int j=0; j<i; j++) {
            if (car[i] < car[j] && ldsDP[i] < ldsDP[j] + 1) {
                ldsDP[i] = ldsDP[j] +1;
            }
        }
    }
}

int main() {
    cin >> test;
    
    for (int t=0; t<test; t++) {
        cin >> n;
        for (int i=n-1; i>=0; i--) {
            cin >> car[i];
        }
        lis(); lds();
        long long longest = 0;
        for (int i=0; i<n; i++)  {
            longest = max(longest, lisDP[i] + ldsDP[i] - 1);
        }
        cout << longest << endl;
    }
    return 0;
}