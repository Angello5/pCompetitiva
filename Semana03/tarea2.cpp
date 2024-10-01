#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int contarSubCadenasDistintas(string s) {
    unordered_set<string> uniqueSubstrings;

    for (int i = 0; i < s.length() - 1; i++) {
        string sub = s.substr(i, 2);
        uniqueSubstrings.insert(sub);
    }

    return uniqueSubstrings.size();
}

int main() {
    string s;
    cout << "Introduce una cadena: ";
    cin >> s;

    int result = contarSubCadenasDistintas(s);
    cout << "Numero de subcadenas de tamaño 2 distintas: " << result << endl;

    return 0;
}