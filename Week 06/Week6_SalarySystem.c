#include <stdio.h>

#define MAX_EMPLOYEES 50

/* ---------- Function Prototypes ---------- */
void captureSalaries(float salaries[], int size);
void displaySalaries(float salaries[], int size);
float calculateTotal(float salaries[], int size);
float calculateAverage(float salaries[], int size);
float findHighest(float salaries[], int size);
float findLowest(float salaries[], int size);
int  searchSalary(float salaries[], int size, float target);
void sortAscending(float salaries[], int size);

/* ---------- Main ---------- */
int main(void)
{
    float salaries[MAX_EMPLOYEES];
    int   count = 0;
    int   choice;

    do {
        printf("\n===== EMPLOYEE SALARY MANAGEMENT SYSTEM =====\n");
        printf("1. Capture 50 employee salaries\n");
        printf("2. Display all salaries\n");
        printf("3. Total salary expenditure\n");
        printf("4. Average salary\n");
        printf("5. Highest salary\n");
        printf("6. Lowest salary\n");
        printf("7. Search for a salary\n");
        printf("8. Sort salaries (lowest to highest)\n");
        printf("9. Display sorted salaries\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                captureSalaries(salaries, MAX_EMPLOYEES);
                count = MAX_EMPLOYEES;
                break;

            case 2:
                if (count == 0) { printf("No salaries captured yet.\n"); break; }
                displaySalaries(salaries, count);
                break;

            case 3:
                if (count == 0) { printf("No salaries captured yet.\n"); break; }
                printf("Total salary expenditure: %.2f\n",
                       calculateTotal(salaries, count));
                break;

            case 4:
                if (count == 0) { printf("No salaries captured yet.\n"); break; }
                printf("Average salary: %.2f\n",
                       calculateAverage(salaries, count));
                break;

            case 5:
                if (count == 0) { printf("No salaries captured yet.\n"); break; }
                printf("Highest salary: %.2f\n",
                       findHighest(salaries, count));
                break;

            case 6:
                if (count == 0) { printf("No salaries captured yet.\n"); break; }
                printf("Lowest salary: %.2f\n",
                       findLowest(salaries, count));
                break;

            case 7: {
                if (count == 0) { printf("No salaries captured yet.\n"); break; }
                float target;
                printf("Enter salary to search: ");
                scanf("%f", &target);
                int pos = searchSalary(salaries, count, target);
                if (pos != -1)
                    printf("Salary %.2f found at position %d (index %d).\n",
                           target, pos + 1, pos);
                else
                    printf("Salary %.2f NOT found.\n", target);
                break;
            }

            case 8:
                if (count == 0) { printf("No salaries captured yet.\n"); break; }
                sortAscending(salaries, count);
                printf("Salaries sorted successfully!\n");
                break;

            case 9:
                if (count == 0) { printf("No salaries captured yet.\n"); break; }
                printf("\n--- Sorted Salaries (Lowest to Highest) ---\n");
                displaySalaries(salaries, count);
                break;

            case 10:
                printf("Exiting... Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 10);

    return 0;
}

/* ---------- Function Definitions ---------- */

/* 1. Capture salaries using a loop */
void captureSalaries(float salaries[], int size)
{
    printf("\nEnter %d employee salaries:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }
    printf("All salaries captured successfully!\n");
}

/* 2. Display all salaries */
void displaySalaries(float salaries[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }
}

/* 3. Total salary expenditure */
float calculateTotal(float salaries[], int size)
{
    float total = 0.0f;
    for (int i = 0; i < size; i++)
        total += salaries[i];
    return total;
}

/* 4. Average salary */
float calculateAverage(float salaries[], int size)
{
    return calculateTotal(salaries, size) / size;
}

/* 5. Highest salary */
float findHighest(float salaries[], int size)
{
    float highest = salaries[0];
    for (int i = 1; i < size; i++)
        if (salaries[i] > highest)
            highest = salaries[i];
    return highest;
}

/* 6. Lowest salary */
float findLowest(float salaries[], int size)
{
    float lowest = salaries[0];
    for (int i = 1; i < size; i++)
        if (salaries[i] < lowest)
            lowest = salaries[i];
    return lowest;
}

/* 7. Linear search for a salary */
int searchSalary(float salaries[], int size, float target)
{
    for (int i = 0; i < size; i++)
        if (salaries[i] == target)
            return i;
    return -1;
}

/* 8. Bubble sort ascending */
void sortAscending(float salaries[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                float temp       = salaries[j];
                salaries[j]      = salaries[j + 1];
                salaries[j + 1]  = temp;
            }
        }
    }
}