#include "hashtable.h"

template <>
int HashTable<int, int>::hash_function(const int& key) const {
    return (key + 1) % size;
}

template <>
int HashTable<string, string>::hash_function(const string& key) const {
        int hash = 0;
        for (int i = 0; key[i] != '\0'; i++) {
            hash += i;
        }
        return hash % size;
}

int main(void) {
    //----------------Моя реализация (c другим типом - int)--------------------

    printf("!!!!!!!!!!!!!!!\n\n");
    HashTable<int, int> th;
    th.insert(1, 2);
    th.output();
    if (th.find(1) == 1) {
        cout << "Element Presents\n";
    }
    else {
        cout << "Element Not presents\n";
    }

    if (th.find(0) == 1) {
        cout << "Element Presents\n";
    }
    else {
        cout << "Element Not presents\n";
    }

    th.insert(2, 2);
    th.remove(1);
    th.output();
    
    printf("!!!!!!!!!!!!!!!\n");

    //-----------------Моя реализация для сравнения с STL----------------------

    auto start = high_resolution_clock::now();

    HashTable<string, string> ht;

    ht.insert("One", "First");
    ht.insert("Two", "Second");
    ht.insert("Three", "Third");
    ht.insert("First", "1");
    ht.insert("Second", "2");

    ht.output();

    printf("\n");


    string key_true = "One";
    cout << key_true << endl;
    if (ht.find(key_true) == 1) {
        cout << "Element Presents\n";
    }
    else {
        cout << "Element Not presents\n";
    }

    printf("\n\n");

    string key_false = "e";
    cout << key_false << endl;
    if (ht.find(key_false) == 1) {
        cout << "Element Presents\n";
    }
    else {
        cout << "Element Not Presents\n";
    }

    printf("\n\n");

    ht.remove(key_true);
    ht.output();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    auto c1 = duration.count();
    cout <<"Implementation time for my HashTable is "<< c1 << " microsecons" << endl;



    //--------------------------STL реализация---------------------------------
    start = high_resolution_clock::now();

    unordered_map<string, string> umap;
    umap.insert(make_pair("One", "First"));
    umap.insert(make_pair("Two", "Second"));
    umap.insert(make_pair("Three", "Third"));
    umap.insert(make_pair("First", "1"));
    umap.insert(make_pair("Second", "2"));

    unordered_map<string, string>::iterator itr;
    for (itr = umap.begin(); itr != umap.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }

    printf("\n\n");

    cout << key_true << endl;

    if (umap.find(key_true) == umap.end()) {
        cout << "Element Not presents\n";
    }
    else {
        cout << "Element presents\n";
    }

    printf("\n");

    cout << key_false << endl;

    if (umap.find(key_false) == umap.end()) {
        cout << "Element Not presents\n";
    }
    else {
        cout << "Element presents\n";
    }

    printf("\n");

    umap.erase(key_true);
    for (itr = umap.begin(); itr != umap.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }

    printf("\n");

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    auto c2 = duration.count();
    cout <<"Implementation time for STL unordered_map is "<< c2 << " microsecons" << endl;

    cout << "Time difference: " << c1 - c2 << " microsecons" << endl;

    return 0;
}




