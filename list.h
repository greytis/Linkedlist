#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



template <typename T>
class List {

    private:
        struct Node {
            T val;
            Node *next;
        };

        Node *first;

        friend class Iterator;

    public:

    class Iterator {
        private:
        friend class List< T >;
        Node *current;

        public:
        Iterator () : current (NULL) { }
        Iterator (Node *nd) : current (nd) { }

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

    bool isempty() const;

    void append_end(const T& t);
    void append_begin(const T& t);
    void append_i(const T& t, int k);

    void remove_begin();
    void remove_i(int k);
    void remove_end();

    bool find(T& t) const;

    T pop_begin() const;
    T pop_i(const int k) const;


    Iterator begin() const;
    Iterator end() const;

    size_t size() const;

    void clear();

};







#endif