// Assignment1.cpp - Madison Alexander

#include <iostream>
#include <fstream>
#include <string>


const int MAX_SIZE = 100; 

void readDataFromFile(int arr[], int& size, const std::string& fileName) {
	std::ifstream inputFile("A1input.txt");

	if (inputFile.is_open()) {
		size = 0;
		while (inputFile >> arr[size] && size < MAX_SIZE) {
			size++;
			}
		inputFile.close();
	} else {
		std::cerr << "Error when opening file: A1input.txt" << std::endl;
	}
}
static int ModifyValue(int arr[], int index, int newValue, int& oldValue) {
	if (index < 0 || index >= MAX_SIZE) {
		throw std::out_of_range("Index out of bounds");
	}
	oldValue = arr[index];
	arr[index] = newValue;
	return oldValue;
}

int findIndex(int arr[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

int modifyValue(int arr[], int index, int newValue, int& oldValue) {
	oldValue = arr[index];
	arr[index] = newValue;
	return oldValue;
}

void addInterger(int arr[], int& size, int newValue) {
	if (size < MAX_SIZE) {
		arr[size] = newValue;
		size++;
	}
	else {
		std::cerr << "Cannot add more, array is full" << std::endl;
	}
}
// This will move everything from left to right like in class
void replaceValueOrRemove(int arr[], int& size, int index, bool remove) {
	if (index >= 0 && index < size) {
		if (remove) {
			for (int i = index; i < size - 1; i++) {
				arr[i] = arr[i + 1];
			}
			size--;
		}
		else 
			arr[index] = 0;
		
	}
	else {
		std::cerr << "Invalid index" << std::endl;
	}
}

int main() {
	int arr[MAX_SIZE];
	int size = 0;

	readDataFromFile(arr, size, "A1input.txt");
	std::cout << "Array from file: ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	int target = 27;
	int index = findIndex(arr, size, target);
	if (index != -1) {
		std::cout << "Number " << target << " found at index: " << index << std::endl;
	}
	else {
		std::cout << "Number " << target << " not found in the array." << std::endl;
	}

	int modifyIndex = 32;
	int newValue = 4;
	int oldValue;
	int modifiedValue = modifyValue(arr, modifyIndex, newValue, oldValue);
	std::cout << "Modified value in index " << modifyIndex << ": " << modifiedValue << " (Old value: " << oldValue << ")" << std::endl;

	int newInterger = 69;
	if (size < MAX_SIZE) {
		arr[size] = newInterger;
		size++;
		std::cout << "New Integer that was Added: " << newInterger << std::endl;
	} else {
	addInterger(arr, size, newInterger);

	int replaceIndex = 1;
	bool remove = true;
	replaceValueOrRemove(arr, size, replaceIndex, remove);
	std::cout << "Removed integer at index " << replaceIndex << "." << std::endl;
	return 0;
}