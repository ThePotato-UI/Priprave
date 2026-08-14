
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -Dtest testXY.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 *
 * 01: iz besedila
 * 01--05: ro"cno izdelani
 * 06--14: samodejno izdelani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* prevezi(Vozlisce* zacetek) {
    bool jeZaceten = true;

    if(zacetek == NULL) return NULL;
    if(zacetek->nasl == NULL) return zacetek;
    Vozlisce* tren = zacetek;
    Vozlisce* prev = NULL;
    while(tren->nasl != NULL && tren != NULL) {
        
        Vozlisce* naprej = tren->nasl;
        if(jeZaceten) {
            zacetek = naprej;
            jeZaceten = false;
        }
        Vozlisce* vmes = naprej->nasl;

        naprej->nasl = tren;
        tren->nasl = vmes;

        if(prev == NULL) {
            prev = tren;
        }
        else {
            prev->nasl = naprej;
            prev = tren;
        }

        tren = tren->nasl;
    }

    return zacetek;
}

#ifndef test

int main() {
    return 0;
}

#endif
