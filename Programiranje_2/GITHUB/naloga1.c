
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Testni primeri:
 *
 * 01: iz besedila
 * 01--05: ro"cno izdelani
 * 06--10: samodejno izdelani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    FILE *vhod = fopen(argv[1], "r");
    FILE *izhod = fopen(argv[2], "w");

    int *stevila = malloc(100000*sizeof(int)); 
    char line[1000000];
    int i = 0;
    while(fscanf(vhod, "%s", line) != EOF) {
        
        stevila[i] = atoi(line);
        i++;
    }
    int size = i+1;

    long maxVsota = -1000000;
    for(int j = 0; j < size-3; j++) {
        long vmesVsota = (long)stevila[j] + (long)stevila[j+1] + (long)stevila[j+2];
        if(vmesVsota > maxVsota) {
            maxVsota = vmesVsota;
        }
    }

    printf("%ld\n", maxVsota);
    fprintf(izhod, "%ld", maxVsota);

    fclose(vhod);
    fclose(izhod);
    
    return 0;
}
