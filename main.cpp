#include "list.h"

int main(void) {
    List<int> list;
    int s = 0;
    list.append_end(10);
    list.append_end(3);
    list.append_end(8);
    
    

    for (List<int>::Iterator i = list.begin(); i != list.end(); ++i) {
    //for (Node<int> *n = list.first; n != NULL; n = n->next) {
        s++;
        printf(" !%d! ", s);
        printf("%d ", *i);
    }
    return 0;
}