//Uzair Jawaid
//2018-12-24
//employee management console application

#include <stdio.h>
#include <stdlib.h>

//define a structure of type employee
typedef struct
{
    int employeeID;
    char firstName[16];
    char lastName[16];
    float wage;
    float hoursWorked;
    float pay;
}Employee;

//this function will generate a list of employees from a textfile and return a pointer to it
Employee **createList(char fileName, int *size)
{
    //read the file
    File *list = fopen(fileName, "r");
    //get the size of the text file ie.number of lines and store it in size
    fscanf(list, %d, size);

    //creates an object of type employee and allocates memory for every employee in the list from the textfile
    Employee **employeeList = calloc(*size, sizeof(Employee*));

    for(int i = 0; i < *size; i++)
    {
        //allocate memory for current employee and cast to type Employee*
        employeeList[i] = (Employee*)malloc(sizeof(Employee));

        //from file instantiate fixed values for the employee
        fscanf(list, %d %s %s %d, &(employeeList[i]->employeeID), employeeList[i]->firstName, employeeList[i]->lastName));
        employeeList[i]->hoursWorked = 0;
        employeeList[i]->pay = 0;
    }

    //close file
    fclose(list);

    //return the memory location of the employee list
    return employeeList;
}//end function

int main()
{
    //workspace
    return 0;
}
