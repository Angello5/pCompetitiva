#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <map>
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

// Función para leer ingresos desde un archivo CSV con año
map<int, vector<float>> leerIngresosDesdeCSV(const string& nombreArchivo) {
    map<int, vector<float>> ingresosPorAnio;
    ifstream archivo(nombreArchivo);
    string linea;

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return ingresosPorAnio;
    }

    // Leer el encabezado
    getline(archivo, linea);

    // Leer cada línea de datos
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string añoStr, mes, ingresoStr;
        int año;
        float ingreso;

        // Leer las columnas separadas por punto y coma (;)
        getline(ss, añoStr, ';');
        getline(ss, mes, ';');
        getline(ss, ingresoStr, ';');

        // Convertir los datos a los tipos apropiados y agregar al mapa
        try {
            año = stoi(añoStr);
            ingreso = stof(ingresoStr);
            ingresosPorAnio[año].push_back(ingreso);
        } catch (invalid_argument&) {
            cerr << "Formato de ingreso inválido en la línea: " << linea << endl;
        }
    }

    archivo.close();
    return ingresosPorAnio;
}

int main() {
    string nombreArchivo = "microEmpresaFinal.csv"; // Nombre del archivo CSV
    map<int, vector<float>> ingresosPorAnio = leerIngresosDesdeCSV(nombreArchivo);

    if (ingresosPorAnio.empty()) {
        cout << "No se encontraron ingresos en el archivo." << endl;
        return 1;
    }

    // Nombres de los meses
    vector<string> meses = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO",
                           "JULIO", "AGOSTO", "SETIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

    // Procesar cada año por separado
    for (auto& [año, ingresos] : ingresosPorAnio) {
        if (ingresos.empty()) {
            cout << "No hay ingresos para el año " << año << "." << endl;
            continue;
        }

        ResultadoKadane resultado = kadaneAlgorithm(ingresos);

        // Calcular los meses correspondientes
        int indiceInicio = resultado.indiceInicio;
        int indiceFin = resultado.indiceFin;

        string mesInicio = (indiceInicio >= 0 && indiceInicio < meses.size()) ? meses[indiceInicio] : "Desconocido";
        string mesFin = (indiceFin >= 0 && indiceFin < meses.size()) ? meses[indiceFin] : "Desconocido";

        // Formatear la salida a dos decimales
        cout << fixed << setprecision(2);

        cout << "Año: " << año << endl;
        cout << "La mayor suma de ingresos es: " << resultado.sumaMaxima << " soles" << endl;
        cout << "Este valor se obtiene entre " << mesInicio << " y " << mesFin << "." << endl;

        // Imprimir los valores que componen la subsecuencia más rentable
        cout << "Los ingresos que forman esta subsecuencia son: ";
        for (int i = resultado.indiceInicio; i <= resultado.indiceFin; ++i) {
            cout << ingresos[i];
            if (i < resultado.indiceFin) cout << ", ";
        }
        cout << "\n----------------------------------------\n";
    }

    return 0;
}
