#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int arraySize;

struct MovieData
{
	string title;
	string director;
	int yearReleased;
	double runningTime;
};

void populateMovieArray(MovieData *, int);

void displayMovieArray(MovieData *, int);

void findLongestMovie(MovieData *, int);

int main()
{
	while (true)
	{
		MovieData movieInfo;
		int user_size;
		cout << "Enter desired array size: ";
		cin >> user_size;

		// here we are allocating memory based on the size given by the user.
		// arrayPtr points to the initial space of memory allocated
		// user_size is the maximum size of the space allocated.

		MovieData *arrayPtr = new MovieData[user_size];
		cout << "arrayPtr = " << arrayPtr << endl;

		populateMovieArray(arrayPtr, user_size);

		displayMovieArray(arrayPtr, user_size);

		findLongestMovie(arrayPtr, user_size);

		cout << "DELETING array at arrayPtr = " << arrayPtr << endl;

		delete[] arrayPtr;
	}
	system("pause");
	return 0;
}

void populateMovieArray(MovieData *arrayPtr, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Enter Title " << i  << ": ";
		cin.ignore();
		getline(cin, arrayPtr[i].title);
		//arrayPtr[i] = title;

		// get the director
		cout << "Enter Director " << i  << ": ";
		getline(cin, arrayPtr[i].director);

		cout << "Enter Year Released " << i  << ": ";
		cin >> arrayPtr[i].yearReleased;

		cout << "Enter Running Time(minutes) " << i  << ": ";
		cin >> arrayPtr[i].runningTime;
	}
}

void displayMovieArray(MovieData *arrayPtr, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << arrayPtr + i << ":  " << "arrayPtr[" << i << "] = " << endl;
		cout << setw(24) << "Title        : " << arrayPtr[i].title << endl;
		cout << setw(24) << "Director     : " << arrayPtr[i].director << endl;
		cout << setw(24) << "Released     : " << arrayPtr[i].yearReleased << endl;
		cout << setw(24) << "Running Time : " << arrayPtr[i].runningTime << endl;
	}

	cout << endl << endl;
}

void findLongestMovie(MovieData *arrayPtr, int arraySize)
{
	int maxTime = 0;
	int index = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (maxTime < arrayPtr[i].runningTime) {
			maxTime = arrayPtr[i].runningTime;
			index = i;
		}
	}

	cout << "Longest Movie in list:" << endl;
	cout << setw(24) << "Title        : " << arrayPtr[index].title << endl;
	cout << setw(24) << "Director     : " << arrayPtr[index].director << endl;
	cout << setw(24) << "Released     : " << arrayPtr[index].yearReleased << endl;
	cout << setw(24) << "Running Time : " << arrayPtr[index].runningTime << endl;

	cout << "Longest Movie is: " << maxTime << " minutes long" << endl;

}




