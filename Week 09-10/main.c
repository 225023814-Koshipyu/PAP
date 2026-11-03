#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For system("mkdir")
#include "employee.h"
#include "file_handler.h"

void displayMenu() {
    printf("\n==================================\n");
    printf("  WEEK 9 & 10: FILE HANDLING LAB\n");
    printf("==================================\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Save Data (Text File)\n");
    printf("4. Load Data (Text File)\n");
    printf("5. Save Data (Binary File)\n");
    printf("6. Load Data (Binary File)\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice;
    
    // Create the "data" folder automatically so the program doesn't crash
    system("mkdir data >nul 2>&1");

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); 
            choice = -1;
        } else {
            while(getchar() != '\n'); // clear newline
        }

        switch(choice) {
            case 1: {
                int id; char name[NAME_LEN]; double salary;
                printf("Enter ID: "); scanf("%d", &id); while(getchar() != '\n');
                printf("Enter Name: "); fgets(name, NAME_LEN, stdin); name[strcspn(name, "\n")] = 0;
                printf("Enter Salary: "); scanf("%lf", &salary);
                addEmployee(id, name, salary);
                break;
            }
            case 2:
                displayEmployees();
                break;
            case 3:
                saveDataText();
                break;
            case 4:
                loadDataText();
                break;
            case 5:
                saveDataBinary();
                break;
            case 6:
                loadDataBinary();
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}