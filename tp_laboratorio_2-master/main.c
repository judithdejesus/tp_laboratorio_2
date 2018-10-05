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

    /*int auxInit;
    int auxAdd;
    int auxFind;
    int auxRemove;
    int auxPrint;
    int auxSort;*/
    float muestra;
    int mostrar;

    char auxName[51];
    char auxLastName[51];
    int auxId;
    float auxSalary;
    int auxSector;


    mostrar = initEmployees(listaEmpleados, CANTIDAD);

    do
    {
    printf("\n1- ALTA. Ingresar los empleados \n");
    printf("2- MODIFICACION. Modificar datos de empleados \n");
    printf("3- BAJA. Eliminar empleados \n");
    printf("4- INFORMAR \n");
    printf("5- SALIR \n");

    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            mostrar = addEmployees(listaEmpleados,CANTIDAD,auxId,auxName,auxLastName,auxSalary,auxSector);
            break;

        case 2:
            printf("Ingrese el id del empleado que desea modificar: ");
            scanf("%d", &auxId);
            modificarEmployees(listaEmpleados, CANTIDAD, auxId);
            /*printf("Ingrese el numero de id del empleado que desea buscar: ");
            scanf("%d", &auxId);
            auxFind = findEmployeeById(listaEmpleados, CANTIDAD, auxId);*/
            break;

        case 3:
            printf("Ingrese el numero de id del empleado que desea eliminar: ");
            scanf("%d", &auxId);
            mostrar = removeEmployee(listaEmpleados, CANTIDAD, auxId);
            break;

        case 4:
            //auxPrint=printEmployees(listaEmpleados, CANTIDAD);
            printf("1.DESCENDETE - APELLIDO \n");
            printf("2.ASCENDENTE - APELLIDO \n");
            printf("3.DESCENDENTE - SECTOR \n");
            printf("4.ASCENDENTE - SECTOR \n");

            do
            {
                printf("Ingrese en que orden quiere el ordenamiento: ");
                scanf("%d", &opcion);
            }while (!(opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4));

            mostrar = sortEmployees(listaEmpleados, CANTIDAD, opcion);
            muestra = promedioSalario(listaEmpleados, CANTIDAD);
            superanPromedio(listaEmpleados, CANTIDAD, muestra);

            break;
        case 5:
            printf("Saliendo del programa \n");
            break;
        }
        system("pause");
        system("cls");

        } while (opcion != 1 || opcion != 2 || opcion != 3 || opcion != 4 || opcion != 5);

    return 0;
}
