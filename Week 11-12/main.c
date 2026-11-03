#include <stdio.h>
#include <string.h>
#include "records.h"

int main() {
    // WEEK 11: Array of structures
    Employee staff[MAX_EMPLOYEES] = {
        {1001, "Maria", "Finance", 18500.50, {15, 3, 2022}},
        {1002, "Simon", "HR", 17200.00, {10, 1, 2021}},
        {1003, "Anna", "IT", 21000.75, {5, 8, 2023}}
    };
    int employeeCount = 3;

    double salaryA = 18500.50;
    double salaryB = 21000.75;

    printf("=== WEEK 11: STRUCTURES ===\n");
    displayEmployees(staff, employeeCount);

    printf("\n=== WEEK 12: POINTERS ===\n");
    printf("Original Salaries: A = %.2f, B = %.2f\n", salaryA, salaryB);

    // 1. The WRONG way (Pass by value)
    swapWrong(salaryA, salaryB);
    printf("After swapWrong:   A = %.2f, B = %.2f (Nothing changed!)\n", salaryA, salaryB);

    // 2. The RIGHT way (Pass by address with &)
    swapSalaries(&salaryA, &salaryB);
    printf("After swapSalaries:A = %.2f, B = %.2f (It worked!)\n", salaryA, salaryB);

    // 3. Updating a record using findEmployee and pointers
    printf("\n--- Updating Employee 1002 (Simon) ---\n");
    Employee *found = findEmployee(staff, employeeCount, 1002);
    
    if (found != NULL) {
        updateSalary(found, 20000.00); // Uses -> operator inside function
        printf("Success! Simon's new salary is: N$%.2f\n", found->salary);
    } else {
        printf("Employee not found.\n");
    }

    // 4. Testing an ID that doesn't exist
    printf("\n--- Searching for Employee 9999 ---\n");
    Employee *notFound = findEmployee(staff, employeeCount, 9999);
    if (notFound == NULL) {
        printf("Employee 9999 does not exist (returned NULL safely).\n");
    }

    return 0;
}