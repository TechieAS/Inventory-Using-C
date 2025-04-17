#include <stdio.h>
#include <string.h>

struct Item {
    char item_name[50];
    int quantity;
    float price;
};

void deleteItem(struct Item inventory[], int *itemcount, char name[]);
void displayInventory(struct Item inventory[], int itemcount);

int main() {
    struct Item inventory[100];
    int itemcount = 0;
    char input[50];
    int quantity;
    int choice, choice1;
    float price;
    
    do {
        printf("\nInventory Management System\n");
        printf("1. Add items\n");
        printf("2. Update quantity\n");
        printf("3. Display Inventory\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (itemcount < 100) {
                    printf("Enter item name: ");
                    scanf(" %[^\n]", inventory[itemcount].item_name);
                    printf("Enter item quantity: ");
                    scanf("%d", &inventory[itemcount].quantity);
                    printf("Enter item price: ");
                    scanf("%f", &inventory[itemcount].price);
                    itemcount++;
                    printf("Item added successfully!\n");
                } else {
                    printf("Inventory is full!\n");
                }
                break;

            case 2:
                printf("Enter name: ");
                scanf(" %[^\n]", input);
                int found = 0;
                for (int i = 0; i < itemcount; i++) {
                    if (strcmp(inventory[i].item_name, input) == 0) {
                        printf("Enter new quantity: ");
                        scanf("%d", &quantity);
                        inventory[i].quantity = quantity;
                        printf("Updated successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Item not found!\n");
                }
                break;

            case 3:
                displayInventory(inventory, itemcount);
                break;

            case 4:
                printf("Enter name: ");
                scanf(" %[^\n]", input);
                deleteItem(inventory, &itemcount, input);
                break;

            case 5:
                printf("Exiting program...\nBye!\n");
                return 0;
        }
        printf("Do you want to continue again (yes=1/No=2)? ");
        scanf("%d", &choice1);
    } while (choice1 == 1);

    printf("Bye...\n");
    return 0;
}

void displayInventory(struct Item inventory[], int itemcount) {
    if (itemcount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\n%-20s %-10s %-10s\n", "Item Name", "Quantity", "Price");
    printf("------------------------------------------\n");
    for (int i = 0; i < itemcount; i++) {
        printf("%-20s %-10d $%.2f\n", inventory[i].item_name, inventory[i].quantity, inventory[i].price);
    }
}

void deleteItem(struct Item inventory[], int *itemcount, char name[]) {
    int found = 0;
    for (int i = 0; i < *itemcount; i++) {
        if (strcmp(inventory[i].item_name, name) == 0) {
            for (int j = i; j < (*itemcount) - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*itemcount)--;
            printf("Deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item not found!\n");
    }
}