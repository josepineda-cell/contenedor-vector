
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

// CLASE ESTUDIANTE
class Estudiante {
private:
    string nombre;
    int año;
    float gpa, presupuesto;

public:
    // Constructor
    Estudiante(string n = "NN", int a = 0,
               float g = 0, float p = 0) {
        nombre = n;
        año = a;
        gpa = g;
        presupuesto = p;
    }

    // Ingresar datos
    void leer() {
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Año de nacimiento: ";
        cin >> año;
        cout << "GPA: ";
        cin >> gpa;
        cout << "Presupuesto: ";
        cin >> presupuesto;
    }

    // Getters
    int getAño() const { return año; }
    float getGpa() const { return gpa; }
    float getPresupuesto() const { return presupuesto; }

    // Calcular indice universidad
    float indiceU() const {
        return abs(gpa - 3) * presupuesto;
    }

    // Mostrar datos
    void mostrar(int pos) const {
        cout << "\nIndice: " << pos;
        cout << "\nNombre: " << nombre;
        cout << "\nAño de nacimiento: " << año;
        cout << "\nGPA: " << gpa;
        cout << "\nPresupuesto: " << presupuesto;
        cout << "\nIndice universidad: " << indiceU();
        cout << "\n";
    }
};

// CLASE SISTEMA ESTUDIANTES
class SistemaEstudiantes {
private:
    vector<Estudiante> estudiantes;

public:
    int cantidad() const {
        return estudiantes.size();
    }

    // INSERTAR AL FINAL
    void insertarFinal(Estudiante e) {
        estudiantes.push_back(e);
    }

    // INSERTAR POR INDICE
    bool insertarIndice(int pos, Estudiante e) {
        if (pos < 0 || pos > cantidad())
            return false;

        estudiantes.insert(estudiantes.begin() + pos, e);
        return true;
    }

    // ELIMINAR ULTIMO
    bool eliminarUltimo() {
        if (estudiantes.empty())
            return false;

        estudiantes.pop_back();
        return true;
    }

    // ELIMINAR POR INDICE
    bool eliminarIndice(int pos) {
        if (pos < 0 || pos >= cantidad())
            return false;

        estudiantes.erase(estudiantes.begin() + pos);
        return true;
    }

    // ACTUALIZAR
    bool actualizar(int pos, Estudiante e) {
        if (pos < 0 || pos >= cantidad())
            return false;

        estudiantes[pos] = e;
        return true;
    }

    // ORDENAR
    bool ordenar(int tipo) {
        if (tipo < 1 || tipo > 4)
            return false;

        sort(estudiantes.begin(), estudiantes.end(),
            [tipo](Estudiante a, Estudiante b) {
                if (tipo == 1)
                    return a.getAño() < b.getAño();

                if (tipo == 2)
                    return a.getGpa() < b.getGpa();

                if (tipo == 3)
                    return a.getPresupuesto() < b.getPresupuesto();

                return a.indiceU() < b.indiceU();
            });

        return true;
    }

    // IMPRIMIR
    void imprimir() const {
        if (estudiantes.empty()) {
            cout << "Vector vacio.\n";
            return;
        }

        for (int i = 0; i < cantidad(); i++)
            estudiantes[i].mostrar(i);
    }
};

// FUNCION PRINCIPAL
int main() {

    SistemaEstudiantes sistema;
    int op, tipo, modo, pos;

    do {
        cout << "\n===== MENU ESTUDIANTES =====\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Actualizar\n";
        cout << "4. Ordenar\n";
        cout << "5. Imprimir\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op) {

        case 1: {
            Estudiante e;

            cout << "1. Por defecto\n";
            cout << "2. Con datos\n";
            cin >> tipo;

            if (tipo == 2)
                e.leer();
            else if (tipo != 1) {
                cout << "Opcion invalida\n";
                break;
            }

            cout << "1. Al final\n";
            cout << "2. Por indice\n";
            cin >> modo;

            if (modo == 1) {
                sistema.insertarFinal(e);
                cout << "Insertado correctamente\n";
            }
            else if (modo == 2) {
                cout << "Indice: ";
                cin >> pos;

                if (sistema.insertarIndice(pos, e))
                    cout << "Insertado correctamente\n";
                else
                    cout << "Indice invalido\n";
            }
            else
                cout << "Opcion invalida\n";

            break;
        }

        case 2: {
            if (sistema.cantidad() == 0) {
                cout << "Vector vacio. No se puede eliminar\n";
                break;
            }

            cout << "1. Eliminar ultimo\n";
            cout << "2. Eliminar por indice\n";
            cin >> modo;

            if (modo == 1) {
                sistema.eliminarUltimo();
                cout << "Eliminado correctamente\n";
            }
            else if (modo == 2) {
                cout << "Indice: ";
                cin >> pos;

                if (sistema.eliminarIndice(pos))
                    cout << "Eliminado correctamente\n";
                else
                    cout << "Indice invalido\n";
            }
            else
                cout << "Opcion invalida\n";

            break;
        }

        case 3: {
            if (sistema.cantidad() == 0) {
                cout << "Vector vacio\n";
                break;
            }

            sistema.imprimir();

            cout << "\nIndice a actualizar: ";
            cin >> pos;

            if (pos < 0 || pos >= sistema.cantidad()) {
                cout << "Indice invalido\n";
                break;
            }

            Estudiante e;
            e.leer();

            sistema.actualizar(pos, e);
            cout << "Actualizado correctamente\n";
            break;
        }

        case 4: {
            if (sistema.cantidad() == 0) {
                cout << "Vector vacio\n";
                break;
            }

            cout << "1. Por año de nacimiento\n";
            cout << "2. Por GPA\n";
            cout << "3. Por presupuesto\n";
            cout << "4. Por indice universidad\n";
            cin >> tipo;

            if (sistema.ordenar(tipo))
                cout << "Ordenado correctamente\n";
            else
                cout << "Opcion invalida\n";

            break;
        }

        case 5:
            sistema.imprimir();
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
