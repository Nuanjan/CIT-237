#include <math.h>
#include "Mortgage.h"

Mortgage::Mortgage()
{
	annualInterestRate = 0.0475;
}

double Mortgage::getLoanAmount()
{
	return loanAmount;
}

double Mortgage::getAnnualInterestRate()
{
	return annualInterestRate;
}

int Mortgage::getNumberOfYears()
{
	return numberOfYears;
}

double Mortgage::getMonthlyPayment()
{
	return monthlyPayment;
}

double Mortgage::getTotalPayback()
{
	return totalPayment;
}

void Mortgage::setLoanAmount(double new_loan_amount)
{
	loanAmount = new_loan_amount;
}

void Mortgage::setAnnualInterestRate(double new_annual_interest)
{
	annualInterestRate = new_annual_interest;
}

void Mortgage::setYearsToRepay(int new_years_to_repay)
{
	numberOfYears = new_years_to_repay;
}

void Mortgage::term()
{

	numberOfPayments = numberOfYears * 12;
	monthlyInterestRate = annualInterestRate / 12;

	// calculate term
	paymentTerm = pow((1 + monthlyInterestRate), numberOfPayments);

	// monthly payment
	monthlyPayment = (loanAmount * monthlyInterestRate * paymentTerm) /
		(paymentTerm - 1);

	// total payment
	totalPayment = monthlyPayment * numberOfPayments;

}