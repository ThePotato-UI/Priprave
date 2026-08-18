#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define TRACE() printf("Reached %s:%d in %s()\n", __FILE__, __LINE__, __func__) // zelo uporabno za ugotavljanje kje je seg fault
#define N 10 //definiras lahko konstante tako...

char** pretvori(char tabela[][N], int m) {
    char** novaTabela = malloc(m*sizeof(char*));
    for(int i = 0; i < m; i++) {
        novaTabela[i] = malloc((strlen(tabela[i])+1)*sizeof(char));
        strcpy(novaTabela[i], tabela[i]);
    }

    return novaTabela;
}


int main() {

}