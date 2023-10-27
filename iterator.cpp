#include "list.h"

template <typename T>
Iterator< T >::Iterator() {
    Node* current = NULL;
}

template <typename T>
Iterator< T >::Iterator(Node<T> *nd) {
    
}



/*template <typename T>
T Iterator< T >::begin() const {
    return 
}

template <typename T>
T Iterator< T >::end() const */

template <typename T>
bool Iterator< T >::operator==(const Iterator& other) const {
        if (this == &other) {
            return true;
        }
        return current==other->current;
    }

template <typename T>
bool Iterator<T>::operator!=(const Iterator& other) const {
    return !operator==(other);
}

template <typename T>
T Iterator<T>::operator*() const {
    if (current) {
        return current->val;
    }
    else {
        printf("The end of list is reached.\n\n");
    }
}

template <typename T>
void Iterator<T>::operator++() {
    if (current) {
        current = current->next;
    }
    else {
        printf("The end of list is reached.\n\n");
    }
}
