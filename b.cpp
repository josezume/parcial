#include <iostream>
#include <fstream>
#include <string>
#include <string>

using namespace std;

int main() {
    int opcion;
    string nombreArchivo = "pc.txt"; 

    do {
        cout << "\n|-------------- MENU --------------|" << endl;
        cout << "| 1. Agregar informacion a 'pc.txt'|" << endl;
        cout << "| 2. Modificar                     |" << endl;
        cout << "| 3. Leer otro archivo             |" << endl;
        cout << "| 4. Salir                         |" << endl;
        cout << "|----------------------------------|" << endl;
        cout << "Opcion a elegir:";
       
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
        case 1: {
            ofstream archivoEscritura(nombreArchivo, ios::app);  
            if (!archivoEscritura) {
                cout << "Error al abrir el archivo para escribir" << endl;
                break;
            }
            cout << "Escribe el texto que deseas agregar: ";
            string texto;
            getline(cin, texto);
            archivoEscritura << texto << endl;
            archivoEscritura.close();
            cout << "Informacion agregada con exito." << endl;
            break;
        }

        case 2: { 
            ofstream archivoEscritura(nombreArchivo); 
            if (!archivoEscritura) {
                cout << "Error al abrir el archivo para escribir" << endl;
                break;
            }
            cout << "Escribe el nuevo contenido (esto borrara lo anterior): ";
            string texto;
            getline(cin, texto);
            archivoEscritura << texto << endl;
            archivoEscritura.close();
            cout << "Archivo modificado con exito." << endl;
            break;
        }

        case 3: { 
            string otroArchivo;
            cout << "Ingresa el nombre del archivo a leer (ejemplo: archivo.txt): ";
            cin >> otroArchivo;
            cin.ignore(); //el cin.ignore limpia el bufer de entrada, esto evita leer espacios / lienas en blanco

            ifstream archivoLectura(otroArchivo);
            if (!archivoLectura) {
                cout << "Error: No se pudo abrir el archivo '" << otroArchivo << "'" << endl;
                break;
            }

            cout << "\nContenido de '" << otroArchivo << "':" << endl;
            string linea;
            while (getline(archivoLectura, linea)) {
                cout << linea << endl;
            }
            archivoLectura.close();
            break;
        }

        case 4:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida. Intenta de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
