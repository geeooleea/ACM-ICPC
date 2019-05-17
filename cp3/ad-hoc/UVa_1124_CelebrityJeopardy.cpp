#include <stdio.h>
#include <cstring>

using namespace std;

int main() {
    char s;
    bool open = true;
    scanf("%c",&s);
    do {
        printf("%c", s);
    } while (scanf("%c",&s) != EOF);
    return 0;
}