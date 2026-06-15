
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Testni primeri:
 *
 * 01: iz besedila
 * 02: velikost slike je 1 x 1
 * 03: velikost slike je 1 x 2
 * 04--10: samodejno izdelani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    FILE *vhod = fopen(argv[1], "rb");
    FILE *izhod = fopen(argv[2], "wb");

    char line[3];
    int sirina, dolzina, maxVal;
    fscanf(vhod, "%2s", line);
    fscanf(vhod, "%d %d", &sirina, &dolzina);
    fscanf(vhod, "%d", &maxVal);

    fgetc(vhod);
    unsigned char rgb[3];
    while(fread(rgb, 1, 3, vhod) == 3) {
        printf("%d %d %d\n", rgb[0], rgb[1], rgb[2]);
    }
    return 0;
}
