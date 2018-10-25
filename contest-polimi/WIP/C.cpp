#include <iostream>
#include <algorithm>
using namespace std;

bool reachable[200001] = { false };
int ladders[200001];
int floors[200001];

int main () {
    int n,q;
    cin >> n >> q;
    reachable[0] = true;
    int max = 0, min = 200001;
    for (int i=0; i<n; i++) {
        cin >> ladders[i];
        
        if (ladders[i] > max) {
            max = i;
        }
        if (ladders[i] < min) {
            min = i;
        }
        
        reachable[ladders[i]] = true;
    }
    /*
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (ladders[i] + ladders[j] <= 200000) {
                reachable[ladders[i]+ladders[j]] = true;
            }
        }
    }
    */
    int counter = 0;
    bool found;

    for (int i=0; i<q; i++) {
        cin >> floors[i];
    }

    // sort(ladders,ladders+n);
    // sort(floors, floors+q);
    int index;
    for (int i=0; i<q; i++) {
        found = false;
        // raggiungibile con una sola scala
        if (reachable[floors[i]]) {
            counter++;
        } else {    // raggiungibile con due scale
            for(int j=0; (j<1000) && !found; j++) {
                /*
                if (reachable[floors[i]-ladders[j]]) {  // Nota: ladders[j] è sempre raggingibile
                    counter++;
                    found = true;
                }
                */
                index = min + (rand() % static_cast<int>(max+1 - min + 1));
                if (reachable[floors[i]-ladders[index]]) {
                    counter++;
                    found = true;
                }
            }
        }
    }

    cout << counter << endl;

    return 0;
}