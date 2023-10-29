#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <typename T>
struct Node {
    Node(): next ( NULL) { }
    Node(const T& t): val (t), next(NULL) { }
    T val;
    Node *next;
};



template <typename T>
class List {

    //private: 
    public:
    Node<T> *first;

    friend class Iterator;

    public:

        class Iterator {
        private:
        friend class List< T >;
        Node<T> *current;

        public:
        /*Iterator() {
            Node<T>* current;
            current = NULL;
        }*/
        Iterator (Node<T> *nd) : current (nd) { }

        bool operator==(const Iterator& other) const {
            if (this == &other) {
                return true;
            }
            return current==other.current;
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
            return T();
        }

        Iterator& operator++() {
            current = current->next; 
            return *this;        
        }
    };


    public:

    List();
    ~List();
    List(const List &l);
    
    List& operator=(const List &other);

    void append_end(const T& t);
    void append_begin(const T& t);
    Node* append_i(const T& t, int k);

    Iterator begin() const;
    Iterator end() const;

    void clear();
    void output();

};




#endif