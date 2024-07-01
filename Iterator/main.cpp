#include "mylist.h"

#include <iostream>

int main() {
    MyList list(2, 5, 6);
    list.addFirst(7);
    list.addFirst(3);
    for (ListIterator it(&list); !it.IsDone(); it.Next()) {
        std::cout << it.CurrentItem() << " ";
    }
    std::cout << std::endl;
    return 0;
}