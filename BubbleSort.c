#include <stdio.h>
#include <stdlib.h>

int swaped = 0;

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble(int* arr, int size) {
    
    for(int i = 0; i < size-1; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr, i, i+1);
            swaped = 1;
        }
    }
    if (swaped == 0) {
        return;
    }
    bubble(arr, size-1);
}

void printTab(int* arr, int size) {
    printf("tabela: [");
    for(int i = 0; i < size-1; i++) {
        printf("%d, ", arr[i]);
    }

    printf("%d]\n", arr[size-1]);
}

