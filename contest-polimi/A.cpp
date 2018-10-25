#include <fstream>
#include <iostream>
#include <bitset>

using namespace std;

bitset<10000> panel;

int main () {
    panel.set();
    int n,h,w,x;

    cin >> n >> h >> w;
    int count = 0;
    int a,b;
    for (int i=0; i<n-1; i+=2) {
        cin >> a >> b;
        count += min(a,w-b);
        count += min(b,w-a);
    }
    if (n%2 != 0) {
        cin >> a;
        count += a;
    }
    cout << count*h << endl;
    /*
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (i%2 != 0) {
            for (int j=0; j<x; j++) {
                panel[(w*(i-1))+j] = 0;
                panel[w*i+j] = 1;
            }
        } else {
            for (int j=0; j<x; j++) {
                panel[(w*(i))-j-1] = 0;
                panel[w*(i-1)-j] = 1;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (!panel[i]) {
            count++;
        }
    }
    */
   
    
    return 0;
}