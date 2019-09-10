//Include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
//Define main
int main()
{
	//Declare variable
	string STRING;
	//Declare variable
	string inptflnam;
	//Declare file stream variable
	ifstream infile;
	//Declare variable
	char comm;
	//Do
	do
	{
		//Display message
		std::cout << "p   - convert Pipe-delimited file to CSV." << endl;
		//Display message
		std::cout << "h   - print help text." << endl;
		//Display message
		std::cout << "q   - quit (end the program)." << endl;
		//Display message
		std::cout << "Enter command" << endl;
		//Store command
		std::cin >> comm;
		//If command is p
		if (comm == 'p')
		{
			//Display message
			std::cout << "enter input filename";
			//Store value
			std::cin >> inptflnam;
			//Open file
			infile.open(inptflnam,ios::in);
			//Declare variable
			int a = 0;
			//Declare array
			string inputRecord[50];
			//Declare variable
			int li = 0;

			//Loop
			while (!infile.eof())
			{
				//Get string
				getline(infile, STRING);
				//Push string
				std::istringstream ss(STRING);
				//Declare variable
				std::string token;

				
			}
			//Compute size
			int sz = sizeof(inputRecord) / sizeof(*inputRecord);
			//Declare variable
			string outfilnam;
			//Declare variable
			ofstream outfill;
			//Display message
			std::cout << "Output file name";
			//Store file name
			std::cin >> outfilnam;
			//Open file
			outfill.open(outfilnam);
			//Loop
			for (int li = 0; li<sz; li++)
			{
				//Store value
				string strex = inputRecord[li];
				//Declare variable
				int jj = 0;
				//Declare variable
				int flag = 0;
				//If string has comma
				if (strchr(inputRecord[li].c_str(), ','))
				{
					//Set value
					flag = 1;
				}
				//If flag is 0
				if (flag == 0)
				{
					//Fill array
					outfill << inputRecord[li];
					//Append comma
					outfill << ",";
				}
				//Otherwise
				else
				{
					//Fill symbol
					outfill << " \" ";
					//Fill value
					outfill << inputRecord[li];
					//Fill symbol
					outfill << " \" ";
					//Fill symbol
					outfill << ",";
				}
			}
			//Close file
			outfill.close();
			//Close file
			infile.close();
			//Display message
			cout << "Output is written to file" << endl;
		}
		//If command is h
		else if (comm == 'h')
		{
			//Display message
			cout << "This program converts pipe delimited text file into csv file" << endl;
			//Display message
			cout << "Store pipe delimted file in same folder as code " << endl;
			//Display message
			cout << "Provide name for output file " << endl;
			//Display message
			cout << "Press 'p' command to convert " << endl;
			//Display message
			cout << "Check output file in same folder as code" << endl;
			//Display message
			cout << "Press 'h' command for help" << endl;
			//Display message
			cout << "Press 'q' command to quit from program" << endl;

			//New line
			cout << endl;
		}
		//If command is q
		else if (comm == 'q')
		{
			//Pause console window
			system("pause");
			//Exit
			exit(0);
		}
		//Otherwise
		else
		{
			//Display message
			cout << "Wrong command";
			//Pause console window
			system("pause");
			//Return
			return 0;
		}
	}

	//Loop until command is to quit
	while (comm != 'q');
	//Pause console window
	system("pause");
	//Return
	return 0;
}

