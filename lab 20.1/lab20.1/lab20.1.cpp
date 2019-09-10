#include<iostream>
#include<iomanip>
using std::cout;    //    program uses cout
using std::cin;    //    program uses cin
#include "IntList.h"
				   //    driver program to demonstrate the class IntList
using namespace std; 


int main()
{
	//    declare a variable of type linked list
	IntList myList;
	
	

	
	//    declare other variables
	char choice;
	int n;

	do {

		//    prompt and read the user's choice 
		cout << "Enter command (or 'h' for help : ";
		cin >> choice;
		//    do appropriate action basing on choice selected
		switch (choice)
		{
		case 'A':
		case 'a'://    prompt and read an integer
			cout << "Enter number to append to the list: ";
			cin >> n;
			//    append the number into list   
			myList.appendNode(n);
			break;
		case 'I':
		case 'i':    //    prompt and read an integer
			cout << "Enter number to insert into the list: ";
			cin >> n;
			//    insert the number into list   
			myList.insertNode(n);
			break;

		case 'D':
		case 'd':
			//    prompt and read an integer
			cout << "Enter number to delete from the list:  ";
			cin >> n;
			//    delete the number from list   
			myList.deleteNode(n);
			break;
		case 'p':
		case'P':

			myList.print();

			break;
		case 'b':
		case 'B':
			cout << "BACKWARDS recursive print of list";
			//myList.displayBackward(myList);
			break;
		case 'C':
		case'c':

			
			cout << "Number of node in list, head=";
			//myList.print();

			//cout<<"count="<<myList.countNumber();
			//cout << endl;
			break;
		case 't':
		case 'T':
			cout << "Total of all value fields in list,"; // << myList.totalValue();
			break;
		case 'R':
		case 'r':
			myList.displayRecursive(myList.getHead());
		
			break;
		

		case 'Q':
		case 'q':
			choice = 'q';
		}    //    end switch
	} while (choice != 'q');    //    end do-while
	system("pause");
	return 0;
}            // end of function, main

