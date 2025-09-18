#include <stdio.h>
#include <stdlib.h>

unsigned char convert_iso8859_2_to_cp1250(unsigned char ch) {
    switch (ch) {
        case 0xA1: return 0xA5; // Ą
        case 0xA5: return 0xBC;
        case 0xA6: return 0x8C; // Ś
        case 0xA9: return 0x8A;
        case 0xAB: return 0x8D;
        case 0xAC: return 0x8F;
        case 0xAE: return 0x8E;
        case 0xB1: return 0xB9;
        case 0xB5: return 0xBE;
        case 0xB6: return 0x9C;
        case 0xB7: return 0xA1;
        case 0xB9: return 0x9A;
        case 0xBB: return 0x9D;
        case 0xBC: return 0x9F;
        case 0xBE: return 0x9E;

        default: return ch;
    }
}

void convert_file(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "rb");
    FILE *fout = fopen(output_file, "wb");
    unsigned char ch;
    while (fread(&ch, 1, 1, fin) == 1) {
        unsigned char converted = convert_iso8859_2_to_cp1250(ch);
        fwrite(&converted, 1, 1, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main() {
    const char *input_file = "/Users/arikmirnij/Documents/ap blok 2/ul2.3.1/poviedka.html";
    const char *output_file = "/Users/arikmirnij/Documents/ap blok 2/ul2.3.1/poviedkaWIN1250.html";

    convert_file(input_file, output_file);

    return 0;
}
