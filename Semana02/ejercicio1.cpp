#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void merge(T a1[], T a2[], T a[] ,int n){
    int i =0 ,j = 0 ,k = 0;
    while( i < n/2 && j < n - n/2){
        if(a1[i] < a2[j]){
            a[k] = a1[i];
            i++;
        }else{
            a[k] = a2[j];
            j++;
        }
        k++;
    }

    while(i < n/2){
        a[k] = a1[i];
        i++;
        k++;
    }

    while (j < n-n/2)
    {
        a[k] = a2[j];
        j++;
        k++;
    }
    
}


template<typename T>
void MergeSort(T a[], int n){
    if(n < 2) return;

    int mid = n / 2;

    T* a1 = new T[mid];
    T* a2 = new T[n - mid];

    //divide el array en 2 subarrays
    for(int i = 0; i < mid; i++){
        a1[i] = a[i];
    }

    for(int i = mid; i < n;i++){
        a2[i - mid] = a[i];
    }

    //recursivo
    MergeSort(a1, mid);
    MergeSort(a2, n - mid);

    //mezcla
    merge(a1,a2,a,n);

    //libera memoria
    delete[]  a1;
    delete[]  a2;


}

template <typename T>
void imprimir(const T a[], int n){
    for(int i = 0; i < n; i++){
        cout<<a[i] <<" ";
    }
    cout<< endl;
}


int main(){
    int arr[] = {40,31,51,66,887,15,64,12,34,13};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Array Sin ordenar:";
    imprimir(arr, n);

    MergeSort(arr,n);

    cout<<"Array Ordenado:";
    imprimir(arr,n);

    return 0;
}