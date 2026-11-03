#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

// The dynamic memory manager
typedef struct {
    Employee *array; // Pointer to the heap
    int count;       // How many slots are used
    int capacity;    // How many slots exist
} EmployeeList;

void initList(EmployeeList *list);
void addEmployee(EmployeeList *list, int id, const char* name, double salary);
void displayEmployees(EmployeeList *list);
void freeList(EmployeeList *list);

#endif