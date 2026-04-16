#include <stdio.h>


int process(int a, int b, int c, int d) {

    int dif = ((a*b) - (c*d));

    return dif;
}

int main() {

    int A, B, C, D;
    int dif;

    printf("Input 4 integers(A B C D): ");
    scanf("%d %d %d %d", &A, &B, &C, &D);

    dif = process(A, B, C, D);

    printf("The difference of the product of %d and %d for %d and %d is: %d\n", A, B, C, D, dif);

    return 0;
}



