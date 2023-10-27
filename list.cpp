#include "list.h"

//template <typename T>


template <typename T>
List< T >::List() {
   Node<T> *first;
   this->first = NULL;
};

template <typename T>
List< T >::~List() {
    clear();
}

template <typename T>
List< T >::List(const List &other) {
    first = NULL;
    Node<T> *current = other.first;
    Node<T> *tail = NULL;

    while (current != NULL) {
        Node<T> *nd = new Node(current->data);
        if (tail == NULL) {
            first = nd;
        }
        else {
            tail->next = nd;
        }
        tail = nd;
        current = current->next;
    }
}

template <typename T>
List< T >& List< T >::operator=(const List< T >& other) {
    if (this == &other) {
        return *this;
    }
    clear();

    Node<T> *current = other.first;
    Node<T> *tail = NULL;

    while (current != NULL) {
        Node *nd = new Node(current->data);
        if (tail == NULL) {
            first = nd;
        }
        else {
            tail->next = nd;
        }
        tail = nd;
        current = current->next;
    }
    return *this;
}

template <typename T>
void List< T >::append_end(const T& t) {
    if ( Node *nd = new Node(t) ) { //проверка, что память удалось выделить 
        nd->data = t;
        nd->next = NULL;

        if (first == NULL) {
            first = nd;
        }
        else {
            Node<T> *current = first;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = nd;
        }
    }

}

template <typename T>
void List< T >::append_begin(const T& t) {
    if ( Node<T> *nd = new Node(t) ) {
        nd->data = t;
        nd->next = first;

        first = nd;
    }
}

template <typename T>
void List< T >::clear() {
    Node<T> *current = first;
    while (current != NULL) {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
    first = NULL;
}

template <typename T>
void List<T>::output() {
    Node<T> *current = first;
    while (current != NULL) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
}

template <typename T>
List<T>::Iterator List<T>::begin() {
    return Iterator(first);
}

template <typename T>
List<T>::Iterator List<T>::end() {
    return Iterator(NULL);
}