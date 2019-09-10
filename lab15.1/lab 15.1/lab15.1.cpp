#include<iostream>
#include<string>
#include"ProductionWorker.h"
#include "Employee.h"




using namespace std;
char command;   //prompt the user to put the command
string emName; //hold employee name
string emDate;  //hold the hire date
int emShift;    //hold shift number
double emRate;  //hold employee hour




int main()
{
	ProductionWorker *inf=NULL;
	while (true) {
		
		

		cout << "Enter command (or 'h' for help): ";
		cin >> command;

		if (command == 'h' || command == 'H') {
			cout << "Supported commands: " << endl;
			cout << "        c             create a new ProductionWorker object." << endl;
			cout << "        h             print help text." << endl;
			cout << "        p             print ProductionWorker information." << endl;
			cout << "        q             quit (end the program) ." << endl;
		}

		else if (command == 'c' || command == 'C') {
			inf = new ProductionWorker();
			cout << "Enter name of new employee: ";
			cin.ignore();
			getline(cin, emName);
			inf->setEmployeeName(emName);
			cout << "Enter hire date of new employee: ";
			cin.ignore();
			getline(cin, emDate);
			inf->setDate(emDate);
			cout << "Enter shift for new employee (1=day, 2=night): ";
			cin >> emShift;
			if (emShift == 1)
				inf->setShiftName("day");
			else if (emShift == 2)
				inf->setShiftName("night");
			else
			{
				inf->setShiftName("error");
			}
			inf->setShift(emShift);
			cout << "Enter hourly pay rate for new employee: ";
			cin >> emRate;
			inf->setPayRate(emRate);
			
			
		}
		else if (command == 'p' || command == 'P') {
			inf->displayInfo(inf);
			
		}
		else if (command == 'q' || command == 'Q') {
			break;
		}
		else
			cout << "unvalid command" << endl;
	} //while

	system("pause");
	return 0;
}

