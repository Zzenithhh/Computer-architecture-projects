#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* ul9(const char *input) {
    size_t input_len = strlen(input) + 1;

    char *output = malloc(input_len);
    int pos = 0;

    for (int i = 1; i < input_len; i++) {
        int count = 0;
        for (int j = 1; j <= (i+1); j++) {
            if ((i+1) % j == 0) count++;
        }

        if (count <= 2) {
            output[pos] = input[i];
            pos++;
        }
    }


    output[pos] = 0;
    printf("%s", output);

    return output;
}

int main(void) {
    ul9("XLOZGP.R.ACLHCOGAGTER");


    return 0;
}