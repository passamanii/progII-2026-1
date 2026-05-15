#include <stdio.h>


int main() {

    double prices[5];
    int amounts[5];
    double total1, total2, total3, total4, total5; //Total Cash Per Product
    double subtotal, comission;
    int msi; //MSI - Most Sold Index

    for (int i = 0; i < 5; i++) {
        
        printf("\n----------------- Product %d -----------------\n", i+1);
        printf("Input the price of the product %d: ", i+1);
        scanf("%lf", &prices[i]);

        printf("Input the amount of product %d sold: ", i);
        scanf("%d", &amounts[i]);

        if (i > 0) {
            if (amounts[i] > amounts[i-1]) {
                msi = i;
            }
        }
    }

    total1 = prices[0] * amounts[0];
    total2 = prices[1] * amounts[1];
    total3 = prices[2] * amounts[2];
    total4 = prices[3] * amounts[3];
    total5 = prices[4] * amounts[4];

    printf("----------------- Report -----------------\n");

    for (int i = 0; i < 5; i++) {

        printf("Product %d. Amount: %d. Unitary Price: R$%.2f. Total Value: R$%.2f\n", i+1, amounts[i], prices[i], amounts[i] * prices[i]);
    }

    subtotal = total1 + total2 + total3 + total4 + total5;
    comission = subtotal * 0.05;

    printf("Total Revenue: %.2f\n", subtotal);
    printf("Comission Revenue: %.2f\n", comission);
    printf("Best-Seller Product Price: %.2f", prices[msi]);

    return 0;
}