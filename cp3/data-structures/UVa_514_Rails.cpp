#include <bits/stdc++.h>

using namespace std;
int n;

bool possible(vector<int> &order) {
    stack<int> s;
    int train = 1, i = 0;
    while (train <= n) {
        s.push(train++);
        while (!s.empty() && s.top() == order[i]) {
            s.pop(); i++;
        }
    }
    while (!s.empty() && s.top() == order[i]) {
        s.pop(); i++;
    }
    return s.empty();
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        vector<int> order(n);
        while (cin >> order[0]) {
            if (order[0] == 0) break;
            for (int i=1; i<n; i++) {
                cin >> order[i];
            }
            if (possible(order)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}