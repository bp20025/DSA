#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1024

#include <stdbool.h>

bool check_duplicates(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return true; // 重複が見つかった
            }
        }
    }
    return false; // 重複がない
}


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

    // Set predefined values
    for (int i = 1; i <= 15; i++) {
        X[i] = predefined[i - 1];
    }

    // Fill the rest of the array with numbers from 1 to 1023, excluding the first 15 predefined numbers
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

    // Shuffle the array
    srand(time(0));
    shuffle(arr, size - 16);

    // Assign shuffled values to the rest of X
    for (int i = 16; i < size; i++) {
        X[i] = arr[i - 16];
    }
}

int main() {
    int X[SIZE] = {0};

    fill_array(X, SIZE);

    // Print the array for verification
    for (int i = 1; i < SIZE; i++) {
        printf("X[%d] = %d\n", i, X[i]);
    }

    return 0;
}
