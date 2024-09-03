#include <iostream>
#include "array.h"
int main() {
	array a1(5);
	std::cout << "Initial array: ";
	a1.printArray();
	std::cout << "Array after adding element to beginning: ";
	a1.insertAtBegging(254);
	a1.printArray();
	std::cout << "Array after adding element to end: ";
	a1.insertAtEnd(254);
	a1.printArray();
	std::cout << "Array after adding element 254 and sorted: ";
	a1.intsertSorted(254);
	a1.printArray();
	std::cout << "Array after deleting element at beginning: ";
	a1.deleteAtBeginning();
	a1.printArray();
	std::cout << "Array after deleting element at end: ";
	a1.deleteAtEnd();
	a1.printArray();
	std::cout << "Array after deleting element at positon 4: ";
	a1.deleteAtPosition(4);
	a1.printArray();
	std::cout << "Array after deleting all #4: ";
	a1.deleteElement(4);
	a1.printArray();
	std::cout << "(Linear Search) #254 is located at: " <<
		a1.linearSearchFor(254) << "\n";
	std::cout << "(Iterative Binary Search) #254 is located at: " <<
		a1.iterativebinarySearchFor(254) << "\n";
	std::cout << "(Recursive Binary Search) #254 is located at: " <<
		a1.iterativebinarySearchFor(254) << "\n";
	std::cout << "# of elemets with #254 is: " << a1.countElements(254) << "\n";
	std::cout << "Array Reversed: ";
	a1.reverseArray();
	a1.printArray();
	std::cout << "Section array from position 1 to 3 is: ";
	int* tempArray1 = a1.returnSection(1, 3);
	array a2(tempArray1, 3);
	a2.printArray();
	std::cout << "Section array of only unique elements is: ";
	int* tempArray2 = a1.returnUniqueElements();
	array a3(tempArray2, 3);
	a2.printArray();
	return 0;
}