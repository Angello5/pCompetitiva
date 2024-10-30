#include <iostream>
#include <vector>
#include <stdexcept>  // Para usar out_of_range


using namespace std;


// Definimos la función que permite calcular la suma máxima de un camino


// Recibe como parámetro el tamaño de la matriz y la referencia a la matriz de enteros Matrix
int MaximumPath(int tam, vector<vector<int>>& Matrix) {
    // Validación de la restricción de tamaño de la matriz
    if (tam < 1 || tam > 500) {
        throw invalid_argument("El tamaño de la matriz debe estar entre 1 y 500.");
    }


    // Validación de los valores de la matriz para asegurarse de que están en el rango 1 <= Matrix[i][j] <= 1000
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            if (Matrix[i][j] < 1 || Matrix[i][j] > 1000) {
                throw out_of_range("Cada valor en la matriz debe estar entre 1 y 1000.");
            }
        }
    }


    // Creamos una matriz de tamaño N x N para almacenar las sumas máximas de los caminos o rutas
    vector<vector<int>> sumMaxRuta(tam, vector<int>(tam, 0));


    // Inicializamos la primera fila de sumMaxRuta con la primera fila de la matriz
    for (int columna = 0; columna < tam; columna++) {
        sumMaxRuta[0][columna] = Matrix[0][columna];
    }


    // Llenamos la matriz sumMaxRuta
    for (int fila = 1; fila < tam; fila++) {
        for (int columna = 0; columna < tam; columna++) {
            int valorActual = Matrix[fila][columna];


            // Posibles posiciones previas desde las que podemos llegar a (fila, columna)
            int desdeArriba = sumMaxRuta[fila - 1][columna];
            int desdeIzq = (columna > 0) ? sumMaxRuta[fila - 1][columna - 1] : 0;
            int desdeDer = (columna < tam - 1) ? sumMaxRuta[fila - 1][columna + 1] : 0;


            // Calculamos la suma máxima hasta esta celda
            //sumMaxRuta[fila][columna] = valorActual + max({desdeArriba, desdeIzq, desdeDer});
            sumMaxRuta[fila][columna] = valorActual + max(desdeArriba, max(desdeIzq, desdeDer));


        }
    }


    // Encontrar el valor máximo en la última fila de sumMaxRuta
    int sumFinalMax = 0;
    for (int j = 0; j < tam; j++) {
        sumFinalMax = max(sumFinalMax, sumMaxRuta[tam - 1][j]);
    }


    return sumFinalMax;
}


int main() {
    int tam = 2;
    vector<vector<int>> Matrix = {{348, 391}, {618, 193}};


    try {
        int resultado = MaximumPath(tam, Matrix);
        cout << "La suma maxima del camino es: " << resultado << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }


    return 0;
}
