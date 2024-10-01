#include <iostream>
#include <vector>
#include <climits> // Para INT_MAX

using namespace std;

// Función para encontrar el nodo con la menor distancia que no ha sido procesado
int minDistance(const vector<int>& dist, const vector<bool>& visitado, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visitado[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Función que implementa el algoritmo de Dijkstra sin cola de prioridad
void dijkstra(int src, vector<vector<int>>& grafo, int V) {
    vector<int> dist(V, INT_MAX);  // Vector para almacenar las distancias mínimas
    vector<bool> visitado(V, false);  // Marca de los nodos ya procesados

    dist[src] = 0;  // La distancia al nodo fuente es 0

    for (int count = 0; count < V - 1; count++) {
        // Elegir el nodo no visitado con la distancia mínima
        int u = minDistance(dist, visitado, V);

        // Marcar el nodo u como visitado
        visitado[u] = true;

        // Actualizar el valor de dist de los vecinos de u
        for (int v = 0; v < V; v++) {
            // Solo actualizar dist[v] si no ha sido visitado, si hay una arista desde u a v,
            // y si el camino desde src a v a través de u es más corto que el actual dist[v]
            if (!visitado[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }

    // Imprimir las distancias calculadas
    cout << "Distancias más cortas desde el nodo " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Nodo " << i << ": No alcanzable\n";
        } else {
            cout << "Nodo " << i << ": " << dist[i] << "\n";
        }
    }
}

int main() {
    int V;  // Número de vértices
    cout << "Introduce el número de vértices: ";
    cin >> V;

    // Grafo representado como una matriz de adyacencia
    vector<vector<int>> grafo(V, vector<int>(V, 0));

    cout << "Introduce las aristas (formato: u v peso, -1 para finalizar):\n";
    while (true) {
        int u, v, peso;
        cin >> u >> v >> peso;
        if (u == -1) break;  // Finaliza la entrada de aristas
        grafo[u][v] = peso;
        grafo[v][u] = peso;  // Si el grafo es no dirigido
    }

    int src;
    cout << "Introduce el nodo fuente: ";
    cin >> src;

    // Ejecutar Dijkstra sin cola de prioridad
    dijkstra(src, grafo, V);

    return 0;
}