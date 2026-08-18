#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define TRACE() printf("Reached %s:%d in %s()\n", __FILE__, __LINE__, __func__) // zelo uporabno za ugotavljanje kje je seg fault

typedef struct _Vozlisce {
    struct _Vozlisce* n;
} Vozlisce;


Vozlisce* sticisce(Vozlisce* a, Vozlisce* b), {
    Vozlisce* trenA = a;
    Vozlisce* trenB = b;
    while(trenA->n != NULL) {
        while(trenB->n != NULL) {
            if(trenB == trenA) return trenA;
            tranB = trenB->n;
        }
        trenB = b;
        trenA = trenA->n;
    }
}
