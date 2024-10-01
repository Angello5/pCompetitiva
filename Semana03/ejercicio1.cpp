//#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main(){

    
    string str = "Learn Competetive Programming with GFG!";

    size_t first = str.find('m');
    size_t last = str.find_last_of('m');

    if(first != string::npos){
        cout<<"First ocurrence of m is at index = " << first <<endl;
    }

    if(last != string::npos){
        cout<<"Last ocurrence of m is at index = " << last << endl;
    }

    return 0;
}