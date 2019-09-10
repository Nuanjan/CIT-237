#include<iostream>
#include"ProductionWorker.h"

void ProductionWorker::setShift(int s) {
	shift = s;
}

void ProductionWorker::setPayRate(double r) {
	payRate = r;
}


int ProductionWorker::getShiftNumber() const
{
	return shift;
}


double ProductionWorker::getPayRate()const
{
	return payRate;
}

void ProductionWorker::setShiftName(string s) {
	sfitName = s;

}
string ProductionWorker::getShiftName()const
{
	return sfitName;
	}
	
void ProductionWorker::setName(string n) {
	setEmployeeName(n);
}
void ProductionWorker::setDate(string d) {
	setHireDate(d);
}

string ProductionWorker::getPWName()const {
	return getEmployeeName();
}

string ProductionWorker::getDate()const {
	return getHireDate();
}


void ProductionWorker::displayInfo( ProductionWorker  *e)
{
	 
	cout << "Name: " << e->getEmployeeName() << endl;
	cout << "Employee number: " << e->getEmployeeNumber()<< endl;
	cout << "Hire date: " << e->getHireDate() << endl;
	cout << "Shift: " << e->getShiftName() << endl;
	cout << "Shift number: " << e->getShiftNumber() << endl;
	cout << "Pay Rate: " << e->getPayRate() << endl;

} 