#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define TRACE() printf("Reached %s:%d in %s()\n", __FILE__, __LINE__, __func__) // zelo uporabno za ugotavljanje kje je seg fault

int main() {
    char* stevilo = malloc(1001*sizeof(char));
    fgets(stevilo, 1001, stdin);

    int size = strlen(stevilo) - 1;
    int zacX = (size%3 == 0) ? 2 : size%3;
    printf("--%d in %d\n", zacX, size);
    
    if(size <= 3) {
        printf("%s", stevilo);
        return 0;
    }


    for(int i = 0; i < size; i++) {
        if(zacX > 0) {
            zacX--;
            printf("%c", stevilo[i]);
        }
        else {
            printf(".%c", stevilo[i]);
            zacX = 2;
        }
    }
    printf("\n");
    return 0;
}