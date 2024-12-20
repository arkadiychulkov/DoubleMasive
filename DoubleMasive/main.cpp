#include <iostream>
#include "DoubLinLst.h"

int main() {
    DoubLinLst<int> list;

    list.AddInFrontOfHead(1);
    list.AddAfterTail(2);
    list.AddAfterTail(3);
    list.Show();

    list.DeleteFromHead();
    list.Show();

    list.DeleteFromTail();
    list.Show();

    list.DeleteAll();
    list.Show();

    return 0;
}
