#pragma once
#include <iostream>
class array
{
private:
	int* arr;
	int size;
public:
	array(int size) {
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = i * i;
		}
	}
	array(int* arr, int size) {
		this->size = size;
		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = arr[i];
		}
	}
	void printArray() {
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
	void removeArray() {
		delete[] arr;
	}
	void insertAtBegging(int element) {
		size++;
		int* tempArray = arr;
		arr = new int[size];
		arr[0] = element;
		for (int i = 1; i < size; i++) {
			arr[i] = tempArray[i - 1];
		}
		delete[] tempArray;
	}
	void insertAtEnd(int element) {
		size++;
		int* tempArray = arr;
		arr = new int[size];
		arr[size - 1] = element;
		for (int i = 0; i < size - 1; i++) {
			arr[i] = tempArray[i];
		}
		delete[] tempArray;
	}
	void intsertSorted(int element) {
		// Inserts and element into its correct postion (ascending order) //
		insertAtBegging(element);
		sortArray();
	}
	void deleteAtBeginning() {
		size--;
		int* tempArray = arr;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = tempArray[i + 1];
		}
		delete[] tempArray;
	}
	void deleteAtEnd() {
		size--;
		int* tempArray = arr;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = tempArray[i];
		}
		delete[] tempArray;
	}
	void deleteAtPosition(int positon) {
		size--;
		int* tempArray = arr;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			if (i < positon - 1) {
				arr[i] = tempArray[i];
			}
			else {
				arr[i] = tempArray[i + 1];
			}
		}
		delete[] tempArray;
	}
	void deleteElement(int element) {
		// Deletes all instances of a given element in array //
		int* tempArray = arr;
		int newSize = size;
		int offset = 0;
		for (int i = 0; i < size; i++) {
			if (tempArray[i] == element) {
				newSize--;
			}
		}
		size = newSize;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			if (tempArray[i + offset] == element) {
				offset++;
			}
			arr[i] = tempArray[i + offset];
		}
		delete[] tempArray;
	}
	void sortArray() {
		// Sorts array in ascending order //
		bool passed = true;
		for (int i = 0; i < size - 1; i++) {
			int currentElement = arr[i];
			int nextElement = arr[i + 1];
			// If current > next, swap//
			if (currentElement > nextElement) {
				arr[i] = nextElement;
				arr[i + 1] = currentElement;
				passed = false;
			}
		}
		// Recursive function //
		if (!passed) {
			sortArray();
		}
	}
	int linearSearchFor(int element) {
		// Searches for element and returns its position linearly. -1 means element not found //
			for (int i = 0; i < size; i++) {
				if (arr[i] == element) { return i; }
			}
		return -1;
	}
	int iterativebinarySearchFor(int element) {
		// Searches for element using binary search (assumes array is sorted).-1 means element not found //
			int start = 0;
		int mid = size / 2;
		int end = size - 1;
		while (start <= end) {
			if (arr[mid] == element) {
				return mid;
			}
			else if (arr[mid] < element) {
				start = mid + 1;
				mid = (start + end) / 2;
			}
			else {
				end = mid - 1;
				mid = (start + end) / 2;
			}
		}
		return -1;
	}
	int recursivebinarySearchFor(int element, int start, int end) {
		// Searches for element using binary search (assumes array is sorted).-1 means element not found //
			int mid = (start + end) / 2;
		if (start <= end) {
			if (arr[mid] == element) {
				return mid;
			}
			else if (arr[mid] < element) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
			return recursivebinarySearchFor(element, start, end);
		}
		return -1;
	}
	int countElements(int element) {
		// Returns count for # of a specific element in array //
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] == element) {
				count++;
			}
		}
		return count;
	}
	void reverseArray() {
		int* tempArray = arr;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = tempArray[size - 1 - i];
		}
		delete[] tempArray;
	}
	int* returnSection(int start, int end) {
		// Returns sub array from given start to end //
		int tempSize = end - start + 1;
		int* tempArray = new int[tempSize];
		for (int i = 0; i < tempSize; i++) {
			tempArray[i] = arr[i + start];
		}
		return tempArray;
		delete[] tempArray;
	}
	int* returnUniqueElements() {
		// Returns sub array only containing unique elements //
		int* tempArray = arr;
		int tempSize = size;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i != j) {
					if (arr[i] == arr[j]) {
						deleteAtPosition(j);
						j--;
					}
				}
			}
		}
		return arr;
		arr = tempArray;
		size = tempSize;
		delete[] tempArray;
	}
};