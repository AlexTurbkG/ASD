#include <stdio.h>

void change(char *str) {
    if (*str == '\0') {
        return;
    }
    if (*str == '.') {
        *str = '+';
    }
    change(str + 1);
}

int main() {
    char str[] = "ac....";
    change(str);
    printf("%s", str);
    return 0;
}
