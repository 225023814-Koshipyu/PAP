#include <stdio.h>

#define EMPLOYEES 50

int main(void)
{
    float salary;
    float total   = 0.0f;
    float highest = 0.0f;
    float lowest  = 0.0f;
    float average;

    for (int i = 1; i <= EMPLOYEES; i++) {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

        total += salary;

        if (i == 1) {
            highest = salary;
            lowest  = salary;
        }

        if (salary > highest) highest = salary;
        if (salary < lowest)  lowest  = salary;
    }

    average = total / EMPLOYEES;

    printf("\n--- Salary Report ---\n");
    printf("Total salary:   %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary:  %.2f\n", lowest);

    return 0;
}