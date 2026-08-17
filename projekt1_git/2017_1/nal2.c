#include "stdio.h"
#include "stdlib.h"

int jeVBufferju(int* buffer, int zelenaSkatla, int k) {
    for(int i = 0; i < k; i++) {
        if(buffer[i] == zelenaSkatla) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, k, t;
    scanf("%d%d%d", &n, &k, &t);

    int zeleneSkatle[t];
    for(int i = 0;  i < t; i++) {
        scanf("%d", &zeleneSkatle[i]);
    }


    int skatle[n][k];
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            skatle[i][j] = index;
            index++;
        }
    }

    int kolOdsSkatel = 0;

    for(int i = 0; i < t; i++) {
        int buffer[k]; // Uporaba bufferja je lahko zelo dobra!!
        for(int u = 0; u < k; u++) {
            buffer[u] = -1;
        }
        int Bindex = 0;
        for(int j = 0; j < n; j++) {
            if(zeleneSkatle[i] >= j*k && zeleneSkatle[i] <= (j+1)*k-1) {
                int Zind = zeleneSkatle[i] - j*k;
                //printf("Zind -- %d\n", Zind);
                skatle[j][Zind] = -2;
                for(int z = Zind+1; z < k;z++) {
                    if(!jeVBufferju(buffer, skatle[j][z], k) && skatle[j][z] != -2) {
                        buffer[Bindex] = skatle[j][z]; 
                        //printf("buffer num: %d\n", skatle[j][z]);  
                        kolOdsSkatel++;
                        Bindex++;
                    }
                }
            }
        }
    }

    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            //printf("%d ", skatle[i][j]);
        }
        printf("\n");
    }
    */
    printf("%d\n", kolOdsSkatel);
}