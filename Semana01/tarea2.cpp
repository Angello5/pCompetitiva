#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool esSeguro(vector<vector<int>>& tablero, int i, int j, int num){
    //verifica la fila
    //x = fila
    for (int x =0; x < 9; x++)
    {
        if(tablero[i][x] == num){
            return false;
        }
    }

    //verifica la columna
    //y = columna
    for (int y = 0; y < 9; y++)
    {
        if(tablero[y][j] == num){
            return false;
        }
    }
    
    //verifica la subcuadricula 3x3

    //calculo el inicio de la subcuadricula
    int inicio_fila = i - i % 3;
    int inicio_columna = j - j % 3;

    for(int z = 0; z < 3; z++){
        for(int w = 0; w < 3; w++ ){
            if(tablero[inicio_fila + z][inicio_columna + w] == num){
                return false;
            }
        }
    }
    return true;
}
//i = fila
//j = columna

bool resolverSudoku(vector<vector<int>>& tablero){
    for(int i = 0; i < 9;i++){
        for(int j=0; j < 9; j++){
            if(tablero[i][j] == 0){
                for(int num=1; num <= 9;num++){
                    if(esSeguro(tablero,i,j,num)){
                        tablero[i][j] = num;
                    if(resolverSudoku(tablero)){
                        return true;
                    }
                    tablero[i][j] = 0; //backtracking
                    }
                 }
                return false;
            }
        }
    }
    return true;
}

void imprimirTablero(const vector<vector<int>>& tablero) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "------*-------*------" << endl;  // Línea horizontal 
        }
        
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << " | ";  // Separador vertical 
            }
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    //inicializar los numeros del sudoku
    vector<vector<int>> tablero = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if(resolverSudoku(tablero)){
        cout<<"Sudoku hecho: " << endl;
        imprimirTablero(tablero);
    }else{
        cout<<"No se pudo resolver el sudoku." << endl;
    }

}