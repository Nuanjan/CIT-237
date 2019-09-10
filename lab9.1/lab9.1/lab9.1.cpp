#include <iostream>
#include <iomanip>

using namespace std;

void populateIntegerArray(int *arrayPtr, int arraySize);

void displayIntegerArray(int *arrayPtr, int arraySize);

int findMaximumInteger(int *arrayPtr, int arraySize);

int main() {
	while (true) {
		int user_size;

		cout << "Enter desired array size: ";
		cin >> user_size;

		// here we are allocating memory based on the size given by the user.
		// arrayPtr points to the initial space of memory allocated
		// user_size is the maximum size of the space allocated.
		int *arrayPtr = new int[user_size];

		cout << "arrayPtr = " << arrayPtr << endl;

		populateIntegerArray(arrayPtr, user_size);
		displayIntegerArray(arrayPtr, user_size);
		int max_size = findMaximumInteger(arrayPtr, user_size);

		cout << "Maximum integer in array is: " << max_size << endl;
		cout << "DELETING array at arrayPtr = " << arrayPtr << endl;

		delete[] arrayPtr;
	}
	system("pause");
	return 0;
}

void populateIntegerArray(int *arrayPtr, int arraySize) {
	int integer_input;

	for (int i = 0; i < arraySize; i++) {
		cout << "Enter value for array element " << i << ": ";
		cin >> integer_input;
		arrayPtr[i] = integer_input;
	}

}

void displayIntegerArray(int *arrayPtr, int arraySize) {

	for (int i = 0; i < arraySize; i++) {
		cout << arrayPtr + i << ":   arrayPtr[" << i << "] = " << setw(10) << arrayPtr[i] << endl;
		//cout<<"(Hex " <<hex<<setw(8)<<setfill('0')<<uppercase<<arrayPtr[i] << ")" << endl;
	}
}


int findMaximumInteger(int *arrayPtr, int arraySize) {

	int max_size = arrayPtr[0];
	for (int i = 1; i < arraySize; i++) {
		if (arrayPtr[i] > max_size) {
			max_size = arrayPtr[i];
		}
	}

	return max_size;
}

