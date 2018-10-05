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
    printf("\nIngrese el nombre: ");
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
    int sector;
    int i;
    int j;
    int comparacion;

    switch (order)
    {
    case 1:
        for (i=0; i<len; i++)
        {
            if (list[i].isEmpty == 1)
            {
               for (j=i+1; j<len; j++)
               {
                  comparacion=strcmp(list[i].lastName, list[j].lastName);
                    if (comparacion < 0)
                    {
                        empleado=list[j];
                        list[j]=list[i];
                        list[i]=empleado;
                    }
               }
               break;
            }
        }
        break;

    case 2:
        for (i=0; i<len; i++)
        {
            if (list[i].isEmpty == 1)
            {
               for (j=i+1; j<len; j++)
               {
                  comparacion=strcmp(list[i].lastName, list[j].lastName);
                    if (comparacion > 0)
                    {
                        empleado=list[i];
                        list[i]=list[j];
                        list[j]=empleado;
                    }
               }
               break;
            }
        }
        break;

    case 3:
        for (i=0; i<len; i++)
        {
            if (list[i].isEmpty == 1)
            {
                for (j=i+1; j<len; j++)
                {
                    if (list[i].sector < list[j].sector)
                    {
                        sector=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=sector;

                    }
                }
            }
        }
        break;
    case 4:
        for (i=0; i<len; i++)
        {
            if (list[i].isEmpty == 1)
            {
                for (j=i+1; j<len; j++)
                {
                    if (list[i].sector > list[j].sector)
                    {
                        sector=list[j].sector;
                        list[j].sector=list[i].sector;
                        list[i].sector=sector;
                    }
                }
            }
            break;
        }
    }
    printEmployees(list, len);
    return 0;
}

int printEmployees(Employee* list, int length)
{
    int i;
    int flag=0;

    printf("\nApellido -- Nombre -- Id -- Salario -- Sector\n");

    for (i=0; i<length; i++)
    {
        if (list[i].isEmpty == 1)
        {
            printf("%s -- %s -- %d -- %.2f -- %d \n", list[i].lastName, list[i].name, list[i].id, list[i].salary, list[i].sector);

        }
    }

    return 0;
}

void modificarEmployees (Employee* list, int len, int id)
{
    int opcion;
    int i;

    opcion=menuModificar();

    for (i=0; i<len; i++)
    {
        if (id == list[i].id)
        {
            switch(opcion)
            {
            case 1:
                printf("Ingrese el nombre: ");
                fflush(stdin);
                gets(list[i].name);
                break;
            case 2:
                printf("Ingrese el apellido: ");
                fflush(stdin);
                gets(list[i].lastName);
                break;
            case 3:
                printf("Ingrese el salario: ");
                fflush(stdin);
                scanf("%f", &list[i].salary);
                break;
            case 4:
                printf("Ingrese el sector: ");
                fflush(stdin);
                scanf("%d", &list[i].sector);
                break;
            }

        }else
        {
            printf("\nNo hay un empleado asignado con ese id");
        }
        break;
    }


}

int menuModificar ()
{
  int opcion;

    printf("\n1. NOMBRE\n");
    printf("2. APELLIDO\n");
    printf("3. SALARIO\n");
    printf("4. SECTOR\n");

  do
  {
    printf("Elija la opcion que desea modificar: ");
    scanf("%d", &opcion);
  }while (!(opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4));

    return opcion;
}

float promedioSalario(Employee* list, int len)
{
    int contador=0;
    float promedio=0;
    float acumulador=0;
    int i;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty == 1)
        {
            acumulador=acumulador+list[i].salary;
            contador++;
        }
    }
    promedio = acumulador/contador;
    printf("El total de los salarios es: %f\n", &acumulador);
    printf("El promedio de los salarios es: %f\n", &promedio);

    return promedio;
}

void superanPromedio (Employee* list, int len, float promedio)
{
    int contador=0;
    int i;
    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty == 1)
        {
            if (list[i].salary > promedio)
            {
                contador++;
            }
        }
    }
    printf("%d superan el promedio de sueldos", &contador);
}

