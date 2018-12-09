#include <iostream>
#include <stack>

using namespace std;

int seq[1001];

int main() {
    int n;
    while (cin >> n) {
        if (n==0) break;

        int first;
        cin >> first;
        while (first != 0) {
            stack<int> s;
            seq[0] = first;
            for (int i=1; i<n; i++) {
                cin >> seq[i];
                if (seq[i] == i);
            }
            
            cin >> first;
        }
    }

    return 0;
}