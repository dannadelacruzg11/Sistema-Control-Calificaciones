// Sistema de control de calificaciones de un centro educativo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int cantidadEstudiantes; 
    int aprobados = 0;
    int reprobados = 0;
    string nombreEstudiante;
    double calificacion;
    double sumaNotas;
    double promedio;
    double sumaPromedios = 0;
    double promedioGrupo; 
    double promedioMayor = -1;
    string mejorEstudiante;
    char respuesta;

    // Uso esto para que los promedios salgan con dos numeros despues del punto. 
    cout << fixed << setprecision(2);

    //Este bucle permite registrar otro grupo  sin tener que volver a abrir el programa. 
    do {
        // Reinicia los datosnpara comenzar un grupo nuevo. 
        aprobados = 0;
        reprobados = 0;
        sumaPromedios = 0;
        promedioMayor = -1;
        mejorEstudiante = "";


        cout << "Ingrese la cantidad de estudiantes: ";
        cin >> cantidadEstudiantes;
        // Este bucle verifica que la cantidad de estudiantes sea mayor que 0.
        while (cantidadEstudiantes <= 0) {
            cout << "Cantidad invalida. Intente nuevamente: ";
            cin >> cantidadEstudiantes;
        }
        //Este bucle permite registrar a cada estudiante dependiendo la cantidad indicada por el usuario. 
        for (int i = 1; i <= cantidadEstudiantes; i++) {
            cout << "Ingrese el nombre del estudiante " << i << ": ";
            cin >> nombreEstudiante;
            sumaNotas = 0;
            // Este bucle solicita las cautro calificaciones correspondientes a cada estudiante.  
            for (int j = 1; j <= 4; j++) {
                cout << "Ingrese la calificacion " << j << ": ";
                cin >> calificacion;
                // Este bucle while verifica que cada nota este entre 0 y 100. Si no, la vuelve a pedir. 
                while (calificacion < 0 || calificacion > 100) {
                    cout << "Calificacion invalida. Intente nuevamente: ";
                    cin >> calificacion;

                }
                sumaNotas += calificacion;
            }
            promedio = sumaNotas / 4;
            sumaPromedios += promedio;

            if (promedio > promedioMayor) {
                promedioMayor = promedio;
                mejorEstudiante = nombreEstudiante;
            }

            cout << "Promedio: " << promedio << endl;

            if (promedio >= 70) {
                aprobados++;
                cout << "Aprobado" << endl;
            }
            else {
                reprobados++;
                cout << "Reprobado" << endl;
            }

        }
        promedioGrupo = sumaPromedios / cantidadEstudiantes;

        cout << "==========================================" << endl;
        cout << "        RESUMEN GENERAL DEL GRUPO         " << endl;
       

        cout << "Total de estudiantes: "
             << cantidadEstudiantes << endl;

        cout << "Promedio general del grupo. "
             << promedioGrupo << endl;

        cout << "Estudiante con mayor promedio: "
             << mejorEstudiante << endl;

        cout << "Promedio mas alto: "
             << promedioMayor << endl;

        cout << "Aprobados: " << aprobados << endl;
        cout << "Reprobados: " << reprobados << endl;

        cout << "=========================================" << endl;

        cout << "Desea registrar otro grupo? (s/n): ";
        cin >> respuesta;
        // Este bucle solicita una respuesta valida para asi termina o continuar el programa. 
    } while (respuesta == 's' || respuesta == 'S');

    cout << "GRACIAS POR UTILIZAR EL SISTEMA.";

    return 0;
}