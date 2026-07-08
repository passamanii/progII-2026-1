#include <stdio.h>
#include <stdlib.h>

#define slimit 100
#define size 56

typedef struct {
    char owner[slimit]; //InEx. "John Krasinski"
    char chassi[slimit]; //InEx. "9BWZZZ377VT004251"
    char model[slimit]; //InEx. "Onix LT"
    char brand[slimit];  //InEx. "Chevrolet"
    char color[slimit]; //InEx. "Prata"
    char fuel[slimit]; //InEx. "Flex"
    int fabricated; //InEx. "2020"
    char plate[slimit]; //InEx. "ABC1D23"
} vehicle;

void removenline(char *line) {
    
    for (int i=0; *(line+i) != '\0'; i++) {
        if (line[i] == '\r' || i[line] == '\n')  {
            *(line+i) = '\0';
        }
    }
}

int compares(char *s1, char *s2) {
    
    
    for (int i=0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 1;
    }
    
    return 0;
}

int contains(char *s, char c) {

    for (int i=0; *(s+i) != '\0'; ++i) { 
        if (*(s+i) == c) return 1;
    }

    return 0;
}

void main_menu() {
    printf("\n"
        "0- REGISTER\n"
        "1- LIST 90's\n"
        "2- LIST 'A'\n"
        "3- LIST EVEN\n"
        "4- UPDATE OWNER\n"
        "5 - CLEAR CHAT\n"
        "6 - CLOSE PROGRAM"
    );
}

void _register(vehicle *v) {

    FILE* file = fopen("inputs/05.txt", "r");

    if (!file) {
        printf("ERROR.\n");
        return;
    }

    for (int i=0; i < size; i++) {
        removenline(fgets((v+i)->owner, slimit, file));
        removenline(fgets((v+i)->chassi, slimit, file));
        removenline(fgets((v+i)->model, slimit, file));
        removenline(fgets((v+i)->brand, slimit, file));
        removenline(fgets((v+i)->color, slimit, file));
        removenline(fgets((v+i)->fuel, slimit, file));
        fscanf(file, "%d", &(v+i)->fabricated);
        fgetc(file);
        fgetc(file); // A TERMINAÇÃO DE LINHA NO WINDOWS É "\r\n", ENTÃO SÃO NECESSÁRIOS DOIS GETCHAR().
        removenline(fgets((v+i)->plate, slimit, file));
    }

    printf("\n--> REGISTER SUCEEDED!\n");
}

void list90s(vehicle *v) {

    int hook = 0;

    for (int i=0; i < size; i++) {
        if (((v+i) -> fabricated <= 1990) && (compares((v+i) -> fuel, "Gasolina"))) { // Same as v[i].fuel and *(v+i).fuel
            hook = 1;
            printf(
                "OWNER [%d]: %s\n"
                "\n",
                i,
                (v+i) -> owner
            );
        }
    }

    if (!hook) printf("\n--> NO OWNER FOUND.\n");
    
    printf("--> RETURNING TO MAIN MENU..\n");
}

void lista(vehicle *v) {

    for (int i=0; i < size; ++i) {
        if (v[i].plate[0] == 'A' && contains("027", v[i].plate[6])) {
            printf(
                "OWNER: %s\n"
                "PLATE: %s\n"
                "\n",
                (v+i) -> owner,
                (v+i) -> plate
            );
        }
    }
}

void listeven(vehicle *v) {

    for (int i=0; i < size; i++) {
        int sum = 0;
        for (int j=0; (v+i) -> plate[j] != '\0'; j++) {
            if (v[i].plate[j] >= '0' && v[i].plate[j] <= '9') {
                sum += v[i].plate[j] - '0';
            }
        }

        if (!(sum % 2)) {
            printf(
                "MODEL: %s\n"
                "COLOR: %s\n",
                v[i].model,
                (v+i) -> color
            );
        }
    }
}

void upd_owner(vehicle *v, char *c, char *nn) {

    int j;

    for (int i=0; i < size; i++) {
        if (compares((v+i) -> chassi, c)) {
            printf("before: %s\n", v[i].owner);
            for (j=0; nn[j] != '\0'; j++) {
                v[i].owner[j] = nn[j];
            }
            v[i].owner[j+1] = '\0';
            printf("after: %s\n", v[i].owner);
        }
    }
}

void close() {
    
    printf(
        "\n--> THANKS FOR USING OUR PRODUCT.\n"
        "--> SHUTTING SYSTEM DOWN..\n"
    );
}

int main() {

    int opt;

    vehicle cars[size];    

    while (1) {
        main_menu();
        printf("\n--> SELECT THE DESIRED OPTION: ");
        scanf("%d", &opt);
        getchar();

        switch (opt) {
            case 0:
                _register(cars);
                break;
            case 1:
                list90s(cars);
                break;
            case 2:
                lista(cars);
                break;
            case 3:
                listeven(cars);
                break;
            case 4:
                char chassi[slimit], newowner[slimit];

                printf("--> INFORM THE CHASSI NUMBER: ");
                removenline(fgets(chassi, slimit, stdin));

                printf("--> INFORM THE NEW OWNER'S NAME: ");
                removenline(fgets(newowner, slimit, stdin));

                upd_owner(cars, chassi, newowner);
                break;
            case 5:
                int opt1;
                printf("\n--> WHITCH OPERATING SYSTEM ARE YOU IN?\n"
                "0 - WINDOWS\n"
                "1 - LINUX "
                );
                scanf("%d", &opt1);
                getchar();

                switch (opt1) {
                    case 0:
                        system("cls");
                        break;
                    case 1:
                        system ("clear");
                        break;
                }
                break;
            case 6:
                close();
                return 0;
            default:
                printf("--> INSERT A VALID OPTION.\n");
        }
    }


    return 0;
}