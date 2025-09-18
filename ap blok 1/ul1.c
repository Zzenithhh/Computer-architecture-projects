#include <stdio.h>

void bin(int a) {
    int bin[32];
    int i = 0;

    while (a != 0) {
        bin[i] = a % 2;
        a = a / 2;
        ++i;
    }

    --i;

    for (i; i >= 0; --i) {
        printf("%d",bin[i]);
    }
    printf("\n");
}

int main(void) {
    uloha4();
}