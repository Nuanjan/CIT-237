#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;


int main() {
	string inputText;
	ifstream inputData;
	char answer;
	do {
		cout << "Enter the file name: ";
		cin >> inputText;
		inputData.open(inputText, ios::in);

		static int i = 0;
		while (getline(inputData, inputText)) {

			i++;
			cout << i << ":" << inputText << endl;
		}
		inputData.close();
		cout << "repeat ?" << endl;
		cin >> answer;

	} while (answer == 'Y');
	system("pause");
	return 0;
}
