#include <iostream>

/*Exercise: Reorder code from previously jumbled code snippets*/

using namespace std;

void timeOnJob(int arvHr, int arvMin, bool arvIsAM,int depHr, int depMin, bool depIsAM);

int main(){
		
	string employeeName;
	int arrivalHr;
	int arrivalMin;
	bool arrivalAM;	
	int departureHr;
	int departureMin;
	bool departureAM;
	
	char response;
	char discard;
	char isAM;
	
	cout << "Enter employee's name: ";
	getline(cin, employeeName);	
	
	cout << "This program calculates the total time spent by an employee on the job." << endl;
	cout << "To run the program, enter (y/Y): ";
	cin >> response;
	cout << endl;



	while (response == 'y' || response == 'Y')
	{
		cout << endl;
		cout << "Enter arrival hour: ";
		cin >> arrivalHr;
		cout << endl;
		cout << "Enter arrival minute: ";
		cin >> arrivalMin;
		cout << endl;
		cout << "Enter (y/Y) if arrival is before 12:00PM: ";
		cin >> isAM;
		cout << endl;
		if (isAM == 'y' || isAM == 'Y')
			arrivalAM = true;
		else
			arrivalAM = false;
			
		cout << "Enter departure hour: ";
		cin >> departureHr;
		cout << endl;
		cout << "Enter departure minute: ";
		cin >> departureMin;
		cout << endl;
		cout << "Enter (y/Y) if departure is before 12:00PM: ";
		cin >> isAM;
		cout << endl;
		if (isAM == 'y' || isAM == 'Y')
			departureAM = true;
		else
			departureAM = false;
		cout << employeeName << endl;

		timeOnJob(arrivalHr, arrivalMin, arrivalAM, departureHr, departureMin, departureAM);
		cout << "Run program again (y/Y): ";
		cin >> response;
		cout << endl;	
	}
	
	return 0;
}

void timeOnJob(int arvHr, int arvMin, bool arvIsAM, int depHr, int depMin, bool depIsAM)
{
	int arvTimeInMin;
	int depTimeInMin;
	int timeOnJobInMin;
	arvTimeInMin = arvHr * 60 + arvMin;
	depTimeInMin = depHr * 60 + depMin;	
	
	if (arvIsAM == true && depIsAM == false){
		timeOnJobInMin = (720 - arvTimeInMin) + depTimeInMin;
		cout << "Time spent on job: "
		<< timeOnJobInMin / 60 << " hour(s) and "
		<< timeOnJobInMin % 60 << " minutes." << endl;
	}
	else if ((arvIsAM == true && depIsAM == true)|| (arvIsAM == false && depIsAM == false)){		
		if (arvTimeInMin <= depTimeInMin){	
			cout << endl;	
			timeOnJobInMin = depTimeInMin - arvTimeInMin;
			cout << "Time spent on job: " << timeOnJobInMin / 60 << " hour(s) and "<< timeOnJobInMin % 60 << " minutes." << endl;
		}		
		else
			cout << "Invalid input." << endl;	
	}	 	
	else{
		cout << "Invalid input." << endl;		
	}
	
}
