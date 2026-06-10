#include <stdio.h>
#include <stdlib.h>

int bineryS(int* arr, int size, int i) {
    int low = 0;
    int high = size-1;
    while(low <= high) {
        int mid = low+(high-low)/2;
        if(arr[mid] == i) {
            return mid;
        }

        if(i < arr[mid]) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
}

