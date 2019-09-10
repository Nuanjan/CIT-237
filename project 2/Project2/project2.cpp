#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

string *data_str = new string[100];
int data_size = 0;

// Global Constants:
const int SUCCESS = 0;                  // return code for SUCCESS
const int FAILURE = 1;                  // return code for FAILURE
const int MAX_NUMBER_OF_FIELDS = 20;
const char DEFAULT_DELIMITER = '|';
const char CSV_SEPARATOR = ',';

void addQuotes(string &);
void processDataFile(ifstream&, ofstream&);
void quitProgram(int exitStatus);
void outputHelpMessage();

int main()
{
	// command string, input by user
	string command;

	// variables for file handling
	ifstream inputFile;
	ofstream outputFile;
	string inputFileName;
	string outputFileName;

	string inputText;
	string delimiter = string(1, DEFAULT_DELIMITER);

	while (true)
	{

		// Prompt for command input.
		cout << "\nCommand: ";
		getline(cin, command);

		cout << fixed << setprecision(2);

		if (command == "")
		{
			// ignore empty command
		}
		else if (command == "CI")
		{
			if (inputFile.is_open()) {
				inputFile.close();
			}
			else {
				cout << "No input file selected" << endl;
			}
		}
		else if (command == "CO")
		{
			if (outputFile.is_open()) {
				outputFile.close();
			}
			else {
				cout << "No output file selected" << endl;
			}
		}
		
		else if (command == "h" || command == "help")
		{
			// Output help text
			outputHelpMessage();
		}
		else if (command == "i")
		{
			cout << "Enter input filename:  ";
			getline(cin, inputFileName);
			inputFile.open(inputFileName);

			// Check for file open error.
			if (inputFile.fail())
			{
				cout << "(line " << __LINE__ << ") Error opening file:  " << inputFileName << endl;
			}
		}
		else if (command == "o")
		{
			cout << "Enter output filename:  ";
			getline(cin, outputFileName);
			outputFile.open(outputFileName);

			// Check for file open error.
			if (outputFile.fail())
			{
				cout << "(line " << __LINE__ << ") Error opening file:  " << outputFileName << endl;
			}
		}
		else if (command == "p")
		{
			processDataFile(inputFile, outputFile);
		}
		else if (command == "q" || command == "quit")
		{
			// closing files before exiting
			inputFile.close();
			outputFile.close();

			// Quit program
			quitProgram(SUCCESS);
		}
		else {
			cout << "Invalid command:  " << command << endl;
		}

	}

	system("pause");

	return 0;
}

// func_add_quotes find for possible quotes inside the input string and adds more,
// also checks if quotes are needed in the front and in the back.
void func_add_quotes(string &src) {

	// Process data
	// 1. If there are any pre-existing double-quote characters in the field, 
	//    then each of those should be replaced by TWO double-quote characters.
	// 2. Any field that contains one or more commas or double quote characters must be 
	//    enclosed in double quotes.
	// Example:
	//  quote at "end"      -->    "quote at ""end"""

	if (src.empty())
	{
		return;
	}

	// checks if front and end quotes are needed
	bool insert_front_end = false;

	// using CSV_SEPARATOR character since we are looking for a  comma too
	size_t found_c = src.find(CSV_SEPARATOR);

	// looks for comma
	if (found_c != std::string::npos)
	{
		insert_front_end = true;
	}

	// looks for double quotes
	size_t found = src.find('"');

	while (found < src.length() && found != std::string::npos)
	{
		if (found != 0)
		{
			insert_front_end = true;
		}

		// create insert code
		src.insert(found, 1, '"');
		found++;

		// find again until the end of the string
		found = src.find('"', found + 1);
	}

	// insert code at the beginning and at the end
	if (insert_front_end)
	{
		src.insert(0, 1, '"');
		src.append("\"", 1);
	}

}

//  Output (to the screen) a short description of each interactive command
//  supported by the program.
void outputHelpMessage()
{
	// Help text.
	cout << "Supported commands: \n"
		<< "    CI      Close input file.\n"
		<< "    CO      Close output file.\n"
		// << " d       set delimiter.\n"
		<< "    h       print this help text.\n"
		<< "    i       open file for input\n"
		<< "    o       open file for output\n"
		<< "    p       (lower case 'p') process data file.\n"
		<< "    q       quit (end the program).\n"
		<< endl;

}

// processDataFile takes the input file and output file to read and write
void processDataFile(ifstream& infile, ofstream& outfile) {
	int lines_read = 0;

	//============= Processing Input
	string buffer;
	while (getline(infile, buffer)) {

		cout << "Input data = " << buffer << endl;

		int len = buffer.length();
		lines_read++;
		string save_buffer = "";
		string data_str = "";

		for (int i = 0, j = 0; i < len; i++) {

			//(i + 1 == buffer.length()) --> this checks if it is the last char in the string
			if (buffer[i] == DEFAULT_DELIMITER || (i + 1 == len)) {

				// this reads from a saved poisition of a last good char until pipe is found.
				// when pipe is found, we read from that saved position until the position
				// where pipe was found MINUS 1.

				// this tells how many characters to read.
				// i: is the position of where pipe is found
				// j: is the saved poition
				int limit = i-j;

				// we read an amount of chars less than the limit number and save them into 
				// the string save_buffer
				for (int k = 0; k < limit; k++) {
					save_buffer += buffer[i];
					i++;
				}

				// save the string to our array of string to process later
				func_add_quotes(save_buffer);
				data_str += save_buffer + ",";

				// cleans buffer for next string to be saved
				save_buffer = "";

				// after we finish processing the last string to be saved
				// we need to update j to a position i plus one
				// so that we can read the rest of coming strings
				j = i + 1;
			}
		}

		// write data_str to external file here
		outfile << data_str + "\n";
	}

	cout << "End of file encountered." << endl;
	
}

// quitProgram exits the program
void quitProgram(int exitStatus)
{
	cout << "Exiting program with status = " << exitStatus << endl;
	system("pause");
	exit(exitStatus);
}

