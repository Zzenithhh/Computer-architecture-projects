#include <stdio.h>

int main() {
    FILE *input, *output;
    input = fopen("/Users/arikmirnij/Documents/ap blok 2/ul2.3.2/koniec_poviedky.html", "rb");
    output = fopen("/Users/arikmirnij/Documents/ap blok 2/ul2.3.2/decrypt-koniec_poviedky.html", "wb");

    for (int c; (c = fgetc(input)) != EOF; fputc(c ^ 27, output)) {}

    fclose(input), fclose(output);
    return puts("Successfully decrypted"), 0;
}