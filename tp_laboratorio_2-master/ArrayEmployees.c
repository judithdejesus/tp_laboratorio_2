#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees (Employee* list, int len)
{
    int i;
    int vacio = 0;
    for (i=0; i<len; i++)
    {
       list[i].isEmpty = vacio;
    }
    return vacio;
}


int findSpace (Employee* list, int len)
{
    int indice = -1;
    int i;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int generarId ()
{
    static int id=0;
    id++;
    return id;

}

Employee loadEmployee (Employee* list)
{
    Employee empleado;

    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(empleado.name);

    printf("\nIngrese el apellido: ");
    fflush(stdin);
    gets(empleado.lastName);

    printf("\nIngrese el salario: ");
    fflush(stdin);
    scanf("%f", &empleado.salary);

    printf("\nIngrese el sector: ");
    fflush(stdin);
    scanf("\n%d", &empleado.sector);

    empleado.id = generarId();

    empleado.isEmpty = 1;

    return empleado;
}

int addEmployees (Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int indice;
    int encontro = 0;

    indice = findSpace(list, len);

    if (indice != -1)
    {
        list[indice] = loadEmployee(list);
        encontro = -1;
    }
    return encontro;
}

int findEmployeeById(Employee* list, int len, int id)
{
    int i;
    for (i=0; i<len; i++)
    {
        if (list[i].id == id)
        {
            printf("%s -- %s -- %.2f -- %d", list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            break;
        }else
        {
            printf("No hay un empleado con ese id");
        }
    }
    return NULL;
}

int removeEmployee(Employee* list, int len, int id)
{
    int i;
    for (i=0; i<len; i++)
    {
        if (list[i].id == id)
        {
            list[i].isEmpty == -1;
            break;
        }else
        {
            printf("No hay un empleado con ese id");
        }
    }
    return -1;

}

int sortEmployees(Employee* list, int len, int order)
{
    Employee empleado;
    int i;
    int j;
    int comparacion;

    for (i=0; i<len; i++)
    {
        for (j=i+1; i<len; i++)
        {
            comparacion=stricmp(list[i].lastName, list[j].lastName);
            if (comparacion < 0)
            {
                empleado=list[j].lastName;
            }
        }
    }

    return 0;
}

int printEmployees(Employee* list, int length)
{
    int i;
    int flag=0;

    printf("\nNombre -- Apellido -- Id -- Salario -- Sector\n");

    for (i=0; i<length; i++)
    {
        if (list[i].isEmpty == 1)
        {
            printf("%s -- %s -- %d -- %.2f -- %d \n", list[i].name, list[i].lastName, list[i].id, list[i].salary, list[i].sector);

        }
    }

    return 0;
}


