#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int año;
    float gpa;
    float presupuesto;
};

// Calcular indice universidad
float indiceU(Estudiante e) {
    return abs(e.gpa - 3) * e.presupuesto;
}

// Ingresar datos
Estudiante leerEstudiante() {
    Estudiante e;

    cout << "Nombre: ";
    cin >> e.nombre;
    cout << "Año de nacimiento: ";
    cin >> e.año;
    cout << "GPA: ";
    cin >> e.gpa;
    cout << "Presupuesto: ";
    cin >> e.presupuesto;

    return e;
}

// Mostrar estudiantes
void mostrar(vector<Estudiante>& v) {
    if (v.empty()) {
        cout << "No hay estudiantes.\n";
        return;
    }

    for (int i = 0; i < (int)v.size(); i++) {
        cout << "\nIndice: " << i;
        cout << "\nNombre: " << v[i].nombre;
        cout << "\nNacimiento: " << v[i].año;
        cout << "\nGPA: " << v[i].gpa;
        cout << "\nPresupuesto: " << v[i].presupuesto;
        cout << "\nIndice universidad: " << indiceU(v[i]);
        cout << "\n";
    }
}

int main() {

    vector<Estudiante> estudiantes;
    int op, tipo, modo, pos;

    do {
        cout << "\n===== MENU ESTUDIANTES =====\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Actualizar\n";
        cout << "4. Ordenar\n";
        cout << "5. Imprimir\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> op;

        switch (op) {

        case 1: {
            Estudiante e = {"NN", 0, 0, 0};

            cout << "1. Por defecto\n";
            cout << "2. Con datos\n";
            cin >> tipo;

            if (tipo == 2)
                e = leerEstudiante();
            else if (tipo != 1) {
                cout << "Opcion invalida\n";
                break;
            }

            cout << "1. Insertar al final\n";
            cout << "2. Insertar por indice\n";
            cin >> modo;

            if (modo == 1) {
                estudiantes.push_back(e);
                cout << "Insertado correctamente\n";
            }
            else if (modo == 2) {
                cout << "Indice: ";
                cin >> pos;

                if (pos >= 0 && pos <= (int)estudiantes.size()) {
                    estudiantes.insert(estudiantes.begin() + pos, e);
                    cout << "Insertado correctamente\n";
                }
                else
                    cout << "Indice invalido\n";
            }
            else
                cout << "Opcion invalida\n";

            break;
        }

        case 2: {
            if (estudiantes.empty()) {
                cout << "No hay estudiantes para eliminar\n";
                break;
            }

            cout << "1. Eliminar ultimo\n";
            cout << "2. Eliminar por indice\n";
            cin >> modo;

            if (modo == 1) {
                estudiantes.pop_back();
                cout << "Eliminado correctamente\n";
            }
            else if (modo == 2) {
                cout << "Indice: ";
                cin >> pos;

                if (pos >= 0 && pos < (int)estudiantes.size()) {
                    estudiantes.erase(estudiantes.begin() + pos);
                    cout << "Eliminado correctamente\n";
                }
                else
                    cout << "Indice invalido\n";
            }
            else
                cout << "Opcion invalida\n";

            break;
        }

        case 3: {
            if (estudiantes.empty()) {
                cout << "No hay estudiantes\n";
                break;
            }

            mostrar(estudiantes);

            cout << "\nIndice a actualizar: ";
            cin >> pos;

            if (pos >= 0 && pos < (int)estudiantes.size()) {
                estudiantes[pos] = leerEstudiante();
                cout << "Actualizado correctamente\n";
            }
            else
                cout << "Indice invalido\n";

            break;
        }

        case 4: {
            if (estudiantes.empty()) {
                cout << "No hay estudiantes\n";
                break;
            }

            cout << "1. Por nacimiento\n";
            cout << "2. Por GPA\n";
            cout << "3. Por presupuesto\n";
            cout << "4. Por indice universidad\n";
            cin >> tipo;

            if (tipo < 1 || tipo > 4) {
                cout << "Opcion invalida\n";
                break;
            }

            sort(estudiantes.begin(), estudiantes.end(),
                [tipo](Estudiante a, Estudiante b) {
                    if (tipo == 1)
                        return a.año < b.año;
                    if (tipo == 2)
                        return a.gpa < b.gpa;
                    if (tipo == 3)
                        return a.presupuesto < b.presupuesto;

                    return indiceU(a) < indiceU(b);
                });

            cout << "Ordenado correctamente\n";
            break;
        }

        case 5:
            mostrar(estudiantes);
            break;

        case 0:
            cout << "Fin del programa\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (op != 0);

    return 0;
}