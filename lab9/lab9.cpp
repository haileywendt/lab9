// lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

bool isSortedIncreasing(int array[], int size);
bool isSortedDecreasing(int array[], int size);
bool hasAdjacentDuplicates(int array[], int size);
bool hasDuplicates(int array[], int size);
void displayRun(int array2[], int SIZE2);
bool hasRun(int array2[], int SIZE2);


int main() {
	// Part 1
	int randomarray[10];
	cout << "The random integers: ";
	for (int i = 0; i < 10; i++) { // random integers
		int random = rand() % 9000 + 1000;
		randomarray[i] = random;
		cout << random << " ";
	}
	cout << endl;
	cout << "Even indices: ";
	for (int i = 0; i < 10; i = i + 2) { // even index
		cout << randomarray[i] << " ";
	}
	cout << endl;
	cout << "Even values: ";
	for (int i = 0; i < 10; i++) { // even values
		if (randomarray[i] % 2 == 0) {
			cout << randomarray[i] << " ";
		}
	}
	cout << endl;
	cout << "Reversed order: ";
	for (int i = 9; i >= 0; i--) { // reverse
		cout << randomarray[i] << " ";
	}
	cout << endl;
	cout << "First and last: " << randomarray[0] << " " << randomarray[9] << endl;

	// Part 2
	const int SIZE = 6;
	int array[SIZE];
	 
	for (int i = 0; i < SIZE; i++) {
		cout << "Enter integer #" << i << ": ";
		cin >> array[i];  
	}

	if (isSortedIncreasing(array, SIZE) == true) {
		cout << "The data is increasing. " << endl; 
	}
	else { 
		cout << "The data is not increasing" << endl; 
	}

	if (isSortedDecreasing(array, SIZE) ==  true) {
		cout << "The data is decreasing. " << endl; 
	}
	else { 
		cout << "The data is not decreasing. " << endl; 
	}

	if (hasAdjacentDuplicates(array, SIZE) == true) {
		cout << "The data has adjacent duplicates." << endl; 
	}
	else { 
		cout << "The data has no adjacent duplicates. " << endl; 
	}

	if (hasDuplicates(array, SIZE) == true) {
		cout << "The data has duplicates." << endl;
	}
	else { 
		cout << "The data has no duplicates. " << endl; 
	}

	// Part 3
	srand(time(0));
	const int SIZE2 = 20;
	int array2[SIZE2];
	 
	for (int i = 0; i < SIZE2; i++) {
		int x = rand() % 6 + 1;
		array2[i] = x;
	}
 
	if (hasRun(array2, SIZE2) == true) {
		cout << "has run: "  << endl;
		displayRun(array2, SIZE2);
	}
	else {
		cout << "no run"; 
		for (int i = 0; i < SIZE2; i++) {
			cout << " " << array2[i]; 
		}
		cout << endl; 
	}
}

bool isSortedIncreasing(int array[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		if (array[i] < array[i + 1]) {
			return true;
		}
		else { 
			return false; }
	}
}

bool isSortedDecreasing(int array[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		if (array[i] > array[i + 1]) {
			return true;
		}
		else { 
			return false; }
	}
}

bool hasAdjacentDuplicates(int array[], int SIZE) {
	if (array[0] == array[1]) { 
		return true; }
	else if (array[1] == array[2]) { 
		return true; }
	else if (array[2] == array[3]) { 
		return true; }
	else if (array[3] == array[4]) { 
		return true; }
	else if (array[4] == array[5]) { 
		return true; }
	else { 
		return false; }
}

bool hasDuplicates(int array[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (i != j && array[i] == array[j]) {
				return true;
			}
		}
	}
	return false;
}

void displayRun(int array2[], int SIZE2) {
	for (int i = 0; i < SIZE2; i++) {
		if (array2[i] == array2[i + 1] && array2[i] != array2[i - 1]) {
			cout << " (" << array2[i] << " ";
		}
		else if (array2[i] == array2[i - 1] && array2[i] != array2[i + 1]) {
			cout << array2[i] << ") ";
		}
		else {
			cout << " " << array2[i] << " ";
		}
	}
}

bool hasRun(int array2[], int SIZE2)
{
	for (int i = 0; i < SIZE2; i++) {
		if (array2[i] == array2[i + 1]) {
			return true; 
		}
	}
	return false; 
}