#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

// Estructura para almacenar mes y año
struct MesAnio {
    int anio;
    string mes;
};

// Función para encontrar la subsecuencia de 3 meses con la suma máxima
struct ResultadoVentana {
    float sumaMaxima;
    int indiceInicio;
    int indiceFin;
};

// Función para leer ingresos desde un archivo CSV
vector<float> leerIngresosDesdeCSV(const string& nombreArchivo, vector<MesAnio>& mesesAnios) {
    vector<float> ingresos;
    ifstream archivo(nombreArchivo);
    string linea;

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return ingresos;
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

        // Convertir los datos a los tipos apropiados y agregar al vector
        try {
            año = stoi(añoStr);
            ingreso = stof(ingresoStr);
            ingresos.push_back(ingreso);
            mesesAnios.push_back({año, mes});
        } catch (invalid_argument&) {
            cerr << "Formato de ingreso inválido en la línea: " << linea << endl;
        }
    }

    archivo.close();
    return ingresos;
}


ResultadoVentana ventanaDeslizante(const vector<float>& ingresos) {
    int k = 3; 
    if (ingresos.size() < k) {
        return {0.0, -1, -1};
    }

    float sumaActual = 0.0;
    // Calcular la suma de los primeros k meses
    for (int i = 0; i < k; ++i) {
        sumaActual += ingresos[i];
    }

    float sumaMaxima = sumaActual;
    int indiceInicio = 0;
    int indiceFin = k - 1;

    // Deslizar la ventana a través del arreglo
    for (int i = k; i < ingresos.size(); ++i) {
        sumaActual += ingresos[i] - ingresos[i - k];
        if (sumaActual > sumaMaxima) {
            sumaMaxima = sumaActual;
            indiceInicio = i - k + 1;
            indiceFin = i;
        }
    }

    return {sumaMaxima, indiceInicio, indiceFin};
}

int main() {
    string nombreArchivo = "microEmpresaFinal.csv";
    vector<MesAnio> mesesAnios; // Vector para almacenar año y mes correspondientes a cada ingreso
    vector<float> ingresos = leerIngresosDesdeCSV(nombreArchivo, mesesAnios);

    if (ingresos.empty()) {
        cout << "No se encontraron ingresos en el archivo." << endl;
        return 1;
    }

    ResultadoVentana resultado = ventanaDeslizante(ingresos);

    // Validar que los índices estén dentro del rango
    if (resultado.indiceInicio == -1 || resultado.indiceFin == -1) {
        cout << "No hay suficientes meses para analizar." << endl;
        return 1;
    }

    // Formatear la salida a dos decimales
    cout << fixed << setprecision(2);

    cout << "La mayor suma de ingresos de 3 meses es: " << resultado.sumaMaxima << " soles" << endl;
    cout << "Este valor se obtiene entre " << mesesAnios[resultado.indiceInicio].mes
         << " del año " << mesesAnios[resultado.indiceInicio].anio
         << " y " << mesesAnios[resultado.indiceFin].mes
         << " del año " << mesesAnios[resultado.indiceFin].anio << "." << endl;

    // Imprimir los valores que componen la subsecuencia más rentable
    cout << "Los ingresos que forman esta subsecuencia son: ";
    for (int i = resultado.indiceInicio; i <= resultado.indiceFin; ++i) {
        cout << ingresos[i];
        if (i < resultado.indiceFin) cout << ", ";
    }
    cout << endl;

    return 0;
}
