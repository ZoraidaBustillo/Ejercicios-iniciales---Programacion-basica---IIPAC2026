#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string nombreEmpleado;
    int edadEmpleado;
    int tipoEmpleado;
    int generoEmpleado;
    char continuar;

    double sueldoMensual;
    double horasSemanales;
    double horasMensuales;

    double sueldoHora;
    double sueldoMinuto;
    double sueldoSegundo;

    double sueldoSemanal;
    double sueldoQuincenal;

    double sueldoDiarioLV;
    double sueldoSabado;

    do
    {
        cout << "\n===================================" << endl;
        cout << "      PILLOFON S.A. DE C.V." << endl;
        cout << "===================================" << endl;

        cin.ignore(1000, '\n');

        cout << "Ingrese el nombre del empleado: ";
        getline(cin, nombreEmpleado);

        cout << "Ingrese la edad del empleado: ";
        cin >> edadEmpleado;

        while (edadEmpleado < 18 || edadEmpleado > 70)
        {
            cout << "Edad invalida. Ingrese una edad entre 18 y 70: ";
            cin >> edadEmpleado;
        }

        cout << "\nGENERO DEL EMPLEADO" << endl;
        cout << "1. Femenino" << endl;
        cout << "2. Masculino" << endl;
        cout << "Seleccione una opcion: ";
        cin >> generoEmpleado;

        while (generoEmpleado < 1 || generoEmpleado > 2)
        {
            cout << "Opcion invalida. Ingrese 1 o 2: ";
            cin >> generoEmpleado;
        }

        cout << "\nIngrese el sueldo mensual: L. ";
        cin >> sueldoMensual;

        while (sueldoMensual <= 16000)
        {
            cout << "El sueldo debe ser mayor a L.16,000.00: ";
            cin >> sueldoMensual;
        }

        cout << "\nTIPO DE EMPLEADO" << endl;
        cout << "1. Empleado de Planta" << endl;
        cout << "2. Empleado de Medio Tiempo" << endl;
        cout << "3. Empleado por Contrato" << endl;
        cout << "Seleccione una opcion: ";
        cin >> tipoEmpleado;

        while (tipoEmpleado < 1 || tipoEmpleado > 3)
        {
            cout << "Opcion invalida. Ingrese 1, 2 o 3: ";
            cin >> tipoEmpleado;
        }

        switch (tipoEmpleado)
        {
        case 1:
            horasSemanales = 53.5;
            break;

        case 2:
            horasSemanales = 33.0;
            break;

        case 3:
            cout << "Ingrese las horas semanales trabajadas: ";
            cin >> horasSemanales;

            if (horasSemanales < 30 || horasSemanales > 40)
            {
                cout << "\nERROR: horas fuera de rango permitido." << endl;

                cout << "\nDesea calcular otro empleado? (S/N): ";
                cin >> continuar;

            }
            break;
        }

        horasMensuales = horasSemanales * 4;

        sueldoHora = sueldoMensual / horasMensuales;
        sueldoMinuto = sueldoHora / 60;
        sueldoSegundo = sueldoMinuto / 60;

        sueldoSemanal = sueldoMensual / 4;
        sueldoQuincenal = sueldoMensual / 2;

        if (tipoEmpleado == 1)
        {
            sueldoDiarioLV = (sueldoHora * 47.5) / 5;
            sueldoSabado = sueldoHora * 6;
        }
        else
        {
            sueldoDiarioLV = sueldoSemanal / 6;
            sueldoSabado = sueldoDiarioLV;
        }

        cout << fixed << setprecision(2);

        cout << "\n\n========== REPORTE ==========" << endl;
        cout << "Nombre: " << nombreEmpleado << endl;
        cout << "Edad: " << edadEmpleado << endl;

        if (generoEmpleado == 1)
            cout << "Genero: Femenino" << endl;
        else
            cout << "Genero: Masculino" << endl;

        if (tipoEmpleado == 1)
            cout << "Tipo de Empleado: Planta" << endl;
        else if (tipoEmpleado == 2)
            cout << "Tipo de Empleado: Medio Tiempo" << endl;
        else
            cout << "Tipo de Empleado: Contrato" << endl;

        cout << "Sueldo Mensual: L. " << sueldoMensual << endl;
        cout << "Horas Semanales: " << horasSemanales << endl;
        cout << "Horas Mensuales: " << horasMensuales << endl;

        cout << "\n1. Sueldo diario (Lunes a Viernes):  L. " << sueldoDiarioLV << endl;
        cout << "2. Sueldo del Sabado:                  L. " << sueldoSabado << endl;
        cout << "3. Sueldo por Hora:                    L. " << sueldoHora << endl;
        cout << "4. Sueldo por Minuto:                  L. " << sueldoMinuto << endl;
        cout << "5. Sueldo por Segundo:                 L. " << sueldoSegundo << endl;
        cout << "6. Sueldo Semanal (Lunes a Viernes):   L. " << sueldoSemanal << endl;
        cout << "7. Sueldo Semanal (Lunes a Sabado):    L. " << sueldoSemanal << endl;
        cout << "8. Sueldo Quincenal:                   L. " << sueldoQuincenal << endl;
        cout << "9. Horas Trabajadas Totales: " << horasMensuales << endl;

        cout << "\nDesea calcular otro empleado?" " \n (1. Si / 2. No): ";
        cin >> continuar;

    } while (continuar == 1);

    cout << "\nGracias por utilizar el sistema." << endl;

    return 0;
}