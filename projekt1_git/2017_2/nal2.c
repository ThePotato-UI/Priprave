#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define TRACE() printf("Reached %s:%d in %s()\n", __FILE__, __LINE__, __func__) // zelo uporabno za ugotavljanje kje je seg fault

long Pretvorba(int** Tabela) {
    char *Bstevilo = malloc(64*sizeof(char));
    int x = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(Tabela[i][j] == 0) Bstevilo[x] = '0';
            else Bstevilo[x] = '1';

            x++;
        }
    }
    printf("64-bitno st. : %s\n", Bstevilo);
    long rezultat = 0;
    for(int i = 0; i < x+1; i++) {
        if(Bstevilo[i] == '1') {
            rezultat += (long)pow(2, (double)(63-i));
        }
    }

    return rezultat;
}

int** Tabela() {
    int** tabela8x8 = malloc(8*sizeof(int*));
    for(int i = 0; i < 8; i++) {
        tabela8x8[i] = malloc(8*sizeof(int));
        for(int j = 0; j < 8; j++) {
            tabela8x8[i][j] = 0;
        }
    }

    return tabela8x8;
}

void premikDesno(int** tabela, int* currPos) {
    if(currPos[1] + 1 <= 7) {
        currPos[1]++;
        tabela[currPos[0]][currPos[1]] = 1;
    } 
}
void premikLevo(int** tabela, int* currPos) {
    if(currPos[1] - 1 >= 0) {
        currPos[1]--;
        tabela[currPos[0]][currPos[1]] = 1;        
    } 
}
void premikDol(int** tabela, int* currPos) {
    if(currPos[0] + 1 <= 7) {
        currPos[0]++;
        tabela[currPos[0]][currPos[1]] = 1;
    } 
}
void premikGor(int** tabela, int* currPos) {
    if(currPos[0] - 1 >= 0) {
        currPos[0]--;
        tabela[currPos[0]][currPos[1]] = 1;
    } 
    
}
int main() {
    int n;
    scanf("%d", &n);
    int ukazi[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &ukazi[i]);
    }
    TRACE();
    int **tabela8x8 = Tabela();
    TRACE();
    
    TRACE();
    int currPos[] = {7, 7};
    tabela8x8[7][7] = 1;

    for(int i = 0; i < n; i++) {
        switch (ukazi[i])
        {
        case 0:
            premikLevo(tabela8x8, currPos);
            break;
        case 1:
            premikGor(tabela8x8, currPos);
            break;
        case 2:
            premikDesno(tabela8x8, currPos);
            break;
        case 3:
            premikDol(tabela8x8, currPos);
            break;
        default:
            break;
        }
        
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%d ", tabela8x8[i][j]);
        }
        printf("\n");
    }
    printf("rez: %ld\n", Pretvorba(tabela8x8));
    return 0;
}