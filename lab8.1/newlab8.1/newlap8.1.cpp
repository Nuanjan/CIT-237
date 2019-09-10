#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>

using namespace std;

const int ARRAY_SIZE = 50;

int array_size = 0;

//function pototype
void func_print_array(string array[]);
void func_sort_array(string array[]);

int main()
{
	char answer;
	string input_file;
	do{
	cout << "Enter name of input file: ";
	cin >> input_file;
	
		// 50 spaces
		string presidents[ARRAY_SIZE] = {};

		// Reads from the file and saves into our president array
		// opening file for reading
		ifstream fp(input_file, ios::in);
		if (fp.is_open()) {
			// index is going from 0 to 50
			while (getline(fp, presidents[array_size])) {
				// save line by line into president array
				//getline(fp, president[index]);
				array_size++;
			}
		}
		else {
			cout << "Invalid file name." << endl;
			return 1;
		}

		cout << array_size << " lines of text read from input file." << endl;

		// print unsorted values
		cout << "Here are the unsorted names: " << endl;
		func_print_array(presidents);

		// send array to be sorted
		func_sort_array(presidents);

		// print sorted values
		cout << "Here are the sorted names: " << endl;
		func_print_array(presidents);

		cout << "repeat? " << endl;
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');

	
	system("pause");
	return 0;


}

// func_print_array prints string arrays values 
void func_print_array(string array[]) {
    // 1 for-loops
    // 1st for-loop to go through rows
        // print the array context for the current index
    cout << "--------------------------" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << "[ " <<setw(2)<< i <<"]  " << array[i] << endl;
    }
    cout << endl;
}

// func_sort_array implements selection sort
void func_sort_array(string array[]) {
    string tmp;
    int i, j, minIndex;
    for (i = 0; i < array_size - 1; i++) //arr_size-1 because from array element 0-9 ==10 
    {
        minIndex = i;
        for (j = i + 1; j < array_size; j++)  //arr_size because 1-10
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
				
            }
        }

        if (minIndex != i)
        {
            
            cout <<  "Swap [" << setw(2) << minIndex << "] " <<setw(25)<< array[minIndex]
            // cout.flush();
            <<" with [" <<setw(2)<< i << "] " <<setw(25)<< array[i] << endl;
            tmp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = tmp;
        }
    }
    cout << endl;
}

