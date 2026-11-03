#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

// Start with room for 2 employees
void initList(EmployeeList *list) {
    list->capacity = 2;
    list->count = 0;
    list->array = (Employee *)malloc(list->capacity * sizeof(Employee));
    
    if (list->array == NULL) {
        printf("Fatal Error: Out of memory!\n");
        exit(1);
    }
}

void addEmployee(EmployeeList *list, int id, const char* name, double salary) {
    // 1. Check if we need to grow
    if (list->count == list->capacity) {
        int newCapacity = list->capacity * 2;
        
        // THE SAFE WAY TO REALLOC (using a temporary pointer)
        Employee *bigger = (Employee *)realloc(list->array, newCapacity * sizeof(Employee));
        
        if (bigger == NULL) {
            printf("Fatal Error: Could not resize memory!\n");
            freeList(list); // Clean up what we have before dying
            exit(1);
        }
        
        list->array = bigger;
        list->capacity = newCapacity;
        printf("[System: Memory grown to %d slots]\n", list->capacity);
    }

    // 2. Add the employee
    list->array[list->count].id = id;
    strcpy(list->array[list->count].name, name);
    list->array[list->count].salary = salary;
    list->count++;
}

void displayEmployees(EmployeeList *list) {
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < list->count; i++) {
        printf("ID: %-5d | Name: %-15s | Salary: N$%.2f\n", 
               list->array[i].id, list->array[i].name, list->array[i].salary);
    }
    printf("-----------------------\n");
    printf("Total Employees: %d | Capacity: %d\n", list->count, list->capacity);
}

// WEEK 13 TODO: ALWAYS free the memory!
void freeList(EmployeeList *list) {
    free(list->array);
    list->array = NULL;
    list->count = 0;
    list->capacity = 0;
}