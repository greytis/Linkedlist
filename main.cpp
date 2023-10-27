#include "list.h"

int main(void) {
    List<int> list;
    list.append_end(10);
    list.append_end(3);
    list.append_end(8);

    for (List<int>::Iterator i = list.begin(); i != list.end(); ++i) {
        printf("%d\n", *i);
    }
    
    return 0;
}