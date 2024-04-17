#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "list.h"
#include <string>
#include <chrono>
#include <unordered_map>



using namespace std;
using namespace chrono;


template <typename K, typename V>
class HashTable {
private:
    static const int size = 10;

    struct Ht_item {
        K key;
        V val;

        Ht_item() {
            key = K();
            val = V();
        }

        Ht_item(const K& k, V v) : key(k), val(v) {}

        bool operator==(const Ht_item& other) const {
            if (this->key == other.key && this->val == other.val) {
                return true;
            }
            return false;
        }
        void output_item(Ht_item& other) const {
            printf("%s %s", other.key, other.val);
            return;
        }
    };

    List<Ht_item> table[size];

    int hash_function(const K& key) const {
        return key % size;
    }

    public:

    
        HashTable() {
            for (int i = 0; i < size; i++) {
                table[i] = List<Ht_item>();
            }
        }

        HashTable(HashTable &other) {
            for (int i = 0; i < size; i++) {
                table[i] = other.table[i];
            }
        }

        ~HashTable() {
            for (int i = 0; i < size; i++) {
                table[i].clear();
            }
        }


        void insert(const K& key, const V& val) {
            int index = hash_function(key);
            Ht_item Item(key, val);
            table[index].append_end(Item);
        }

        bool find(const K& key) const {
            int index = hash_function(key);
            if (table[index].isempty() == true) {
                return false;
            }
            return true;
        }

        // bool find(const string& key, const string& val) const {
        //     int index = hash_function(key);
        //     if (table[index].isempty() == true) {
        //         return false;
        //     }
        //     else {
        //         for (List<Ht_item>::Iterator it = table[index].begin(); it != table[index].end(); ++it) {
        //             Ht_item Item(*it);
        //             if (Item.val == val) {
        //                 return true;
        //             }
        //             return false;
        //         }
        //     }
        // }

        void remove(const K& key) {
            int index = hash_function(key);
            table[index].clear();
            return;
        }

        // void remove(const string& key, const string& val) {
        //     int index = hash_function(key);
        //     int i = 0;
        //     for (List<Ht_item>::Iterator it = table[index].begin(); it != table[index].end(); ++it) {
        //         Ht_item Item(*it);
        //         if (Item.val == val) {
        //             table[index].remove_i(i);
        //             }
        //         i++;
        //     }
        // }

        void output() {
            for (int i = 0; i < size; i++) {
                for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                    Ht_item Item(*it);
                    cout << Item.key << " " << Item.val << endl;
                }
                if (table[i].begin() != NULL) {
                    printf("\n");
                }
            }
        }

};





template class List<HashTable<string, string>::Ht_item>;
template class List<HashTable<int, int>::Ht_item>;




#endif
