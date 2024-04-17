#include "list.h"
#include "hashtable.h"

//template <typename T>


template <typename T>
List<T>::List() {
   first = NULL;
};

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
List<T>::List(const List<T> &other) {
    first = NULL;

    for (Node* current = other.first; current != NULL; current = current->next) {
        append_end(current->val);
    }
}

template <typename T>
List<T>& List< T >::operator=(const List& other) {
    if (this != &other) {
        while (first != NULL) {
            Node *temp = first;
            first = first->next;
            free(temp);
        }
        for (Node* current = other.first; current != NULL; current = current->next) {
            append_end(current->val);
        }
    }
    return *this;
}

template <typename T>
void List< T >::append_end(const T& t) {
    Node *nd = new Node;
    nd->val = t;
    nd->next = NULL;
    if (first == NULL) {
        first = nd;
    }
    else {
        Node *current = first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nd;
    }
}

template <typename T>
bool List<T>::isempty() const {
    if (first == NULL) {
        return true;
    }
    return false;
}


template <typename T>
void List<T>::append_i(const T& t, int k) {
    if (k > size() || k < 0) {
        printf("k-error;\n");
        return;
    }
    
    int i = 0;
    Node* current = first;
    Node* previous = NULL;
    while (current != NULL && i < k) {
        previous = current;
        current = current->next;
        i++;
    }

    Node* nd = new Node;
    previous->next = nd;
    nd->next = current;
    nd->val = t;
    return;
}


template <typename T>
void List< T >::append_begin(const T& t) {
    Node *nd = new Node;
    nd->val = t;
    nd->next = first;
    first = nd;
}


template <typename T>
void List<T>::remove_begin() {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* nd = first->next;
    delete first;
    first = nd;
}

template <typename T>
void List<T>::remove_i(int k) {
    if (k < 0 || k > size()) {
        printf("k-error\n");
        return;
    }
    if (k == 0) {
        remove_begin();
        return;
    }
    Node* current = first;
    int i = 0;

    while (current != NULL && i < k - 1) {
        current = current->next;
        i++;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

template <typename T> 
void List<T>::remove_end() {
    remove_i(size()-1);
}

template <typename T>
T List<T>::pop_begin() const {
    T t;
    t = first->val;
    return t;
}

template <typename T>
T List<T>::pop_i(const int k) const {
    T t;
    if (k < 0 || k > size()) {
        printf("k-error\n");
        return T();
    }
    if (k==0) {
        t = pop_begin();
        return t;
    }
    Node* current = first;
    int i = 0;

    while (current != NULL && i < k) {
        current = current->next;
        i++;
    }
    t = current->val;
    return t;
}

template<typename T>
bool List<T>::find(T& t) const {
    int i = 0;
    for (Iterator it = begin(); it != end(); ++it) {
        if (t == pop_i(i)) {
            return true;
        }
        i++;
    }
    return false;
}


template <typename T>
void List<T>::clear() {
    Node *current = first;
    while (current != NULL) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    first = NULL;
}


template <typename T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(first);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(NULL);
}

template <typename T>
size_t List<T>::size() const {
    size_t s = 0;

    for (Iterator it = begin(); it != end(); ++it) {
        s++;
    }
    return s;
}

template class List<int>;
template class List<char>;
template class List<double>;
template class List<string>;
//template class List<HashTable::Ht_item>;
//template class List<List<int>>;

