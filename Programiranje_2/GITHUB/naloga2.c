#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE *vhodS = fopen(argv[1], "rb");
    FILE *izhodS = fopen(argv[2], "wb");

    char p[3];
    int w, h, maxV;

    fscanf(vhodS, "%s", p);
    fscanf(vhodS, "%d %d", &w, &h);
    fscanf(vhodS, "%d", &maxV);

    int n = w * h;
    fprintf(izhodS, "%s\n%d %d\n%d\n", p, w, h, maxV);

    char line[8];
    int i = 0;
    char (*rdece)[8] = malloc(n*sizeof(*rdece));
    int r = 0;
    char (*zelene)[8] = malloc(n*sizeof(*zelene));
    int g = 0;
    char (*modre)[8] = malloc(n*sizeof(*modre));
    int b = 0;
    while(fscanf(vhodS, "%s", line) != EOF) {
        
        switch (i)
        {
        case 0:
            
            strcpy(rdece[r], line);
            i++;
            r++;
            break;
        case 1:
            
            strcpy(zelene[g], line);
            i++;
            g++;
            break;
        case 2:
            
            strcpy(modre[b], line);
            i = 0;
            b++;
            break;
        default:
            break;
        }
    }

    int index = 0;
    for(int j = 0; j < 3; j++) {
        for(int k = 0; k < r; k++) {
            if(k == r-1 && j == 2) {
                fprintf(izhodS, "%s", modre[k]);
                goto end;
            }
            switch (j)
            {
            case 0:
                fprintf(izhodS, "%s ", rdece[k]);
                break;
            case 1:
                fprintf(izhodS, "%s ", zelene[k]);
                break;
            case 2:
                fprintf(izhodS, "%s ", modre[k]);
                break;
            default:
                break;
            }
        }
    }
    end:

    fclose(vhodS);
    fclose(izhodS);
    return 0;
    

}