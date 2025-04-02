// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For Linux or MacOS
// #include <windows.h> For Windows

// Market Data Structure
typedef struct 
{
    int code;
    char name[30];
    float price;
} Product;

typedef struct
{
    Product product;
    int amount;
} Cart;


// Functions
void infoProduct(Product prod);
void menu();
void registerProduct();
void listProduct();
void buyProduct();
void showCart();
Product takeProductPerCode(int code);
int * haveInCart(int code);
void checkout();

// Static Constants
static int counterProduct = 0;
static int counterCart = 0;
static Cart cart[50];
static Product products[50];

// Function Main
int main()
{
    menu();
    return 0;
}

// Implementations Functions
void infoProduct(Product prod)
{
    printf("\nCode: %d\nName: %s\nPrice: %.2f\n", prod.code, strtok(prod.name, "\n"), prod.price);
}

void menu()
{
    printf("\n=========================================\n");
    printf("\n              Welcome!                   \n");
    printf("\n=========================================\n");
    printf("\n             Geek Shop                   \n");
    printf("\n=========================================\n\n");

    printf("Select an option:\n\n");
    printf(" - 1 Register\n");
    printf(" - 2 List\n");
    printf(" - 3 Buy\n");
    printf(" - 4 View\n");
    printf(" - 5 Checkout\n");
    printf(" - 6 Exit\n");

    int option;
    printf("\n   Optin: ");
    scanf("%d", &option);
    getchar();

    switch (option)
    {
    case 1:
        registerProduct();
        break;
    case 2:
        listProduct();
        break;
    case 3:
        buyProduct();
        break;
    case 4:
        showCart();
        break;
    case 5:
        checkout();
        break;
    case 6:
        printf("\nCome back soon!\n");
        sleep(2); 
        exit(0);
        break;
    
    default:
        printf("\nInvalid Option!\n");
        sleep(2);
        menu();
        break;
    }

}

void registerProduct()
{
    printf("\n == Register Product == \n");

    printf("\nName Product: ");
    fgets(products[counterProduct].name, 30, stdin);

    printf("\nPrice Product: ");
    scanf("%f", &products[counterProduct].price);

    printf("\nThe product %s was registered successfully!\n", strtok(products[counterProduct].name, "\n"));

    products[counterProduct].code = (counterProduct + 1);
    counterProduct++;
}

void listProduct()
{
    if(counterProduct > 0)
    {
        printf("\n == List Product == \n\n");
        for (int i = 0; i < counterProduct; i++)
        {
            infoProduct(products[i]);
            printf("\n===========================\n");
            sleep(1);
        }
    }
    else
    {
        printf("\nThere are no registered products.\n");
        sleep(2);
        menu();
    }

}

void buyProduct()
{

}

void showCart()
{
    if(counterCart > 0)
    {
        printf("\nCart Products:\n");
        for (int i = 0; i < counterCart; i ++)
        {
            infoProduct(cart[i].product);
            printf("\nAmount: %d\n", cart[i].amount);
            sleep(1);
        }
    }
    else
    {
        printf("\nEmpty cart.\n");
    }
}

Product takeProductPerCode(int code)
{
    Product p;
    for (int i = 0; i < counterProduct; i++)
    {
        if(products[i].code == code)
        {
            p = products[i];
        }
    }
    return p;
}

int * haveInCart(int code)
{
    int static back[] = {0, 0};
    for (int i = 0; i < counterCart; i++)
    {
        if(cart[i].product.code == code)
        {
            back[0] = 1; // Have this product in Cart
            back[1] = i; // Index of Product in Cart
        }
    }
    return back;
}

void checkout()
{
    // Continue...
}
