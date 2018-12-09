#include <iostream>
#include <cmath>

using namespace std;

void sort_three(int &a, int &b, int &c) {
    int x=a, y=b, z=c;
    a = min(min(x,y),z);
    c = max(max(x,y),z);
    b = x+y+z-a-c;
}

int main() {
    int x,y;
    int a,b,c;

    while (cin >> a >> b >> c >> x >> y) {
        if (a == 0 && b == 0 && c == 0 && x == 0 && y == 0) break;
        int l = -1;
        sort_three(a,b,c);
    }

    return 0;
}