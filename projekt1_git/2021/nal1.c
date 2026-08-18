#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define TRACE() printf("Reached %s:%d in %s()\n", __FILE__, __LINE__, __func__) // zelo uporabno za ugotavljanje kje je seg fault

int main(int argc, char* argv[]) {
    FILE *vhod = fopen(argv[1], "rb");

    char* stevilo = malloc(20*sizeof(char));
    fgets(stevilo, 20, vhod);
    
    printf((strlen(stevilo) <= 2) ? "0\n" : "1\n"); // pogoj ? "DA" : "NE";

    return 0;
}