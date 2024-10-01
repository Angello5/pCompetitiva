#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matriz;


void crearMatriz(int n){
    for(int i = 0; i < n; i++){
        vector<int> row(n,0);
        matriz.push_back(row);
    }
}

void anadirConexion(int a, int b){
   matriz[a][b] = 1;
   matriz[b][a] = 1;
}

void imprimirMatriz(){
    for(int i = 0; i < matriz.size(); i++){
      for(int j = 0; j < matriz.size(); j++){
         cout << matriz[i][j] << " ";
      }
      cout<< endl;
   }
}

int main(){
    int n;
    cin >> n;
    crearMatriz(n);

    int a;
    cin>>a;
    while(a--){
        int a,b;
        cin>> a>> b;
        anadirConexion(a,b);
    } 
    cout<<"\nMatriz De Adyacencia:"<<endl;
    imprimirMatriz();
}