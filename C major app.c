#include <stdio.h>
#include <string.h>

// Define Structures
typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    char name[50];
    int quantity;
    float totalPrice;
} OrderItem;

typedef struct {
    OrderItem items[10];
    int itemCount;
    float totalAmount;
} Order;

// Function Prototypes
void displayMenu(MenuItem menu[], int itemCount);
void takeOrder(MenuItem menu[], int itemCount, Order *order);
void displayOrder(Order *order);
void calculateTotal(Order *order);
void checkOrderPlaced();

// Main Function
int main() {
    MenuItem menu[] = {
        {"Pizza", 8.99},
        {"Burger", 5.49},
        {"Pasta", 7.99},
        {"Salad", 4.99}
    };
    int menuCount = sizeof(menu) / sizeof(menu[0]);

    Order order = {{}, 0, 0.0};
    int choice;

    while (1) {
        printf("\nFood Order Management System\n");
        printf("1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Display Order\n");
        printf("4. Check Order Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(menu, menuCount);
                break;
            case 2:
                takeOrder(menu, menuCount, &order);
                break;
            case 3:
                displayOrder(&order);
                break;
            case 4:
                checkOrderPlaced();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function Implementations
void displayMenu(MenuItem menu[], int itemCount) {
    printf("\nMenu:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void takeOrder(MenuItem menu[], int itemCount, Order *order) {
    int itemNumber, quantity;

    printf("\nEnter item number to order: ");
    scanf("%d", &itemNumber);

    if (itemNumber < 1 || itemNumber > itemCount) {
        printf("Invalid item number.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    MenuItem selectedItem = menu[itemNumber - 1];
    strcpy(order->items[order->itemCount].name, selectedItem.name);
    order->items[order->itemCount].quantity = quantity;
    order->items[order->itemCount].totalPrice = quantity * selectedItem.price;
    order->itemCount++;

    calculateTotal(order);
    printf("Item added to order.\n");
}

void displayOrder(Order *order) {
    if (order->itemCount == 0) {
        printf("No items in the order.\n");
        return;
    }

    printf("\nCurrent Order:\n");
    for (int i = 0; i < order->itemCount; i++) {
        printf("%d. %s - Quantity: %d, Total: $%.2f\n", i + 1, order->items[i].name, order->items[i].quantity, order->items[i].totalPrice);
    }
    printf("Total Amount: $%.2f\n", order->totalAmount);
}

void calculateTotal(Order *order) {
    order->totalAmount = 0;
    for (int i = 0; i < order->itemCount; i++) {
        order->totalAmount += order->items[i].totalPrice;
    }
}

void checkOrderPlaced() {
    printf("\nOrder has been placed successfully! Estimated delivery time: 30 minutes.\n");
}
