#include <iostream>
#include "DoubLinLst.h"
#include "Array.h"

int main() {
    
    try
    {
        Array<int> arr;

        arr.Add(10);
        arr.Add(20);
        arr.Add(30);

        std::cout << "Add: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";

        arr.SetSize(5);
        std::cout << "SetSize: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";

        arr.SetAt(3, 40);
        arr.SetAt(4, 50);

        std::cout << "SetAt: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";

        arr.RemoveAt(1);
        std::cout << "RemoveAt 1: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";

        arr.FreeExtra();
        std::cout << "FreeExtra: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    catch (const std::exception& e)
    {
		std::cout << e.what() << std::endl;
    }



    /*DoubLinLst<int> list;

    try
    {
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
    }
    catch (const std::exception& e)
    {
		std::cout << e.what() << std::endl;
    }*/

    return 0;
}
