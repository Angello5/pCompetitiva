#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // Puntero al siguiente nodo
};Node* first = nullptr;

void create(int A[], int n) {
    Node* last;

    // Inicializa el primer nodo
    first = new Node();
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++) {
        Node* t = new Node();
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void Display(Node* p) {
    Node* current = p;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void RDisplay(Node* p) {
    if (p != nullptr) {
        RDisplay(p->next);
        cout << p->data << " ";
    }
}
Node* search(Node* lst, int v ){
    Node* p;
    for(p = lst; p != nullptr; p = p->next){
        if(p->data == v)
        return p;
    }
    return nullptr;
}
void liberarMemoria(Node* p) {
    while (p != nullptr) {
        Node* temp = p;
        p = p->next;
        delete temp; // Libera memoria de cada nodo
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    int n = sizeof(A) / sizeof(A[0]);

    create(A, n);

    cout << "Mostrar lista :" << endl;
    Display(first);

    cout << "Mostrar lista :" << endl;
    RDisplay(first);
    cout << endl;

    int valor_buscar;
    cout<<"Introduce un valor: "<<endl;
    cin>>valor_buscar;
    
    Node* resultado = search(first,valor_buscar);
    if(resultado != nullptr){
        cout<<"El valor " << valor_buscar << " fue encontrado en la lista" << endl;
    }
    else{
        cout<<"El valor " << valor_buscar << " no fue encontrado en la lista" << endl;
    }
    liberarMemoria(first);

    return 0;
}
