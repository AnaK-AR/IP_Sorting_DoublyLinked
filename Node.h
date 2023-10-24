// Este header file implementa una estructura de datos de doble enlace

#pragma once

// Se defina la estructura Node, que actua conmo un nodo de la lista doblemente enlazada
template<class T>
struct Node {
    // Valor que almacena
    T data;

    // Punteros a los nodos anterior y siguiente
    Node<T>* prev;
    Node<T>* next;
 
    // Constructores
    Node();
    Node(T data);
    Node(T data, Node<T>* prev, Node<T>* next);
};

// Declaracion de constructores

// Punteros nulos
template<class T>
Node<T>::Node() {
    prev = nullptr;
    next = nullptr;
}

// Se toman valores y los punteros son nulos
template<class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
}

// Se toman valores y punteros
template<class T>
Node<T>::Node(T data, Node<T>* prev, Node<T>* next)
{
    this->data = data;
    this->prev = prev;
    this->next = next;
}