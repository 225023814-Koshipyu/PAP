#include <stdio.h>
#include "file_handler.h"
#include "employee.h"

// WEEK 10: SAVE TO TEXT FILE (using fprintf)
void saveDataText(void) {
    FILE *fp = fopen("data/employees.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not create text file.\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        // Save as: ID|Name|Salary
        fprintf(fp, "%d|%s|%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    fclose(fp);
    printf("Saved %d records to text file (data/employees.txt).\n", employeeCount);
}

// WEEK 10: LOAD FROM TEXT FILE (using fscanf)
void loadDataText(void) {
    FILE *fp = fopen("data/employees.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not find text file.\n");
        return;
    }

    clearEmployees(); // Empty the array before loading
    int id;
    char name[NAME_LEN];
    double salary;
    int count = 0;

    // Parse the pipe-delimited format
    while (fscanf(fp, "%d|%49[^|]|%lf\n", &id, name, &salary) == 3) {
        addEmployee(id, name, salary);
        count++;
    }
    fclose(fp);
    printf("Loaded %d records from text file.\n", count);
}

// WEEK 10: SAVE TO BINARY FILE (using fwrite)
void saveDataBinary(void) {
    FILE *fp = fopen("data/employees.dat", "wb");
    if (fp == NULL) {
        printf("Error: Could not create binary file.\n");
        return;
    }

    // Write the whole array at once
    fwrite(employees, sizeof(Employee), employeeCount, fp);
    fclose(fp);
    printf("Saved %d records to binary file (data/employees.dat).\n", employeeCount);
}

// WEEK 10: LOAD FROM BINARY FILE (using fread)
void loadDataBinary(void) {
    FILE *fp = fopen("data/employees.dat", "rb");
    if (fp == NULL) {
        printf("Error: Could not find binary file.\n");
        return;
    }

    clearEmployees();
    int count = 0;

    // Read one Employee struct at a time
    while (fread(&employees[count], sizeof(Employee), 1, fp) == 1) {
        count++;
    }
    employeeCount = count;
    fclose(fp);
    printf("Loaded %d records from binary file.\n", count);
}