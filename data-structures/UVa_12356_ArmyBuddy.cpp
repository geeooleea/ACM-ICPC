using namespace std;

#include <iostream>

int left_buddy[100002];
int right_buddy[100002];
int main() {
    int S,B;
    while (cin >> S >> B) {
        if (S == 0 && B == 0) {
            break;
        }
        left_buddy[1] = 0;
        right_buddy[1] = 2;
        right_buddy[S] = 0;
        left_buddy[S] = S-1;
        right_buddy[0] = 0;
        left_buddy[0] = 0;

        for (int i=2; i<S; i++) {
            left_buddy[i] = i-1;
            right_buddy[i] = i+1;
        }

        int a,b;
        for (int i=0; i<B; i++) {
            cin >> a >> b;
            left_buddy[right_buddy[b]] = left_buddy[a];
            right_buddy[left_buddy[a]] = right_buddy[b];
            
            if (left_buddy[a] == 0) {
                cout << "* ";
            } else {
                cout << left_buddy[a] << " ";
            }
            if (right_buddy[b] == 0) {
                cout << "*" << endl;
            } else {
                cout << right_buddy[b] << endl;
            }
        }
        cout << "-" << endl;
    }
    
    return 0;
}