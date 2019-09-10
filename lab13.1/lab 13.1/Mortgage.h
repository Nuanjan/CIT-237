

class Mortgage
{
private:
	// data variables
	double loanAmount;
	double annualInterestRate;
	double monthlyInterestRate;
	double paymentTerm;
	double monthlyPayment;
	double totalPayment;

	int numberOfYears;
	int numberOfPayments;

	//return (loan * interest_rate) / (1 - pow(1 + interest_rate, -loan_term));
	void calculateTerm();

public:
	// constructors
	Mortgage();       // default constructors
	Mortgage(double); // another constructors

					  // getters  --> obtain the values from the data variables
	double getLoanAmount();
	double getAnnualInterestRate();
	int getNumberOfYears();
	double getMonthlyPayment();
	double getTotalPayback();

	// setters  --> set new values to data variables
	void setLoanAmount(double new_loan_amount);
	void setAnnualInterestRate(double new_annual_interest);
	void setYearsToRepay(int new_years_to_repay);

	// processing
	void term();
};
