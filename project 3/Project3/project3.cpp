#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "InventoryItem.h"

using namespace std;

//====== Global variables======//
//track of inventory number
int invCount = 0;

//====== Function Prototypes======//
int readFromFile(string, InventoryItem[]);
void displayMenu(InventoryItem[]);
void addParts(InventoryItem[]);
void removeParts(InventoryItem[]);
void inputInventory(InventoryItem[]);
void newInventory(InventoryItem[]);
void outputInventory(InventoryItem[]);
void printInventory(InventoryItem[]);
void printHelp();
void quit();


int main()
{
	InventoryItem inventory[100];

	displayMenu(inventory);

	return 0;
}

void displayMenu(InventoryItem inv[])
{
	char inputCmd = 0;
	for (;;)
	{
		cout << "Command: ";
		cin >> inputCmd;
		// cout << endl;

		switch (inputCmd)
		{
		case 'a':
			addParts(inv);
			break;
		case 'h':
			printHelp();
			break;
		case 'i':
			inputInventory(inv);
			break;
		case 'p':
			printInventory(inv);
			break;
		case 'n':
			newInventory(inv);
			break;
		case 'o':
			outputInventory(inv);
			break;
		case 'q':
			quit();
			break;
		case 'r':
			removeParts(inv);
			break;
		default:
			break;
		}

	}
	system("pause");
}

int readFromFile(string filename, InventoryItem inventory[])
{
	ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		return -1;
	}

	string buffer;
	int counter = 0;
	int arrayIndexer = invCount;
	int invAdded = 0;

	while (getline(inputFile, buffer, '|'))
	{
		if (counter == 1)
		{
			inventory[arrayIndexer].setDescription(buffer);
		}
		else if (counter == 2)
		{
			inventory[arrayIndexer].setCost(atof(buffer.c_str()));
		}
		else if (counter == 3)
		{
			inventory[arrayIndexer].setUnits(atoi(buffer.c_str()));
		}

		// reset at the end of the line preparing for next one
		if (counter == 3)
		{
			invCount++;
			arrayIndexer++;
			counter = 0;
			invAdded++;
		}

		counter++;
	}

	inputFile.close();

	return invAdded;
}

void addParts(InventoryItem inv[])
{
	int itemNumber = -1;
	cout << endl;
	cout << "Choose a Item Number: ";
	cin >> itemNumber;

	// check the range
	if (itemNumber >= 0 && itemNumber < invCount)
	{
		int numToAdd = 0;
		cout << "How many parts to add? ";
		cin >> numToAdd;

		// ignore values less than zero
		if (numToAdd > 0)
		{
			int units = inv[itemNumber].getUnits();
			inv[itemNumber].setUnits(units + numToAdd);
		}
	}

}

void removeParts(InventoryItem inv[])
{
	int itemNumber;
	int numToRemove;

	cout << "Choose a Item Number: ";
	cin >> itemNumber;

	if (itemNumber >= 0 && itemNumber < invCount)
	{
		cout << "How many parts to remove? ";
		cin >> numToRemove;

		// calculate removal
		int remainder = inv[itemNumber].getUnits() - numToRemove;
		if (remainder < 0)
		{
			cout << "Error:  You are attempting to remove more "
				<< "parts than the Item currently holds." << endl;
		}
		else
		{
			inv[itemNumber].setUnits(remainder);
		}
	}
}

void inputInventory(InventoryItem inv[])
{
	string filename;
	cout << "Enter name of input file: ";
	cin >> filename;

	int count = readFromFile(filename, inv);
	if (count == -1)
	{
		cout << "Error opening file" << endl;
		return;
	}
	else
	{
		cout << count << " records loaded to array." << endl;
	}
}

void newInventory(InventoryItem inv[])
{
	string des;
	float cost;
	int qty;

	cout << "Enter description for new Item: ";
	cin.ignore();
	getline(cin, des);
	cout << "Enter unit cost for new Item: ";
	cin >> cost;
	int condition = 0;
	while (condition == 0) {

		cout << "Enter initial quantity for the new Item: ";
		cin >> qty;
		if (qty >= 0 && qty <= 30)
		{
			condition = 1;
		}
	else {
		cout << "ERROR: initial quantity must be >=zero and <=30." << endl;

	}
	}
	// store into index
	inv[invCount].setDescription(des);
	inv[invCount].setCost(cost);
	inv[invCount].setUnits(qty);
	// update inventory count
	invCount++;


	cout << "Announcing a new inventory Item: " << des << endl;
	cout << "We now have " << invCount << " different inventory Items in stock!" << endl;
}

void outputInventory(InventoryItem inv[])
{

	string filename;
	cout << "Enter name of output file: ";
	cin >> filename;

	ofstream outFile(filename);
	if (!outFile.is_open())
	{
		cout << "Error opening file" << endl;
	}

	for (int i = 0; i < invCount; i++)
	{
		outFile << i << "|" << inv[i].getDescription() << "|"
			<< inv[i].getCost() << "|" << inv[i].getUnits() << endl;
	}

	outFile.close();

	cout << invCount << " records written to file." << endl;
}

void printInventory(InventoryItem inv[])
{
	// print header
	cout << left << setw(14) << "Item Num";
	cout << setw(44) << "Description";
	cout << setw(16) << "Cost";
	cout << setw(14) << "Quantity" << endl;
	cout << setw(14) << "--------";
	cout << setw(44) << "-----------";
	cout << setw(16) << "----";
	cout << setw(14) << "--------" << endl;
	// print inventory
	for (int i = 0; i < invCount; i++)
	{
		cout << left;
		cout << setw(14) << i;
		cout << setw(40) << left << inv[i].getDescription();
		cout << fixed << showpoint;
		cout << right;
		cout << setprecision(2);
		cout << setw(8) << inv[i].getCost();
		cout << setprecision(0);
		cout << setw(17) << inv[i].getUnits() << endl;
	}

	cout << invCount << " records." << endl;
}

void printHelp()
{
	cout << "Supported commands:" << endl;
	cout << "\t\t\ta\t\t\tAdd parts." << endl;
	cout << "\t\t\th\t\t\tprint Help text." << endl;
	cout << "\t\t\ti\t\t\tInput inventory data from a file." << endl;
	cout << "\t\t\tp\t\t\tPrint inventory list." << endl;
	cout << "\t\t\tn\t\t\tNew inventory Item." << endl;
	cout << "\t\t\to\t\t\tOutput inventory data to a file." << endl;
	cout << "\t\t\tq\t\t\tquit (end of the program)." << endl;
	cout << "\t\t\tr\t\t\tRemove parts." << endl;

}

void quit()
{
	cout << "Exit." << endl;
	exit(0);
}