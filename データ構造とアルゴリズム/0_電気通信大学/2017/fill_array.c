// fill_array.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fill_array.h"

void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void fill_array(int X[], int size) {
    int predefined[] = {15, 7, 14, 3, 6, 10, 13, 1, 2, 4, 5, 8, 9, 11, 12};

    for (int i = 1; i <= 15; i++) {
        X[i] = predefined[i - 1];
    }

    int arr[size - 16];
    int k = 0;
    for (int i = 1; i < size; i++) {
        int is_predefined = 0;
        for (int j = 0; j < 15; j++) {
            if (i == predefined[j]) {
                is_predefined = 1;
                break;
            }
        }
        if (!is_predefined) {
            arr[k++] = i;
        }
    }

    srand(time(0));
    shuffle(arr, size - 16);

    for (int i = 16; i < size; i++) {
        X[i] = arr[i - 16];
    }
}
