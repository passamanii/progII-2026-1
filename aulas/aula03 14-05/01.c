#include <stdio.h>


int main() {

    int arr[9];

    for (int i = 0; i < 9; i++) {
        printf("Input a integer for the Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 9; i++) {
        int state = 1;

        if (arr[i] == 1) {
            continue;
        }
        
        for (int j = 2; j <= arr[i]/2; j++) {
            if (arr[i] % j == 0) state = 0;
        }

        if (state) {
            printf("Prime Element Detected: %d. Element Index: %d.\n", arr[i], i);
        }
    }

    return 0;
}