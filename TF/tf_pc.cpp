#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct ResultadoKadane {
    int sumaMaxima;
    int indiceInicio;
    int indiceFin;
};

// Función para implementar el algoritmo de Kadane
ResultadoKadane kadaneAlgorithm(const vector<int>& ingresos) {
    int maxActual = ingresos[0];
    int maxGlobal = ingresos[0];
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

int leerEnteroPositivo(const string& mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        cin >> numero;
        if (cin.fail() || numero <= 0) {
            cout << "Error: ingrese un número entero positivo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return numero;
}

float leerIngresoTrimestral(int trimestre) {
    float ingreso;
    while (true) {
        cout << "Trimestre " << trimestre << ": ";
        cin >> ingreso;
        if (cin.fail()) {
            cout << "Error: ingrese un número válido para el ingreso.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return ingreso;
}

int main() {
    int n = leerEnteroPositivo("Ingrese el número de trimestres: ");
    vector<int> ingresos(n);

    cout << "Ingrese los ingresos para cada trimestre:" << endl;
    for (int i = 0; i < n; ++i) {
        ingresos[i] = leerIngresoTrimestral(i + 1);
    }

    ResultadoKadane resultado = kadaneAlgorithm(ingresos);

    cout << "La mayor suma de ingresos es: " << resultado.sumaMaxima << endl;
    cout << "Este valor se obtiene entre los trimestres " << (resultado.indiceInicio + 1)
         << " y " << (resultado.indiceFin + 1) << "." << endl;

    return 0;
}
