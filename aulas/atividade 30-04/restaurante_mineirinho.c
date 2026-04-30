#include <stdio.h>
#include <math.h>


void request_item_input(char *name_item, float *price_item, int *amount_item) {
    printf("Input the name of the item (MAX 100): ");
    fgets(name_item, 100, stdin);

    printf("Input the item price: ");
    scanf("%f", price_item);
    getchar();
                
    printf("Input the amount consumed of this item: ");
    scanf("%d", amount_item);
    getchar();
}

float calcular_total_conta(float price1, int amount1, float price2, int amount2, float price3, int amount3, float price4, int amount4) {

    float total = ((price1*amount1)+(price2*amount2)+(price3*amount3)+(price4*amount4));
    
    return total;
}

int main() {
    
    char name[100]; //Nome do Cliente 
    char name_item1[100], name_item2[100], name_item3[100], name_item4[100]; //Nomes dos itens consumidos
    float price_item1 = 0, price_item2 = 0, price_item3 = 0, price_item4 = 0; //Preços dos itens
    int items_amount, amount_item1 = 0, amount_item2 = 0, amount_item3 = 0, amount_item4 = 0; //Quantidade consumida dos itens
    float subtotal = 0, total_conta = 0; //Total da conta
    float credit_tax = 0, taxa_servico = 0; //Taxas
    float total_desconto = 0, desconto = 0; //Descontos
    int client_type; //Tipo de cliente
    int payment_type; //Forma de pagamento
    char *payment_type_name; //Forma de pagamento

    printf("Input the client's name(MAX 100): ");
    fgets(name, 100, stdin);

    printf("Input the amount of different items consumed(MAX 4): ");
    scanf("%d", &items_amount);
    getchar();

    switch (items_amount) {

        case 4:
            request_item_input(name_item4, &price_item4, &amount_item4);
        case 3:
            request_item_input(name_item3, &price_item3, &amount_item3);
        case 2:
           request_item_input(name_item2, &price_item2, &amount_item2);
        case 1:
           request_item_input(name_item1, &price_item1, &amount_item1);
    }

    total_conta = calcular_total_conta(price_item1, amount_item1, price_item2, amount_item2, price_item3, amount_item3, price_item4, amount_item4);

    if (total_conta > 100) {
        taxa_servico = (0.1 * total_conta);
    } else {
        taxa_servico = (0.05 * total_conta);
    }

    subtotal = total_conta;
    total_conta += taxa_servico;

    printf(
        "(1) - Common CLient\n"
        "(2) - VIP Client\n"
        "(3) - Employee\n"
        "Input the type of client: ");
    scanf("%d", &client_type);

    if (client_type == 2) {
        desconto += (0.1 * total_conta);
    } else if (client_type == 3) {
        if (total_conta > 50) {
            desconto += (0.2 * total_conta);
        } else {
            desconto += (0.1 * total_conta);
        }
    }

    total_conta -= desconto;
    total_desconto += desconto;
    desconto = 0;

    printf(
        "(1) - Cash\n"
        "(2) - Debit\n"
        "(3) - Credit\n"
        "(4) - PIX\n"
        "Input the desired payment type: ");
    scanf("%d", &payment_type);

    switch (payment_type) {

        case 1:
            desconto += (0.05 * total_conta);
            payment_type_name = "Cash";
            break;
        case 2:
            payment_type_name = "Debit";
            break;
        case 3:
            credit_tax = (pow(total_conta * 0.1, 1.1)); //Não sei se entendi o sentido de utilizar pow() aqui, mas fiz o quê melhor interpretei
            total_conta += credit_tax;
            payment_type_name = "Credit";
            break;
        case 4:
            desconto += (0.07 * total_conta);
            payment_type_name = "PIX";
    }

    total_conta -= desconto;
    total_desconto += desconto;

    printf("\nClient's Name: %s", name);
    printf("Total bill: R$%.2f\n", subtotal);
    printf("Service Tax: R$%.2f\n", taxa_servico);
    if (payment_type == 3) {
        printf("Credit Tax: R$%.2f\n", credit_tax);
    }
    printf("Total discounts: R$%.2f\n", total_desconto);
    printf("Pre-Discount Bill: R$%.2f\n", total_conta + total_desconto);
    printf("Discounted Bill: R$%.2f\n", total_conta);
    printf("Payment type: %s", payment_type_name);

    return 0;
}