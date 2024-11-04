#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct ResultadoKadane {
    float sumaMaxima;
    int indiceInicio;
    int indiceFin;
};

// Función para implementar el algoritmo de Kadane
ResultadoKadane kadaneAlgorithm(const vector<float>& ingresos) {
    float maxActual = ingresos[0];
    float maxGlobal = ingresos[0];
    int indiceInicio = 0, indiceFin = 0, tempInicio = 0;

    for (int i = 1; i < ingresos.size(); ++i) {
        if (ingresos[i] > maxActual + ingresos[i]) {
            maxActual = ingresos[i];
            tempInicio = i;
        } else {
            maxActual += ingresos[i];
        }

        if (maxActual > maxGlobal) {
            maxGlobal = maxActual;
            indiceInicio = tempInicio;
            indiceFin = i;
        }
    }

    return {maxGlobal, indiceInicio, indiceFin};
}

// Función para leer ingresos desde un archivo CSV
vector<float> leerIngresosDesdeCSV(const string& nombreArchivo) {
    vector<float> ingresos;
    ifstream archivo(nombreArchivo);
    string linea;

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return ingresos;
    }

    // Ignorar la primera línea (nombre de la empresa)
    getline(archivo, linea);

    // Leer cada línea de datos a partir de la segunda línea
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string mes, ingresoStr;
        float ingreso;

        // Leer la columna de "Mes" y "Ingresos", separadas por punto y coma (;)
        getline(ss, mes, ';');
        getline(ss, ingresoStr, ';');

        // Convertir el ingreso a float y agregarlo al vector
        ingreso = stof(ingresoStr);
        ingresos.push_back(ingreso);
    }

    archivo.close();
    return ingresos;
}

int main() {
    string nombreArchivo = "MicroEmpresa1.csv"; // Nombre del archivo CSV
    vector<float> ingresos = leerIngresosDesdeCSV(nombreArchivo);

    if (ingresos.empty()) {
        cout << "No se encontraron ingresos en el archivo." << endl;
        return 1;
    }

    ResultadoKadane resultado = kadaneAlgorithm(ingresos);

    cout << "La mayor suma de ingresos es: " << resultado.sumaMaxima << endl;
    cout << "Este valor se obtiene entre los meses " << (resultado.indiceInicio + 1)
         << " y " << (resultado.indiceFin + 1) << "." << endl;

    // Imprimir los valores que componen la subsecuencia más rentable
    cout << "Los ingresos que forman esta subsecuencia son: ";
    for (int i = resultado.indiceInicio; i <= resultado.indiceFin; ++i) {
        cout << ingresos[i];
        if (i < resultado.indiceFin) cout << ", ";
    }
    cout << endl;

    return 0;
}
