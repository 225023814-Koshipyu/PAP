#include <stdio.h>
#include <string.h>
#include "employee.h"

int main() {
    EmployeeList staff;
    initList(&staff); // Set up the dynamic array

    int choice;
    int id;
    char name[30];
    double salary;

    printf("====================================\n");
    printf("  WEEK 13: DYNAMIC MEMORY (UNLIMITED)\n");
    printf("====================================\n");

    do {
        printf("\n1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit and Free Memory\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = -1;
        } else {
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name (no spaces): ");
                scanf("%29s", name);
                printf("Enter Salary: ");
                scanf("%lf", &salary);
                
                addEmployee(&staff, id, name, salary);
                printf("Employee added successfully!\n");
                break;

            case 2:
                displayEmployees(&staff);
                break;

            case 3:
                printf("\nFreeing memory and exiting...\n");
                freeList(&staff);
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}