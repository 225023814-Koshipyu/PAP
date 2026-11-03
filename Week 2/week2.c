#include <stdio.h>

int main() {
    // 1. Declare variables for the basic calculator
    double revenue = 0.0;
    double expenses = 0.0;
    double balance = 0.0;

    // Extension Exercise variables
    int departments = 0;
    double payroll = 0.0;
    double procurement = 0.0;
    double assets = 0.0;

    // 2. Constants (Good practice for fixed values)
    const char* SYSTEM_NAME = "MUNICIPAL BUDGET CALCULATOR";
    const char* DEPARTMENT_NAME = "MUNICIPAL FINANCIAL MANAGEMENT SYSTEM (MFMS)";

    printf("====================================\n");
    printf("   %s\n", SYSTEM_NAME);
    printf("   %s\n", DEPARTMENT_NAME);
    printf("====================================\n\n");

    // 3. Prompt for basic input
    printf("Enter total revenue: N$");
    scanf("%lf", &revenue); // %lf is used for double

    printf("Enter total expenses: N$");
    scanf("%lf", &expenses);

    // 4. Calculate the balance
    balance = revenue - expenses;

    // 5. Display the basic results
    printf("\n--- BASIC BUDGET REPORT ---\n");
    printf("Revenue:    N$%15.2f\n", revenue);
    printf("Expenses:   N$%15.2f\n", expenses);
    printf("Balance:    N$%15.2f\n", balance);

    // 6. Determine if it's a surplus or deficit
    if (balance > 0) {
        printf("Status:     SURPLUS\n");
    } else if (balance < 0) {
        printf("Status:     DEFICIT\n");
    } else {
        printf("Status:     BALANCED\n");
    }

    // 7. Extension Exercise
    printf("\n--- EXTENSION: EXTRA BUDGET DATA ---\n");
    printf("Enter number of departments: ");
    scanf("%d", &departments); // %d is used for int

    printf("Enter total payroll: N$");
    scanf("%lf", &payroll);

    printf("Enter total procurement: N$");
    scanf("%lf", &procurement);

    printf("Enter total assets: N$");
    scanf("%lf", &assets);

    printf("\n--- MUNICIPAL FINANCIAL SUMMARY ---\n");
    printf("Departments: %d\n", departments);
    printf("Payroll:     N$%15.2f\n", payroll);
    printf("Procurement: N$%15.2f\n", procurement);
    printf("Assets:      N$%15.2f\n", assets);

    return 0;
}