#include<iostream>
#include<iomanip>

using namespace std;
//grobal variable
int delta = 5;
int previousSpeed;
int currentSpeed;
double time_interval =0;
double total_feet_interval;
double totalSpeed = 0;

void intervalFeetTraveled(double previousSpeed) {
	int timeInterval = 1;
	double averageSpeed = (previousSpeed + currentSpeed) / 2;
	double averageSpeed_feetPerSecs = averageSpeed * 5280.0 / 3600.0;
	double intervalSpeedFeetTraveled = averageSpeed_feetPerSecs * timeInterval;
	time_interval = intervalSpeedFeetTraveled;
	
	cout << fixed << setprecision(1) << setw(6) << time_interval << "          ";
		
	
}
void totalFeetTraveled(double previousSpeed) {
	int timeInterval = 1;

	double averageSpeed = (previousSpeed + currentSpeed) / 2;
	double averageSpeed_feetPerSecs = averageSpeed * 5280.0 / 3600.0;
	double intervalSpeedFeetTraveled = averageSpeed_feetPerSecs * timeInterval;
	double totalMiles;
	total_feet_interval += intervalSpeedFeetTraveled;
	
	totalMiles = total_feet_interval * 0.0001893939;
	cout<< total_feet_interval << "(" << fixed << setprecision(4)
		<< setw(6) << totalMiles << ")" << endl;
}


//function accelarate
void accelerate() {

	int previousSpeed;
	previousSpeed = currentSpeed;
	currentSpeed += delta;
	
	cout << "Accelerate    " << setw(6) << "Accelerating    " << setw(6) << currentSpeed<<"           ";
}

void brake() {

	int previousSpeed;
	previousSpeed = currentSpeed;
	currentSpeed = currentSpeed - delta;
	if (currentSpeed >0)
		cout << "Brake          " << setw(6) << "Braking        " << setw(6) << currentSpeed << "           ";
	else

		cout << "Brake          " << setw(6) << "Stopped        " << setw(6) << "0" << "           ";
}


void cruise() {
	int previousSpeed;
	previousSpeed = currentSpeed;
	if (previousSpeed <0)
		cout << "Cruise         " << setw(6) << "stopped        " << setw(6) << "0"<< "           ";
	else
		cout << "Cruise         " << setw(6) << "Cruising       " << setw(6) << previousSpeed << "           ";

}
void demo() {


}



void help() {
	cout << "Supported commands:" << endl;
	cout << "                  a               accelerate." << endl;
	cout << "                  b               brake." << endl;
	cout << "                  c               cruise." << endl;
	cout << "                  d               demo." << endl;
	cout << "                  h               print this help text." << endl;
	cout << "                  q               quit(end the program)" << endl;
}

int main() {
	char commands;
	
	cout << "Function  " << setw(6) << "Current State  " << setw(6)
		<< "Current Speed  " << setw(6) << "Interval Distance  " << setw(6)
		<< "Total Feet(and miles) traveled" << endl;
	cout << "put any command or h for help" << endl;
	while (cin >> commands && commands != 'q') {
		switch (commands) {
		case'A':;
		case'a':cout << "command: a" << endl;
			accelerate();
			intervalFeetTraveled(previousSpeed);
		totalFeetTraveled(previousSpeed);
			break;
		case 'B':;
		case 'b':cout << "command: b" << endl;
			brake();
			intervalFeetTraveled(previousSpeed);
			totalFeetTraveled(previousSpeed);
			break;
		case'C':;
		case 'c':cout << "command: c" << endl;
			cruise();
			intervalFeetTraveled(previousSpeed);
			totalFeetTraveled(previousSpeed);
			break;
		case 'H':;
		case 'h': cout << "command: h" << endl;
			help();
			break;


		default: cout << "You did not put the right command" << endl;
		}
	}
	system("pause");
	return 0;
}