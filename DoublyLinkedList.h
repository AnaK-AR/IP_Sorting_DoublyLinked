#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include "Node.h"

template<class T>

class DoublyLinkedList{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
 
    public:
        DoublyLinkedList();
        int getSize();
        void addFirst(T data);
        void addLast(T data);
        T& operator[](int index);
        void operator=(DoublyLinkedList<T> list);
        void clear();
        void merge(Node<T>* left, Node<T>* mid, Node<T>* right);
        void mergeSort(Node<T>* left, Node<T>* right);
        void sort();
};

// Se inicializa la lista como vacia
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Se devuelve el tamaño de la lista
template<class T>
int DoublyLinkedList<T>::getSize(){
    return size;
}

template<class T>
void DoublyLinkedList<T>::addFirst(T data){
     // Si la lista está vacía, se agrega el primer elemento como cabeza y cola
    if (size == 0){
        head = new Node<T>(data);
        tail = head;
    // Se agrega un nuevo nodo como cabeza y ajusta los punteros
    } else {
        head->prev = new Node<T>(data, nullptr, head);
        head = head->prev;
    }
    size++;
}

template<class T>
void DoublyLinkedList<T>::addLast(T data) {
    // Si la lista está vacía, se agrega el primer elemento (llama a addFirst).
    if (size == 0){
        addFirst(data);
    // Se agrega un nuevo nodo como cola y se ajustan los punteros
    } else {
        tail->next = new Node<T>(data, tail, nullptr);
        tail = tail->next;
        size++;
    }
}

// Se sobrecarga el operador de acceso a elementos de la lista mediante corchetes
template <class T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }
        return aux->data;
    } else {
        throw out_of_range("Índice inválido");
    }
}

// Se sobrecarga el operador de asignación para copiar el contenido de otra lista en la lista actual
template <class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list) {
    clear();
    Node<T>* aux = list.head;
    while (aux != nullptr) {
        addLast(aux->data);
        aux = aux->next;
    }
}

// Se eliminan todos los nodos de la lista
template<class T>
void DoublyLinkedList<T>::clear(){
    Node<T>* aux = head;
    while (aux != nullptr) {
        Node<T>* temp = aux;
        aux = aux->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Merge, parte del algoritmo de ordenación Merge Sort
template<class T>
void DoublyLinkedList<T>::merge(Node<T>* left, Node<T>* mid, Node<T>* right) {
    DoublyLinkedList<T> leftList;
    DoublyLinkedList<T> rightList;

    Node<T>* current = left;
    while (current != mid->next) {
        leftList.addLast(current->data);
        current = current->next;
    }
    current = mid->next;
    while (current != right->next) {
        rightList.addLast(current->data);
        current = current->next;
    }

    current = left;
    Node<T>* leftCurrent = leftList.head;
    Node<T>* rightCurrent = rightList.head;

    while (leftCurrent && rightCurrent) {
        if (leftCurrent->data < rightCurrent->data) {
            current->data = leftCurrent->data;
            leftCurrent = leftCurrent->next;
        } else {
            current->data = rightCurrent->data;
            rightCurrent = rightCurrent->next;
        }
        current = current->next;
    }
    while (leftCurrent) {
        current->data = leftCurrent->data;
        leftCurrent = leftCurrent->next;
        current = current->next;
    }
    while (rightCurrent) {
        current->data = rightCurrent->data;
        rightCurrent = rightCurrent->next;
        current = current->next;
    }
}

// Algoritmo de ordenación Merge Sort
template<class T>
void DoublyLinkedList<T>::mergeSort(Node<T>* left, Node<T>* right) {
    if (left != nullptr && right != nullptr && left != right && left->prev != right) {
        Node<T>* mid = left;
        Node<T>* fast = left;
        while (fast != right && fast->next != right) {
            mid = mid->next;
            fast = fast->next->next;
        }
        mergeSort(left, mid);
        mergeSort(mid->next, right);
        merge(left, mid, right);
    }
}

// Ordenamientro en Merge Sort
template<class T>
void DoublyLinkedList<T>::sort() {
    if (size <= 1) {
        return;
    }
    mergeSort(head, tail);
}

#endif