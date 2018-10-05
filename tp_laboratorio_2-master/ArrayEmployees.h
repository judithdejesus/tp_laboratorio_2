typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

int initEmployees (Employee*, int);
int addEmployees (Employee*, int, int, char[], char[], float, int);
int findSpace (Employee*, int);
Employee loadEmployee (Employee*);
int generarId ();
int findEmployeeById(Employee*, int, int);
int removeEmployee(Employee*, int, int);
int sortEmployees(Employee*, int , int);
int printEmployees(Employee*, int);
void modificarEmployees (Employee*, int, int);
int menuModificar ();
float promedioSalario(Employee*, int);
void superanPromedio (Employee*, int, float);
