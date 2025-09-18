#include <stdio.h>

int main() {
    char text[] = "Ul2.2 By Yaroslav Myrka";
    printf("%s\n", text);

    char *ptr = text;
    printf("%p\n", ptr);

    ptr++;
    *ptr = 'X';
    printf("%s\n", text);

    //ptr = ptr + 1000000;
    // *ptr = 'Y';

    int numbers[] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    int *int_ptr = numbers;
    printf("%p\n", int_ptr);

    int_ptr++;
    *int_ptr = 99;

    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}
