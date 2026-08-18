#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define TRACE() printf("Reached %s:%d in %s()\n", __FILE__, __LINE__, __func__) // zelo uporabno za ugotavljanje kje je seg fault

int main(int argc, char** argv) {
    FILE *vhod = fopen(argv[1], "r");
    FILE *izhod = fopen(argv[2], "w");
    int currIndex = 1;
    int desIndex = 1;
    int currNum;
    TRACE();
    while(fscanf(vhod, "%d", &currNum) != EOF) {
        printf("%d in index: %d\n", currNum, currIndex);
        if(currIndex == 1)  {
            fprintf(izhod, "%d\n", currNum);
            desIndex += currNum;
        }
        if(currIndex == desIndex) {
            fprintf(izhod, "%d\n", currNum);
            desIndex += currNum;
        }
        currIndex++;
        
    }

    fclose(vhod);
    fclose(izhod);

    return 0;
}