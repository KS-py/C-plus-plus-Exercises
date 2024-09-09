#include <iostream>
#include <iomanip>

using namespace std;

const double RES_BILL_PROC_FEES = 4.50;
const double RES_BASIC_SERV_COST = 20.50;
const double RES_COST_PREMIUM = 7.5;

const double BUS_BILL_PROC_FEES = 15.00;
const double BUS_BASIC_SERV_COST = 75.00;
const double BUS_BASIC_CONN_COST = 15.00;
const double BUS_COST_PREM = 50.00;

double residential();
double business();

int main() {	
	cout << fixed << showpoint;
	cout << setprecision(4);


	double amount;
	int accNo;
	char customerType;
	cout << "What is your account number: ";
	cin >> accNo;

	cusType:
	cout << "What type of customer, Residential (R) or Business (B): ";
	cin >> customerType;

	switch(customerType) {
		case 'r':
		case 'R':
			amount = residential();
			cout << "Account NO: " << accNo << endl;
			cout << "Amount due: " << amount << endl;
			break;

		case 'b':
		case 'B':
			amount = business();
			cout << "Account NO: " << accNo << endl;
			cout << "Amount due: " << amount << endl;
			break;			
		default:
			cout << "The options are R (r) or B (b), Residential or Business" << endl;
			goto cusType;
	}

}

double residential() {
	int numPrem;
	double bill;

	cout << "What are the number of your premium channels: ";
	cin >> numPrem;

	bill = RES_BILL_PROC_FEES + RES_BASIC_SERV_COST + (numPrem * RES_COST_PREMIUM);

	return bill;
}

double business() {
	int numPrem;
	int noServiceConnections;
	double bill;
	
	cout << "What is the number of premium channels used from our service: ";
	cin >> numPrem;
	cout << endl;
	cout << "What is the number of service connections you have to our service: ";
	cin >> noServiceConnections;
	cout << endl;

	if(noServiceConnections <= 10) {
		bill = BUS_BILL_PROC_FEES + BUS_BASIC_CONN_COST + (numPrem * BUS_COST_PREM);
	} else {
		bill = BUS_BILL_PROC_FEES + BUS_BASIC_CONN_COST + ((noServiceConnections - 10) * BUS_BASIC_SERV_COST) + (numPrem * BUS_COST_PREM);		
	}

	return bill;

}
