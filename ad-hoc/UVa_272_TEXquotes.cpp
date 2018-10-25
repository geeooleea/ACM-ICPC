#include <stdio.h>
#include <cstring>

using namespace std;

int main() {
    char s;
    bool open = true;
    scanf("%c",&s);
    do {
        if (s == '"') {
            if (open) {
                printf("%s", "``");
            } else {
                printf("%s", "''");
            }
            open = !open;
        } else {
            printf("%c", s);
        }
    } while (scanf("%c",&s) != EOF);
    return 0;
}