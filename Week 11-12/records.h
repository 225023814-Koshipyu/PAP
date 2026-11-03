#ifndef RECORDS_H
#define RECORDS_H

#define MAX_EMPLOYEES 50

// Nested Date structure
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Employee structure
typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
    Date hired; // Nested structure
} Employee;

// Function prototypes
void swapWrong(double a, double b);
void swapSalaries(double *a, double *b);
void giveRaise(double salaries[], int n, double percent);
void updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int n, int id);
void displayEmployees(Employee list[], int n);

#endif