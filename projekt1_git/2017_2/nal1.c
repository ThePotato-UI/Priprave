#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define TRACE() printf("Reached %s:%d in %s()\n", __FILE__, __LINE__, __func__) // zelo uporabno za ugotavljanje kje je seg fault

char* Mnozi(char* number, int k, int size) {
    char *mnozenNum = malloc(size+1*sizeof(char));
    int prenos = 0;
    int index = size-1;
    for(int i = size-1; i >= 0; i--) {
        int stevka = number[i] -'0'; // char -> int => (char) - '0'
        int zmnozek = stevka * k + prenos;
        if(prenos != 0) prenos = 0;
        while(zmnozek>=10) {
            zmnozek-=10;
            prenos++;
        }
        mnozenNum[index] = zmnozek + '0';
        index--;
        
    }

    return mnozenNum;
}

int main() {
    char *number = malloc(1200*sizeof(char));
    fgets(number, 1200, stdin);
    char *justNumber;
    int Zst;
    for(int i = 0; i < strlen(number); i++) {
        if(number[i] == ' ') {
            char *n = &number[i+1];
            Zst = atoi(n);
            justNumber = strtok(number, " ");
            break;
        }
    }
    int size = strlen(justNumber);
    char *novZmnoz = Mnozi(justNumber, Zst, size);
    printf("%s\n", novZmnoz);

}