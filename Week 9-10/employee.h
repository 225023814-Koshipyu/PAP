#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_EMPLOYEES 50
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    double salary;
} Employee;

// Global variables (defined in employee.c)
extern Employee employees[MAX_EMPLOYEES];
extern int employeeCount;

// Function prototypes
void addEmployee(int id, const char* name, double salary);
void displayEmployees(void);
void clearEmployees(void);

#endif