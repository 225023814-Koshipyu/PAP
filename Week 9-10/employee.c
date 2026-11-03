#include <stdio.h>
#include <string.h>
#include "employee.h"

// Define the global variables here
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee(int id, const char* name, double salary) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Error: Employee list is full!\n");
        return;
    }
    employees[employeeCount].id = id;
    strcpy(employees[employeeCount].name, name);
    employees[employeeCount].salary = salary;
    employeeCount++;
    printf("Employee added successfully.\n");
}

void displayEmployees(void) {
    if (employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("ID: %-5d | Name: %-20s | Salary: N$%.2f\n", 
               employees[i].id, employees[i].name, employees[i].salary);
    }
}

void clearEmployees(void) {
    employeeCount = 0;
    printf("Memory cleared.\n");
}