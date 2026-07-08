#include <stdio.h>
#define size 3

typedef struct {
    int id;
    char name[99];
    double wage;
    double inssDiscount;
    double discountedWage;
} employee;

void print_struct(employee* e) {

    printf("\nId: %d\n", e -> id);
    printf("Name: %s", e -> name);
    printf("Wage: %.2lf\n", e -> wage);
    printf("Discount: %.2lf\n", e -> inssDiscount);
    printf("Discounted Wage: %.2lf\n\n", e -> discountedWage);
}

int main() {

    employee e[size];

    for (int i = 0; i < size; i++) {

        scanf("%d", &e[i].id);
        getchar();

        fgets(e[i].name, 99, stdin);

        scanf("%lf", &e[i].wage); 
        getchar();

        e[i].inssDiscount = 0.12 * e[i].wage;
        e[i].discountedWage = e[i].wage - e[i].inssDiscount;

        print_struct(&e[i]);

    }
    
    return 0;
}