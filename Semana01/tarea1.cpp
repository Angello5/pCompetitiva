#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(vector<int>& array){
    int max_actual = array[0];
    int max_global = array[0];

    for (int i = 0; i < array.size(); i++)
    {
        max_actual = max(array[i], max_actual + array[i]);

        if(max_actual > max_global){
            max_global = max_actual;
        }
    }
    return max_global;
}

int main(){
    vector<int> array = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<"La suma de la subsecuencia con la mayor suma es: " << maxSubArraySum(array)<<endl;

    return 0;
}