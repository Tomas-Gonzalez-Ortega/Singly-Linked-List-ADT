#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
    LinkedList<int> myList;
    for (int i = 0; i < 10; i++) {
        myList.insertAt(i, i);
        myList.insertAt(i, 10 - i);
    }
    cout << "The elements of the list are : \n";
    myList.print();
    myList.removeAll(5);
    myList.removeAll(9);
    cout << "After removing all the occurrences of 5 and 9 the elements of the list are : \n";
    myList.print();
    for (int i = 0; !myList.isEmpty(); i++)
        cout << "Element at " << i << " is removed : " << myList.removeFrom(i);
    myList.print();
    system("PAUSE");
    return 0;
}
