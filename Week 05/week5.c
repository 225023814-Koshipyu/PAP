#include <stdio.h>

void runSalaryAnalysis() {
    float salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average = 0;
    int count = 0;

    printf("\n--- Salary Capture (Enter 0 to stop) ---\n");

    // We use a while loop because we don't know how many they will enter
    while (1) {
        printf("Enter salary for employee %d: ", count + 1);
        
        if (scanf("%f", &salary) != 1) {
            while (getchar() != '\n'); // clear buffer if they type a letter
            printf("Invalid input. Please enter a number.\n");
            continue; // Skip the rest of this loop iteration
        }

        // BREAK: Stop if they enter 0
        if (salary == 0) {
            break; 
        }

        // CONTINUE: Skip negative salaries
        if (salary < 0) {
            printf("Negative salaries are not allowed. Skipping...\n");
            continue;
        }

        // If it's the first valid salary, set it as both highest and lowest
        if (count == 0) {
            highest = salary;
            lowest = salary;
        }

        if (salary > highest) highest = salary;
        if (salary < lowest) lowest = salary;

        total += salary;
        count++;
    }

    // Only calculate if they entered at least one salary
    if (count > 0) {
        average = total / count;
        printf("\n--- Salary Report ---\n");
        printf("Total Employees: %d\n", count);
        printf("Total Salary:    N$%.2f\n", total);
        printf("Average Salary:  N$%.2f\n", average);
        printf("Highest Salary:  N$%.2f\n", highest);
        printf("Lowest Salary:   N$%.2f\n", lowest);
    } else {
        printf("\nNo salaries were entered.\n");
    }
}

void printNumbers() {
    printf("\n--- Numbers 1 to 5 (For Loop) ---\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void passwordDemo() {
    int password = 0;
    printf("\n--- Password Demo (While Loop) ---\n");
    
    // Do...while guarantees the prompt shows at least once
    do {
        printf("Enter password (1234): ");
        scanf("%d", &password);
        
        if (password != 1234) {
            printf("Incorrect. Try again.\n");
        }
    } while (password != 1234);
    
    printf("Access granted!\n");
}

int main() {
    int choice;

    printf("====================================\n");
    printf("     WEEK 5: LOOPS LABORATORY\n");
    printf("====================================\n");

    do {
        printf("\n1. Municipal Salary Analysis\n");
        printf("2. Simple For Loop Demo\n");
        printf("3. Password Demo (Do-While)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = -1;
        } else {
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1: runSalaryAnalysis(); break;
            case 2: printNumbers(); break;
            case 3: passwordDemo(); break;
            case 4: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}