#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    while (n-- > 0)
    {
        string palabra;
        getline(cin, palabra);

        int l = palabra.length();
        
        if(l < 3){
            cout<< palabra << endl;
        }else{
            cout<< palabra[0] << l - 2 << palabra[l-1] <<endl;
        }
    }
    return 0;
}