#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n;
    cin >> s;
    
    string original; 

    for (int i = n - 1 ; i >= 0; --i) {
        if ((n - i) % 2 == 0) {
            original = s[i] + original;
        } else {
            original = original + s[i];
        }
    }

    cout << original << endl;

    return 0;
}