#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define CANTIDAD 1000
#define OCUPADO 1
#define ELIMINADO -1
#define VACIO 0

int main()
{
    Employee listaEmpleados [CANTIDAD];
    int opcion;

    int auxInit;
    int auxAdd;
    int auxFind;
    int auxRemove;
    int auxPrint;

    char auxName[51];
    char auxLastName[51];
    int auxId;
    float auxSalary;
    int auxSector;


    auxInit = initEmployees(listaEmpleados, CANTIDAD);

    do
    {
    printf("\n1- ALTA. Ingresar los empleados \n");
    printf("2- MODIFICACION. Modificar datos de empleados \n");
    printf("3- BAJA. Eliminar empleados \n");
    printf("4- SALIR \n");

    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            auxAdd = addEmployees(listaEmpleados,CANTIDAD,auxId,auxName,auxLastName,auxSalary,auxSector);
            break;

        case 2:
            printf("Ingrese el numero de id del empleado que desea buscar: ");
            scanf("%d", &auxId);
            auxFind = findEmployeeById(listaEmpleados, CANTIDAD, auxId);
            break;

        case 3:
            printf("Ingrese el numero de id del empleado que desea eliminar: ");
            scanf("%d", &auxId);
            auxRemove=removeEmployee(listaEmpleados, CANTIDAD, auxId);
            break;

        case 4:
            auxPrint=printEmployees(listaEmpleados, CANTIDAD);

            break;
        case 5:
            break;
        }

        } while (opcion != 1 || opcion != 2 || opcion != 3 || opcion != 4);



    return 0;
}
