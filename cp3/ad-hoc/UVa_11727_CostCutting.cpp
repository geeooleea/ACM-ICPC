#include <stdio.h>

using namespace std;

int main() {
    int t;
    scanf("%i",&t);
    int a,b,c;
    for (int ciao = 1; ciao <= t; ciao++) {
        scanf("%d %d %d", &a, &b, &c);
        if ((a <= b && a >= c) || (a >= b && a <= c)) {
            printf("Case %d: %d\n", ciao, a);
        } else if ((b <= a && b >= c) || (b >= a && b <= c)) {
            printf("Case %d: %d\n", ciao, b);
        } else if ((c <= a && c >= b) || (c >= a && c <= b)) {
            printf("Case %d: %d\n", ciao, c);
        }
    }
    
    return 0;
}