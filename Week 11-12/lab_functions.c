#include <stdio.h>
#include "records.h"

// WEEK 12: The "Wrong" swap (Pass by Value)
void swapWrong(double a, double b) {
    double temp = a;
    a = b;
    b = temp;
    // This only changes the copies! The originals in main() are safe.
}

// WEEK 12: The "Right" swap (Pass by Address / Pointers)
void swapSalaries(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// WEEK 12: Pass array to function (acts as pointer)
void giveRaise(double salaries[], int n, double percent) {
    for (int i = 0; i < n; i++) {
        // Changes the ORIGINAL array because arrays are passed by address
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

// WEEK 12: Modify struct using pointer and arrow operator ->
void updateSalary(Employee *e, double newSalary) {
    e->salary = newSalary;
}

// WEEK 12: Find employee and return a pointer to them
Employee *findEmployee(Employee list[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i]; // Return the address of the found employee
        }
    }
    return NULL; // Not found
}

// WEEK 11: Display array of structs
void displayEmployees(Employee list[], int n) {
    printf("\n--- Employee Records ---\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %-5d | Name: %-10s | Dept: %-10s | Salary: N$%-10.2f | Hired: %02d/%02d/%d\n",
               list[i].id, list[i].name, list[i].department, list[i].salary, 
               list[i].hired.day, list[i].hired.month, list[i].hired.year);
    }
    printf("------------------------\n");
}