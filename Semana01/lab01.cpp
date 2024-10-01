#include <iostream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

int main(){

    bool esNumero(const string &str){
        regex numero_regex("^-?\\d+$") // para numeros enteros 
        return regex_match(str, numero_regex);
    }

    vector<int> numeros; //vector

    for (int i = -5; i <10; i++)
    {
        numeros.push_back(i);// se empuja los valores al vector
    }
    

    //for
    cout<<"Imprimir con for: ";
    for(int i = 0; i < numeros.size(); i++){
        cout<<numeros[i]<< " ";
    }
    //foeach
    cout<<"\nImprimir con foreach: ";
    for (int &num : numeros){// & se hace referencia a la variable y cambiarlo si gustas 
        num++;
        cout<< num << " ";// se imprime los valores 
    }
    
    system("pause");
    return 0;
}