#include <iostream>
#include <string>
#include <cctype>

using namespace std;


void minusculas(string& nombre, int tamano){
    tamano = nombre.size();
    for(int i = 0; i < tamano;i++){
        nombre[i] = tolower(nombre[i]);
    }
    cout<< nombre <<endl;
}
void mayusculas(string& nombre, int tamano){
    tamano = nombre.size();
    for(int i = 0; i < tamano;i++){
        nombre[i] = toupper(nombre[i]);
    }
    cout<< nombre <<endl;
}
int main(){
    string nombre;
    int tamano;

    cout<<"Ingrese su nombre: " << endl;
    getline(cin, nombre);

    
    cout<<"EN minuscula: ";
    minusculas(nombre,tamano);

    cout<<"En mayuscuka: ";
    mayusculas(nombre, tamano);
}