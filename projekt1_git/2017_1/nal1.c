#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
    
    char niz[11000];
    fgets(niz, sizeof(niz), stdin); //kopiranje celotne linije vhoda v nek array

    int jeStevilo = 0;
    int index = 0;
    int vsota = 0;
    char stevilo[30];
    int indexSt = 0;
    while(niz[index] != '\n') {
        
        if(niz[index] >= '0' && niz[index] <= '9') {
            stevilo[indexSt] = niz[index];
            jeStevilo = 1;
            indexSt++;
            
        }
        else {
            if(jeStevilo) {
                indexSt = 0;
                jeStevilo = 0;
                int st = atoi(stevilo);
                printf("st: %d\n", st);
                vsota += st;
                memset(stevilo, 0, strlen(stevilo)); //resetiranje zacasnega arraya v zanki

            }
        }
        index++;
    }
    if(jeStevilo) {
        int st = atoi(stevilo);
        vsota += st;
    }

    printf("vsota: %d\n", vsota);
}