#include <iostream>
#include <vector>
#define N 8
using namespace std; 


int movX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int movY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool esSeguro(int x, int y, vector<vector<int>>&tablero){
    return (x >=0 && x < N && y >=0 && y < N && tablero[x][y]== -1); // verificacion
}

bool resolverKT(int x, int y, int movi, vector<vector<int>> &tablero){
    if(movi == N * N ){
        return true;
    }

    for(int k=0; k <= N; k++){
        int nextX = x + movX[k];
        int nextY = y + movY[k];

        if(esSeguro(nextX, nextY, tablero)){
            tablero[nextX][nextY] = movi;
            if(resolverKT(nextX, nextY, movi+1,tablero)){
                return true;
            }
            tablero[nextX][nextY] = -1; //backtracking
        }
    }
    return false;
}

void knightsTour(){
        vector<vector<int>> tablero(N,vector<int>(N, -1));

        tablero[0][0] = 0;

        if(resolverKT(0,0,1,tablero)){
            for(auto &fila : tablero){
                for(auto &celda : fila){
                    cout<< celda << " " << endl;
                }
            }
            cout << endl;
        }
        else{
            cout<<"No hay solucion";
        }
}

int main() {

    knightsTour();
    return 0;
}