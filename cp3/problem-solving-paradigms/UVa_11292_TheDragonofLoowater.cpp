#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int dragon[20001];
int knight[20001];

int main() {
    while (cin >> n >> m) {
        if (n==0 && m==0) break;

        for (int i=0; i<n; i++) {
            cin >> dragon[i];
        }

        for (int i=0; i<m; i++) {
            cin >> knight[i];
        }

        if (n > m) {
            cout << "Loowater is doomed!" << endl;
            continue;
        }

        sort(dragon,dragon+n);
        sort(knight,knight+m);

        long long cash = 0;
        int i,j;
        for (i=0,j=0; i<n && j<m;) {
            if (knight[j] >= dragon[i]) {
                cash += knight[j];
                j++;
                i++;
            } else {
                j++;
            }
        }
        if (i < n) { // not all heads killed
            cout << "Loowater is doomed!" << endl;
        } else {
            cout << cash << endl;
        }
    }
}