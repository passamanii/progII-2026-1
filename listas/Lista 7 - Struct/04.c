#include <stdio.h>

#define slimit 100
#define size 50

typedef struct {
    char code[slimit]; //InEx. "50F2"
    char author[slimit]; //InEx. "John Green"
    char book[slimit]; //InEx. "Noites Brancas"
    char publisher[slimit]; //InEx. "HarperCollins"
    int pages; //InEx. "594"
} book;

int is_same_str(char* s1, char* s2) {
    
    int i = 0;

    while (*(s1+i) == *(s2+i)) {
        if (*(s1+i) == '\0') return 1;
        i++;
    }

    return 0;
}

void remove_nline(char *string) {

    int i = 0;

    while (string[i] != '\0') {
        if (string[i] == '\n' || *(string+i) == '\r') {
            string[i] = '\0';
            return;
        }
        i++;
    }
}

void main_menu() {

    printf(
        "\n0 - Cadastro\n"
        "1 - Consulta (B)\n"
        "2 - Consulta (C)\n"
        "3 - Consulta (D)\n"
        "4 - Fechar Sistema\n"
    );
}

void cadastro(book f[size][3]) {

    FILE* file = fopen("inputs/04.txt", "r");

    if (!file) {
        perror("ERROR.\n"); //Print Error
        return;
    }

    for (int i=0; i < size; i++) {
        for (int j=0; j < 3; j++) {
            fgets(f[i][j].code, slimit, file);
            fgets(f[i][j].author, slimit, file);
            fgets(f[i][j].book, slimit, file);
            fgets(f[i][j].publisher, slimit, file);
            fscanf(file, "%d", &f[i][j].pages);
            fgetc(file);
            fgetc(file);

            remove_nline(f[i][j].code);
            remove_nline(f[i][j].author);
            remove_nline(f[i][j].book);
            remove_nline(f[i][j].publisher);
        }
    }

    fclose(file);
    printf("-> SUCESSFUL REGISTER..\n");
    printf("-> PRESS 'ENTER' TO RETURN..");
    getchar();
}

void consultaB(book f[size][3]) {
    
    char code[slimit];
    
    printf("-> INFORM THE DESIRED CODE: ");
    scanf("%s", code);
    getchar();
    
    do {
        int state = 0;

        for (int i=0; i < size; i++) {
            for (int j=0; j < 3; j++) {
                if (is_same_str(code, f[i][j].code)) {
                    printf(
                        "\nCODE: %s\n"
                        "AUTHOR: %s\n"
                        "BOOK: %s\n"
                        "PUBLISHER: %s\n"
                        "PAGES: %d\n",
                        f[i][j].code,
                        f[i][j].author,
                        f[i][j].book,
                        f[i][j].publisher,
                        f[i][j].pages
                    );
                    state = 1;
                    break;
                }
            }
        }

        if (!state) printf("\n-> BOOK NOT FOUND.\n");
        

        printf("\n-> INFORM THE DESIRED CODE: ");
        scanf("%s", code);
        getchar();

    } while (!is_same_str(code, "-1"));


}

void consultaC(book f[size][3]) {
    
    char book[slimit];
    int section, state = 0, opt;

    do {
        printf(
            "\n0- EXACT SCIENCE\n"
            "1- HUMANITIES SCIENCE\n"
            "2- BIOMEDICAL SCIENCE\n"
            "\n-> INFORM THE DESIRED SECTION: "
        );
        fgets(book, slimit, stdin);
        sscanf(book, "%d", &section);
        printf("Section: %d", section);
        
        printf("\n-> INFORM THE BOOK'S NAME:");
        remove_nline(fgets(book, slimit, stdin));
        
        for (int i = 0; i < size; i++) {
            if (is_same_str(f[i][section].book, book)) {
                printf(
                    "\nCODE: %s\n"
                    "AUTHOR: %s\n"
                    "BOOK: %s\n"
                    "PUBLISHER: %s\n"
                    "PAGES: %d\n",
                    f[i][section].code,
                    f[i][section].author,
                    f[i][section].book,
                    f[i][section].publisher,
                    f[i][section].pages
                );
                state = !state;
                break;
            }
        }
        
        if (!state) printf("-> BOOK NOT FOUND.\n");

        printf(
            "\n0- YES\n"
            "1- NO\n\n"
            "DO YOU WANT TO CHECK ON ANOTHER BOOK? "
        );
        scanf("%d", &opt);
        getchar();

    } while (!opt);
}

void consultaD(book f[size][3]) {

    char author[slimit];
    int stt = 0;

    printf("-> WRITE THE NAME OF THE DESIRED AUTHOR: ");
    remove_nline(fgets(author, slimit, stdin));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            if (is_same_str(author, f[i][j].author)) {
                printf(
                    "\nCODE: %s\n"
                    "AUTHOR: %s\n"
                    "BOOK: %s\n"
                    "PUBLISHER: %s\n"
                    "PAGES: %d\n",
                    f[i][j].code,
                    f[i][j].author,
                    f[i][j].book,
                    f[i][j].publisher,
                    f[i][j].pages
                );
                stt = 1;
            }
        }
    }

    if (!stt) printf("\n-> BOOK NOT FOUD.\n");
}

void close() {

    printf(
        "\n-> THANKS FOR USING OUR SERVICES.\n"
        "-> EXITING PROGRAM...\n"
    );
}

int main() {

    int opt;

    book folder[size][3];

    while (1) {
        main_menu();
        
        printf("Select the desired option: ");
        scanf("%d", &opt);
        getchar();

        switch (opt) {
            case 0:
                cadastro(folder);
                break;
            case 1:
                consultaB(folder);
                break;
            case 2:
                consultaC(folder);
                break;
            case 3:
                consultaD(folder);
                break;
            case 4:
                close();
                return 0;
            default:
                printf("Insert a valid option.");
                continue;
        }   
    }
}