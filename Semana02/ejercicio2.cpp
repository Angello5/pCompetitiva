#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para intercambiar dos elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para particionar el array sin mover el pivote al final
int partition(vector<int>& arr, int p, int r) {
    // Selección aleatoria del pivote
    int pivotIndex = p + rand() % (r - p + 1);
    int pivot = arr[pivotIndex];

    int i = p; // Inicializa el índice para elementos menores o iguales al pivote
    int j = r; // Inicializa el índice para elementos mayores al pivote

    // Realiza la partición sin mover el pivote al final
    while (i <= j) {
        // Encuentra un elemento que debería estar a la derecha del pivote
        while (arr[i] < pivot) {
            i++;
        }
        // Encuentra un elemento que debería estar a la izquierda del pivote
        while (arr[j] > pivot) {
            j--;
        }
        // Si encontramos un par de elementos fuera de lugar, los intercambiamos
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    // El índice i ahora es la nueva posición del pivote, con todos los elementos
    // menores o iguales al pivote a la izquierda y los mayores a la derecha.
    return i - 1;
}

// Función QuickSelect
int quickSelect(vector<int>& A, int p, int r, int k) {
    if (p == r) {
        return A[p];
    }

    int q = partition(A, p, r);  // Partición, q es la posición final del pivote
    int l = q - p + 1;  // Número de elementos en el subarray A[p ... q]

    if (k == l) {
        return A[q];  // El pivote es la respuesta
    } else if (k < l) {
        return quickSelect(A, p, q - 1, k);  // Buscar en el subarray izquierdo
    } else {
        return quickSelect(A, q + 1, r, k - l);  // Buscar en el subarray derecho
    }
}

int main() {
    vector<int> arr = {10, 4, 5, 8, 6, 11, 26};
    int n = arr.size();
    int k = 3;  // Queremos el 3er elemento más pequeño (índice 2)

    srand(time(0));  // Inicializar el generador de números aleatorios

    int result = quickSelect(arr, 0, n - 1, k);

    cout << "El " << k << "-ésimo elemento más pequeño es: " << result << endl;

    return 0;
}