#include <stdio.h>
#include <math.h>
#define interest 0.01
#define limit 100

typedef struct {
    char id[limit];
    double tax;
    int overdue_months;
    double total_fine;
} fine;

int is_same_str(char* s1, char* s2) {
    
    for (int i=0; i < limit; i++) {
        if (*(s1+i) != '\0' || *(s2+i) != '\0'){ // Aritmética de Ponteiros. Same as s1[i] e s2[i]
            if (*(s1+i) != *(s2+i)) return 0;
        } else return 1;
    }
}

int main() {

    int size = 0;
    fine f1[limit];
    
    for (int i=0; i < limit; i++) {
        printf("Write your id: ");
        scanf("%s", f1[i].id);

        if (!is_same_str(f1[i].id, "XXX")) {
            printf("Write the tax amount:");
            scanf("%lf", &f1[i].tax);

            printf("Write the number of overdue months: ");
            scanf("%d", &f1[i].overdue_months);
            
            f1[i].total_fine = f1[i].tax * pow(1+interest, f1[i].overdue_months);
            size++;
        } else break;
    }

    for (int i=0; i < size; i++) {
        printf(
            "\nID: %s\n"
            "TAX AMOUNT: $%.2lf\n"
            "OVERDUE MONTHS: %d\n"
            "TOTAL FINE: $%.2lf\n",
            f1[i].id, 
            f1[i].tax, 
            f1[i].overdue_months, 
            f1[i].total_fine
        );
    }

    return 0;
}