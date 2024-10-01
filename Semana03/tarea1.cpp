#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

long long generarHash(const string& str, int prime, int mod){
    long long hash = 0;
    long long power = 1;

    for(int i = 0;i < str.length(); i++){
        hash = (hash + (str[i] - 'a' + 1) * power) % mod;
        power = (power * prime) % mod;
    }
    return hash;
}

int contarSubCadenasDistintas(string s){
    unordered_set<long long> uniqueHashes;
    int prime = 31;
    int mod = 1e9 + 9;

    for(int i = 0;i < s.length(); i++){
        string sub = "";
        for(int j = i; j < s.length(); j++){
            sub += s[j];
            long long hash = generarHash(sub,prime,mod);
            uniqueHashes.insert(hash);
        }
    }
    return uniqueHashes.size();
}


int main(){
    string s;
    cout<<"Introduce una cadena: ";
    cin >> s;

    int result = contarSubCadenasDistintas(s);
    cout<<"Numero de subcadenas distintas: " << result <<endl;

    return 0;
}