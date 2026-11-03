#include <stdio.h>
#include <string.h>

/* =========================================
   WEEK 7: STRINGS (Supplier Management)
   ========================================= */

// A struct to hold our supplier data (makes it easier to manage)
typedef struct {
    char name[100];
    char email[100];
    char phone[30];
    char town[50];
} Supplier;

Supplier currentSupplier; // Global variable for the lab

// Helper function to remove the newline character left by fgets()
void removeNewline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

// LAB TASK 1: Accept and display supplier info
void addSupplier() {
    printf("\n--- Add Supplier ---\n");
    
    printf("Enter supplier name: ");
    fgets(currentSupplier.name, sizeof(currentSupplier.name), stdin);
    removeNewline(currentSupplier.name);

    printf("Enter email: ");
    fgets(currentSupplier.email, sizeof(currentSupplier.email), stdin);
    removeNewline(currentSupplier.email);

    printf("Enter phone: ");
    fgets(currentSupplier.phone, sizeof(currentSupplier.phone), stdin);
    removeNewline(currentSupplier.phone);

    printf("Enter town: ");
    fgets(currentSupplier.town, sizeof(currentSupplier.town), stdin);
    removeNewline(currentSupplier.town);

    printf("Supplier added successfully!\n");
}

// LAB TASK 2: Display lengths using strlen()
void displaySupplierLength() {
    printf("\n--- Supplier String Lengths ---\n");
    printf("Supplier name length: %zu\n", strlen(currentSupplier.name));
    printf("Email length: %zu\n", strlen(currentSupplier.email));
    printf("Town length: %zu\n", strlen(currentSupplier.town));
}

// LAB TASK 3: Search using strcmp()
void searchSupplier() {
    char searchName[100];
    printf("\n--- Search Supplier ---\n");
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    removeNewline(searchName);

    // Compare the input with the stored supplier name
    if (strcmp(currentSupplier.name, searchName) == 0) {
        printf("Supplier found.\n");
    } else {
        printf("Supplier not found.\n");
    }
}

// LAB TASK 4 & 5: strcpy and strcat
void displaySupplierDescription() {
    char backupName[100];
    char description[200];

    // 1. Copy the name using strcpy
    strcpy(backupName, currentSupplier.name);
    printf("\n--- Copy Test ---\n");
    printf("Original: %s\n", currentSupplier.name);
    printf("Backup:   %s\n", backupName);

    // 2. Construct a sentence using strcat
    strcpy(description, currentSupplier.name); // Start with name
    strcat(description, " operates in ");      // Add middle text
    strcat(description, currentSupplier.town); // Add town
    strcat(description, ".");                  // Add full stop

    printf("\n--- Constructed Description ---\n");
    printf("%s\n", description);
}


/* =========================================
   WEEK 8: FUNCTIONS (Reusable MFMS)
   ========================================= */

// LAB TASK 1: displayWelcome
void displayWelcome() {
    printf("Welcome to the Municipal Financial Management System\n");
}

// LAB TASK 2: calculateVAT
float calculateVAT(float amount) {
    return amount * 0.15;
}

// LAB TASK 3: calculateSalary
float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

// LAB TASK 4: calculateBudget
void checkBudget(float revenue, float expenses) {
    float result = revenue - expenses;
    printf("Budget balance: %.2f\n", result);
    
    if (result > 0) {
        printf("Status: SURPLUS\n");
    } else if (result < 0) {
        printf("Status: DEFICIT\n");
    } else {
        printf("Status: BALANCED\n");
    }
}

// LAB TASK 6: searchEmployee
int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i; // Found, return index
        }
    }
    return -1; // Not found
}


/* =========================================
   THE MAIN MENU (Integrating it all)
   ========================================= */

void displayMenu() {
    printf("\n================================\n");
    printf("   WEEK 7 & 8 LABORATORY MENU\n");
    printf("================================\n");
    printf("1. Add Supplier (Week 7)\n");
    printf("2. Show String Lengths (Week 7)\n");
    printf("3. Search Supplier (Week 7)\n");
    printf("4. Copy & Concat Test (Week 7)\n");
    printf("5. Calculate VAT (Week 8)\n");
    printf("6. Calculate Salary (Week 8)\n");
    printf("7. Calculate Budget (Week 8)\n");
    printf("8. Search Employee (Week 8)\n");
    printf("9. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice;
    
    // Initialize dummy supplier so the string tests don't crash if run first
    strcpy(currentSupplier.name, "ABC Office Supplies");
    strcpy(currentSupplier.email, "sales@abc.com");
    strcpy(currentSupplier.phone, "0611234567");
    strcpy(currentSupplier.town, "Windhoek");

    displayWelcome();

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); // Clear bad input
            choice = -1;
        } else {
            while(getchar() != '\n'); // Clear the newline left by scanf
        }

        switch(choice) {
            case 1: 
                addSupplier(); 
                break;
            case 2: 
                displaySupplierLength(); 
                break;
            case 3: 
                searchSupplier(); 
                break;
            case 4: 
                displaySupplierDescription(); 
                break;
            case 5: {
                float amount;
                printf("Enter amount for VAT: ");
                scanf("%f", &amount);
                printf("VAT (15%%): %.2f\n", calculateVAT(amount));
                break;
            }
            case 6: {
                float basic, housing, transport;
                printf("Enter basic, housing, transport: ");
                scanf("%f %f %f", &basic, &housing, &transport);
                printf("Gross Salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;
            }
            case 7: {
                float rev, exp;
                printf("Enter revenue and expenses: ");
                scanf("%f %f", &rev, &exp);
                checkBudget(rev, exp);
                break;
            }
            case 8: {
                int employeeIDs[] = {101, 102, 103, 104, 105};
                int searchId;
                printf("Enter employee ID to search: ");
                scanf("%d", &searchId);
                
                int pos = searchEmployee(searchId, employeeIDs, 5);
                if (pos != -1) {
                    printf("Employee found at position %d.\n", pos);
                } else {
                    printf("Employee not found.\n");
                }
                break;
            }
            case 9:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);

    return 0;
}