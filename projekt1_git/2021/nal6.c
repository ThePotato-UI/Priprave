#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define TRACE() printf("Reached %s:%d in %s()\n", __FILE__, __LINE__, __func__) // zelo uporabno za ugotavljanje kje je seg fault

typedef struct _Oseba {
    int indeks;
    struct _Oseba* prviOtrok;
    struct _Oseba* drugiOtrok; 
} Oseba;

int findS(int* tabela, int n, int iskan) {
    for(int i = 0; i < n; i++) {
        if(tabela[i] == iskan) {
            tabela[i] = -2;
            return i;
        }
    }
    return -10;
}

Oseba* zgradi(int n, int* starsi) {
    int Koren = findS(starsi, n, -1);
    int k = n-1;
    Oseba koren;
    koren.indeks = Koren;
    koren.prviOtrok = NULL;
    koren.drugiOtrok = NULL;
    Oseba* tren = &koren;
    while(k > 0) {
        int prvi = findS(starsi, n, Koren);
        if(prvi != -10) {
            int drugi = findS(starsi, n, Koren);
            if(drugi != -10) {
                
            }
        }
        



    }
}

 