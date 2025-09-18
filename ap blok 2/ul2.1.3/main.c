#include <stdio.h>

static int number, res;

int main()
{
    number = 11;
    res = 0;

    printf("Cislo: %d", number);
    asm volatile(
        "mov w0, %w[value]      \n\t"
        "cmp w0, #10            \n\t"
        "blt 1f                 \n\t"
        "add w1, w0, #55        \n\t"
        "b 2f                   \n\t"
    "1:                         \n\t"
        "add w1, w0, #48        \n\t"
    "2:                         \n\t"
        "mov %w[result], w1     \n\t"
        : [result] "=r" (res)
        : [value] "r" (number)
        : "w0", "w1"
    );

    printf("\nASCII Code: %c", res);

    return 0;
}
