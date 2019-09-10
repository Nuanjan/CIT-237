#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct FileText {
	int lineNumber;
	long long fileOffset;
	int length;
	string contents;
};

//function prototype
void ReadProcessSave(ifstream &inputF, ofstream &outFile, FileText data[]);

int main() {

	//====================================
	// initial variables
	//====================================

	// line data structure
	FileText data[150];

	string outputFile;
	string inputFile;


	//====================================
	// obtaining information from user
	//====================================

	cout << "Enter a input file: ";
	cin >> inputFile;

	ifstream inputF(inputFile);
	// ifstream inputF("Gettysburg.txt");
	if (!inputF.is_open()) {
		cout << "Error opening file" << endl;
		return 1;
	}

	cout << "Enter a output file: ";
	cin >> outputFile;

	ofstream outF(outputFile);
	// ofstream outF("output.txt");

	//====================================
	// read information from input file
	//====================================

	ReadProcessSave(inputF, outF, data);

	// closing files
	inputF.close();
	outF.close();

	system("pause");
	return 0;
}

//========================================

void ReadProcessSave(ifstream &inputF, ofstream &outFile, FileText data[])
{
	//====================================
	// read information from input file
	//====================================

	string buffer;      // contains file's content line by line
	int str_len = 0;    // calculated lenght of each string
	int offset = 0;     // keeps offset of read lines
	int line_num = 0;   // keeps track of line number
	int index = 0;      // keeps track of index in array for saving


						// each line needs to add the null terminator for the lenth
						// for (initial; condition; update)
						// getlines reads until if finds '\n'
						// but returns FALSE when it finds EOF.
						//while(getline(inputF, buffer)) {
	//inputF.seekg(0L, ios::beg);
	offset = inputF.tellg();

	for (; getline(inputF, buffer);) {
		// size without null-terminator
		str_len = buffer.length();
		++line_num;

		cout << line_num << "<" << offset << "," << str_len << ">"
			<< ": " << buffer << endl;
		//inputF.seekg(0L, ios::cur);
		
		outFile << line_num << "<" << offset << "," << str_len << ">"
			<< ": " << buffer << endl;

		data[index].lineNumber = line_num;
		data[index].fileOffset = offset;
		data[index].length = str_len;
		data[index].contents = buffer;

		offset = inputF.tellg();

		index++;
	}
}


