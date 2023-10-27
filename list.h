#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

template <typename T>
struct Node {
    Node(): next ( NULL) { }
    Node(const T& t): val (t), next(NULL) { }
    T val;
    Node *next;
};



template <typename T>
class List {

    private: 

    Node<T> *first;

    friend class Iterator;

    public:

        class Iterator {
        private:
        friend class List< T >;
        Node<T> *current;

        public:
        Iterator() {
            Node<T>* current;
            this->current = NULL;
        }
        Iterator (Node<T> *nd) {
            this->current = node;
        }

        bool operator==(const Iterator& other) const {
            if (this == &other) {
                return true;
            }
            return current==other->current;
        }

        bool operator!=(const Iterator& other) const {
            return !operator==(other);
        }

        T operator*() const {
            if (current) {
            return current->val;
            }
            else {
                printf("The end of list is reached.\n\n");
            }
        }

        void operator++() {
            if (current) {
                current = current->next;
            }
            else {
                printf("The end of list is reached.\n\n");
            }
        }
    };


    public:

    List();
    ~List();
    List(const List &l);
    
    List& operator=(const List &other);

    void append_end(const T& t);
    void append_begin(const T& t);

    Iterator begin();
    Iterator end();

    void clear();
    void output();

};




#endif