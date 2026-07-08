#include <stdio.h>

#define size 3
#define slimit 100

typedef struct {
    char name[slimit];
    int phone;
    int birth[3];
} people;

int main() {

    int n;
    people p[size];

    for (int i=0; i < size; i++) { // Recebe os dados
        printf("Name: ");
        fgets(p[i].name, slimit, stdin);

        printf("Phone: ");
        scanf("%d", &p[i].phone);
        getchar();

        printf("Date of Birth(XX XX XX): ");
        scanf("%d %d %d", &p[i].birth[0], &p[i].birth[1], &p[i].birth[2]);
        getchar();
    }

    printf("Write the desired month: ");
    scanf("%d", &n);
    getchar();

    for (int i=0; i < size; i++) {
        if (p[i].birth[1] == n){
            printf(
                "\nName : %s"
                "Phone: %d\n"
                "Date of Birth: %02d/%02d/%02d\n",
                p[i].name,
                p[i].phone,
                p[i].birth[0], p[i].birth[1], p[i].birth[2]
            );
        }
    } 

    return 0;
}