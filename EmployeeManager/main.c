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
    FILE *list = fopen(fileName, "r");
    //get the size of the text file ie.number of lines and store it in size
    fscanf(list, "%d", size);

    //creates an object of type employee and allocates memory for every employee in the list from the textfile
    Employee **employeeList = calloc(*size, sizeof(Employee*));

    for(int i = 0; i < *size; i++)
    {
        //allocate memory for current employee and cast to type Employee*
        employeeList[i] = (Employee*)malloc(sizeof(Employee));

        //from file instantiate fixed values for the employee
        fscanf(list, "%d %s %s", &(employeeList[i]->employeeID), employeeList[i]->firstName, employeeList[i]->lastName);
        employeeList[i]->wage = 0;
        employeeList[i]->hoursWorked = 0;
        employeeList[i]->pay = 0;
    }

    //close file
    fclose(list);

    //return the memory location of the employee list
    return employeeList;
}//end function

//find the id of an employee in the list and return their index position
int find(int idNo, Employee** list, int size)
{
    //loop through list
    for(int i = 0; i < size; i++)
    {
        if(list[i] == idNo)
        {
            return i;
        }
        else
        {
            printf("ID not found.");
            return -1;
        }
    }
}//end of function

//upload paystub information from textfile
void payStatus(char *fileName, Employee** list, int size)
{
    //open textfile to read from it
    FILE* paystub = fopen(fileName, "r");

    //variable to store the id
    int id, rate, hours;

    //format:
    //ID - wage - hoursWorked
    for(int i = 0; i < size; i++)
    {
        //read a line from the text and calls the find function to locate the employee in the list with their id
        //and assign the correct wage and hours
        fscanf(paystub , "%d %f %f", &id, &rate, &hours);
        int index = find(id,list,size);
        if(index == -1)
        {
            continue;
        }
        else
        {
            list[index]->wage = rate;
            list[index]->hoursWorked = hours;
        }
    }//end loop
    fclose(paystub);
}//end function

//compute the pay for each employee in the list
void computePay(Employee** list,int size)
{
    //loop through list
    for(int i = 0; i < size; i++)
    {
        //Calculate the employees pay
        list[i]->pay = (list[i]->hoursWorked)*(list[i]->wage);
    }//end loop
}//end function

//outputs the list of payments for each employee
float amountPaid(Employee **list, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d : %f", list[i]->employeeID, list[i]->pay);
    }
}

//function to print the whole list
void printList(Employee** list, int size)
{
    //loop through list
    for(int i = 0; i < size; i++)
    {
        printf("%d - %s %s : %f", list[i]->employeeID, list[i]->firstName, list[i]->lastName, list[i]->pay);
    }
}

//function to remove an employee from the list
void withdraw(Employee **list, int size, int id)
{
    //get index of employee
    int employee = find(id, list, size);
    //deallocate the memory
    free(list[employee]);

    //shift all employees from list up after the removed employee
    for (int i = employee; i < size-1; i++)
    {
        list[i+1] = list[i];
    }
}

int main()
{
    //workspace
    return 0;
}
