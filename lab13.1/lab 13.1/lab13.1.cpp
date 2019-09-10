#include <iostream>
#include <iomanip>
#include "Mortgage.h"

using namespace std;

void getUserInfo(Mortgage &);
void displayLoanInfo(Mortgage &);

// program entry point
int main() {

	char input = 'y';
	while (input == 'Y' || input == 'y')
	{
		Mortgage mymortgage;                    // default constructor

		getUserInfo(mymortgage);
		mymortgage.term();
		displayLoanInfo(mymortgage);

		cout << endl;
		cout << "Do you wish to process another loan? ";
		cin >> input;
		cout << endl;
	}


	return 0;
}

void displayLoanInfo(Mortgage &mymortgage)
{
	cout << fixed << showpoint;             

	cout << endl;
	cout << setprecision(2);
	cout << "Loan Amount: $" << mymortgage.getLoanAmount() << endl;

	cout << setprecision(5);
	cout << "Annual Interest Rate: " << mymortgage.getAnnualInterestRate() << endl;

	cout << setprecision(0);
	cout << "Years to repay: " << mymortgage.getNumberOfYears() << endl;

	cout << setprecision(2);
	cout << "Monthly Payment: $" << mymortgage.getMonthlyPayment() << endl;

	cout << "Total Pay Back: $" << mymortgage.getTotalPayback() << endl;
}

void getUserInfo(Mortgage &mymortgage)
{
	// Get user info
	double temp_loan;
	cout << "Enter the amount of the loan: ";
	cin >> temp_loan;
	cout << endl;
	// save value
	mymortgage.setLoanAmount(temp_loan);

	double temp_interest;
	cout << "Enter the annual interest rate in decimal form (example .075): ";
	cin >> temp_interest;
	cout << endl;
	// save value
	mymortgage.setAnnualInterestRate(temp_interest);

	int yearsToRepay;
	cout << "Enter the length of the loan in years: ";
	cin >> yearsToRepay;
	cout << endl;
	// save value
	mymortgage.setYearsToRepay(yearsToRepay);
}