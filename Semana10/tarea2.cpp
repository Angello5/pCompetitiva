#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    // Crear una matriz para almacenar los resultados de subproblemas
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Llenar la matriz de manera 
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                // Verificar que el índice no sea negativo antes de acceder
                int value_with_item = (w - wt[i - 1] >= 0) ? val[i - 1] + dp[i - 1][w - wt[i - 1]] : 0;
                // Podemos escoger no tomar el objeto o tomarlo y agregar su valor
                dp[i][w] = max(dp[i - 1][w], value_with_item);
            } else {
                // No podemos tomar el objeto porque excede el peso actual
                dp[i][w] = dp[i - 1][w];    
            }
        }
    }

    // El valor máximo que se puede obtener con la capacidad W
    return dp[n][W];
}

int main() {
    int N = 5;
    int W = 10;
    vector<int> val = {2,3,4,5,6};
    vector<int> wt = {3,4,5,2,6};

    if (N <= 0 || N > 1000 || W <= 0 || W>1000 || val.size() != N || wt.size() != N) {
        cout << "Error: Los valores de entrada no son válidos." << endl;
        return 1;
    }

    cout << "El valor máximo que se puede obtener en la mochila es: " << knapSack(W, wt, val, N) << endl;

    return 0;
}      