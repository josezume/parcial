#include <iostream>
#include <fstream>
#include <stdexcept>
#include <numeric>
#include <string>

using namespace std;

int main() {
    try {
        int suma = 0;
        int cantidad = 0;
        string entrada;

        while (true) {
            cout << "Ingrese un numero o 'fin' para terminar: ";
            cin >> entrada;

            if (entrada == "fin") {
                break;
            }

            try {
                int num = stoi(entrada);
                suma += num;
                cantidad++;
            }
            catch (const invalid_argument& e) {
                cerr << "Entrada inválida. Se esperaba un número entero o 'fin'." << endl;
                continue;
            }
        }

        if (cantidad == 0) {
            cout << "No se ingresó ningún número." << endl;
            return 0;
        }

        double promedio = static_cast<double>(suma) / cantidad;

        ofstream out("resultados.txt");
        if (!out.is_open()) {
            throw runtime_error("Error: no se pudo abrir el archivo 'resultados.txt' para escribir.");
        }
        out << "Suma: " << suma << endl;
        out << "cantidad: " << cantidad << endl;
        out << "promedio: " << promedio << endl;
        out.close();

        cout << "\nProceso completado. Los resultados se han escrito en 'resultados.txt'." << endl;

        ifstream in("resultados.txt");
        if (!in.is_open()) {
            throw runtime_error("Error: no se pudo abrir el archivo 'resultados.txt' para lectura.");
        }
        cout << "\nContenido de resultados.txt:" << endl;
        string linea;
        while (getline(in, linea)) {
            cout << linea << endl;
        }
        in.close();
    }
    catch (const exception& e) {
        cerr << "Se produjo una excepción: " << e.what() << endl;
        return 1;
    }

    return 0;
}
